#include "semunion.h"

int main(int argc, char *argv[]){
  //printf("%d\n", argc);
  //printf("%s\n", argv[1]);

  if(argc == 1){
    printf("Choose an action:\nCreate: -c\nRemove: -r\nView: -v\n");
  }else{
    int semkey;
    int sc;
    int semid;
    int fd;
    int fsize;
    int shmkey;
    int shmid;
    
    if(strcmp(argv[1], "-c") == 0){
      //printf("-c\n");
      semkey = ftok("makefile", 22);
      sc;
      semid = semget(semkey, 1, IPC_CREAT | 0644);

      fd = open("semaphone.ring", O_CREAT | O_TRUNC | 0644);
      fsize = lseek(fd, 0, SEEK_END);
      //printf("size: %d\n", fsize);
      
      shmkey = ftok("makefile", 23);
      shmid = shmget(shmkey, fsize, IPC_CREAT | 0644);
    }
    
    if(strcmp(argv[1], "-r") == 0){
      //printf("-r\n");
      
    }
    
    if(strcmp(argv[1], "-v") == 0){
      //printf("-v\n");
      
    }
  }
  close(fd);
  return 0;
}
