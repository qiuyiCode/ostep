#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc,char *argv[]){
  printf("(PID:%d)\n",getpid());
  int rc = fork();
  if(rc < 0){
    fprintf(stderr,"fork() failed!\n");
  }else if(rc == 0){
    int wr = wait(NULL);
    printf("this is child environment.(PID:%d),wr = (%d)\n",getpid(),wr);
  }else{
    int wr = waitpid(-1,NULL,0);
    printf("parent PID:%d\n",getpid());
    printf("wait return value:(%d)\n",wr);
  }
  return 0;
}