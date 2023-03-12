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
    // execl("/bin/ls","ls",NULL);
    // char *env[] = { "HOME=/home/user", "LOGNAME=user", NULL };
    // execle("/bin/ls","ls",NULL,env);
    // execlp("ls","ls",NULL);
    // char *args[] = {"/bin/ls","-l",NULL};
    // execv(args[0],args);
    // char *args[] = {"ls","-l",NULL};
    // execvp("ls",args);
  }else{
    wait(NULL);
    printf("process of parent.\n");
  }
  return 0;
}