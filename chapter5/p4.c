#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

// 将exec执行程序获得的内容信息重定向到newfile.txt中
int main(int argc,char *argv[]){
  int rc = fork();
  if(rc < 0){
    fprintf(stderr,"fork failed!\n");
    exit(1);
  }else if(rc == 0){
    close(STDOUT_FILENO); // 关闭默认的文件描述符
    int fd = open("./newfile.txt", O_CREAT | O_WRONLY | O_TRUNC);
    char* myargs[3];
    myargs[0] = strdup("wc");
    myargs[1] = strdup("p3.c");
    myargs[2] = NULL;
    execvp(myargs[0],myargs);
    printf("this shouldn't print out");
  }else{
    int wc = wait(NULL);
  }
  return 0;
}