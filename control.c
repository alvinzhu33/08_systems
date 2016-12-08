#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include "semunion.h"

int main(int argc, char *argv[]){
  //printf("%d\n", argc);
  //printf("%s\n", argv[1]);

  if(argc == 1){
    printf("Choose an action:\nCreate: -c\nRemove: -r\nView: -v\n");
  }else{
    int semid;
    int key = ftok("makefile", 22);
    int sc;
    
    if(strcmp(argv[1], "-c") == 0){
      //printf("-c\n");
      int semid = semget(key, 1, IPC_CREAT | 0644);

      if(semid >= 0 ){
	union semun su;
	
      }
    }
    if(strcmp(argv[1], "-r") == 0){
      printf("-r\n");
    }
    if(strcmp(argv[1], "-v") == 0){
      printf("-v\n");
    }
  }
  return 0;
}
