#include "semunion.h"

int main(int argc, char *argv[]){
  //printf("%d\n", argc);
  //printf("%s\n", argv[1]);

  if(argc == 1){
    printf("Choose an action:\nCreate: -c\nRemove: -r\nView: -v\n");
  }else{
    int key = ftok("makefile", 22);
    int sc;
    int semid;
    int shmid;
    int fd;
    int fsize;
    int *size;
    union semun su;

    if(strcmp(argv[1], "-c") == 0){
      //printf("-c\n");
      semid = semget(key, 1, IPC_CREAT | 0644);
      su.val = 1;
      semctl(semid, 0, SETVAL, su);

      shmid = shmget(key, 4, IPC_CREAT | 0644);

      fd = open("semaphone.ring", O_CREAT | O_TRUNC | 0644);
      //fsize = lseek(fd, 0, SEEK_END);
      size = (int *) shmat(shmid, 0, 0);
      size = 0;
      //printf("size: %d\n", fsize);
      close(fd);
    }

    if(strcmp(argv[1], "-r") == 0){
      //printf("-r\n");
      fd = open("semaphone.ring", O_RDONLY);
      fsize = lseek(fd, 0, SEEK_END);
      lseek(fd,-1 * fsize, SEEK_CUR);
      char buffer[fsize];
      read(fd, buffer, fsize);
      //printf("size: %d\n", fsize);
      printf("%s\n", buffer);
      close(fd);

      semid = semget(key, 1, 0);
      semctl(key, 0, IPC_RMID);

      shmid = shmget(key, 4, 0);
      shmctl(key, IPC_RMID, 0);
    }

    if(strcmp(argv[1], "-v") == 0){
      //printf("-v\n");
      fd = open("semaphone.ring", O_RDONLY);
      fsize = lseek(fd, 0, SEEK_END);
      lseek(fd,-1 * fsize, SEEK_CUR);
      char buffer[fsize];
      read(fd, buffer, fsize);
      //printf("size: %d\n", fsize);
      printf("%s\n", buffer);
      close(fd);
    }
  }
  return 0;
}
