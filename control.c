#include "semunion.h"

int main(int argc, char *argv[]){
  //printf("%d\n", argc);
  //printf("%s\n", argv[1]);

  if(argc == 1){
    printf("Choose an action:\nCreate: -c\nRemove: -r\nView: -v\n");
  }else{
    int semkey = ftok("makefile", 22);
    int sc;
    int semid;
    int shmkey = ftok("makefile", 23);
    int shmid;
    int fd;
    int fsize;
 
    if(strcmp(argv[1], "-c") == 0){
      //printf("-c\n");
      semid = semget(semkey, 1, IPC_CREAT | 0644);

      shmid = shmget(shmkey, fsize, IPC_CREAT | 0644);

      fd = open("semaphone.ring", O_CREAT | O_TRUNC | 0644);
      fsize = lseek(fd, 0, SEEK_END);
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

      semctl(semkey, 0, IPC_RMID);

      shmctl(shmkey, IPC_RMID, 0);
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
