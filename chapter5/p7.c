#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc,char *argv[]){
  int fd = open("./p7.txt", O_CREAT | O_WRONLY | O_TRUNC);
  int rc = fork();

  if(rc < 0){
    fprintf(stderr,"fork() failed!\n");
  }else if (rc == 0){
    char *str = "1.this sentence is wrote by child.\n";
    write(fd,str,strlen(str));
  }else{
    wait(NULL);
    char *str = "2.this sentence is wrote by parent.\n";
    write(fd,str,strlen(str));
  }
  return 0;
}