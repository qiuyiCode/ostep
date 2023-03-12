#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc,char *argv[]){
  int x = 100;
  printf("x == %d\n",x);

  int rc = fork();
  if(rc < 0){
    printf("fork() failed!\n");
  }else if(rc == 0){
    printf("rc : %d\n",x);
    x = 5;
    printf("rc in child process : %d\n",x);
  }else{
    int wt = wait(NULL);
    x = -5;
    printf("rc in parent process : %d\n",x);
  }
  return 0;
}