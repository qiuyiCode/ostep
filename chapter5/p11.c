#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc,char *argv[]){
  int rc = fork();
  if(rc < 0){
    fprintf(stderr,"fork() failed!\n");
  }else if(rc == 0){
    close(STDOUT_FILENO);
    printf("child close STDOUT_FILENO\n");
  }else{
    printf("parent stdout.\n");
  }
  return 0;
}