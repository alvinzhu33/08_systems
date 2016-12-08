#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include "semunion.h"

void main(){
  int semid;
  int shmid;
  semid = semget(ftok("makefile", 22), 1, 0644);
  shmid = shmget(ftok("makefile", 23), 0, 0644);
}
