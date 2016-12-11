#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include "semunion.h"

void main(){
    int key = ftok("makefile", 22);
    int semid = semget(key, 1, 0644);
    int shmid = shmget(key, 4, 0644);
    int fd = open("semaphone.ring", O_RDWR | O_APPEND | 0644);

    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_flg = SEM_UNDO;
    sb.sem_op = -1;
    semop(semid, &sb, 1);

    int *size = (int *)shmat(shmid, 0, 0);
    char text[*size + 1];
    lseek(fd, -(*size), SEEK_END);
    read(fd, text, *size);
    close(fd);
    printf("Last entry: %s\n", text);
}
