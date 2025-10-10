// Godoy Manriquez Andrés



/*
Explicación:

Memoria compartida: Se usa shm_open para crear la memoria compartida y mmap para mapearla a la memoria del proceso.

Comunicación: Los procesos (padre e hijo) alternan entre leer y escribir un valor en la memoria compartida. Utilizan la variable turn para determinar quién debe enviar o recibir datos.

Sincronización con señales: El proceso principal (padre) configura una señal (SIGINT) para terminar la comunicación. Cuando se recibe la señal (por ejemplo, al presionar Ctrl+C), la bandera terminate_flag se pone a 1, lo que detiene el ciclo de comunicación.

Condición de terminación: La comunicación entre los procesos se detiene cuando se recibe la señal de interrupción (SIGINT), lo cual cambia el valor de terminate_flag y termina la ejecución de la función de comunicación.
*/





#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

// Estructura para la memoria compartida
struct shared_data {
    int data;              // Datos a compartir
    int turn;              // Determina quien debe hablar (0 - padre, 1 - hijo)
};

// Definir nombre del objeto de memoria compartida
#define SHM_NAME "/shared_mem"

// Variables globales
int *terminate_flag; // bandera de terminación
struct shared_data *shm_ptr; // puntero a la memoria compartida

// Señal de terminación
void handle_termination(int sig) {
    *terminate_flag = 1;
}

// Función que implementa la comunicación entre el padre y el hijo
void communication() {
    while (*terminate_flag == 0) {
        if (shm_ptr->turn == 0) {
            // El padre está esperando para hablar
            printf("Padre: Enviando dato %d\n", shm_ptr->data);
            shm_ptr->data++;      // El padre incrementa el valor
            shm_ptr->turn = 1;    // Cambiar turno al hijo
        } else if (shm_ptr->turn == 1) {
            // El hijo está esperando para hablar
            printf("Hijo: Recibí dato %d\n", shm_ptr->data);
            shm_ptr->data++;      // El hijo incrementa el valor
            shm_ptr->turn = 0;    // Cambiar turno al padre
        }
        usleep(1000000);  // Pausa de 1 segundo
    }
    printf("Comunicación terminada.\n");
}

int main() {
    // Crear memoria compartida
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(1);
    }

    // Ajustar tamaño de la memoria compartida
    if (ftruncate(shm_fd, sizeof(struct shared_data)) == -1) {
        perror("ftruncate");
        exit(1);
    }

    // Mapear la memoria compartida
    shm_ptr = (struct shared_data *)mmap(NULL, sizeof(struct shared_data), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // Inicializar la memoria compartida
    shm_ptr->data = 0;
    shm_ptr->turn = 0;  // Comienza el padre
    terminate_flag = (int *)malloc(sizeof(int)); // Crear bandera de terminación
    *terminate_flag = 0; // Iniciar la bandera como falsa

    // Configurar la señal de terminación (Ctrl+C)
    signal(SIGINT, handle_termination);

    // Crear proceso hijo
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Proceso hijo
        communication();
        exit(0);
    } else {
        // Proceso padre
        communication();
        wait(NULL);  // Esperar a que el hijo termine
    }

    // Liberar memoria compartida
    munmap(shm_ptr, sizeof(struct shared_data));
    shm_unlink(SHM_NAME);
    free(terminate_flag);

    return 0;
}
