#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#define BUFFER_SIZE 25

int main(int argc,char* argv[]){
    int fd[2];
    pid_t pid;

    char write_msg[BUFFER_SIZE] = "Hello, world!";
    char read_msg[BUFFER_SIZE];

    // 创建管道
    if (pipe(fd) == -1) {
        fprintf(stderr, "管道创建失败");
        return 1;
    }

    // 创建子进程
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "进程创建失败");
        return 1;
    } else if (pid == 0) {
        // 子进程从管道中读取数据
        close(fd[1]); // 关闭写入端口
        read(fd[0], read_msg, BUFFER_SIZE);
        printf("子进程读取的消息：%s\n", read_msg);
        close(fd[0]); // 关闭读取端口
    } else {
        // 父进程向管道中写入数据
        close(fd[0]); // 关闭读取端口
        write(fd[1], write_msg, strlen(write_msg) + 1);
        printf("父进程写入的消息：%s\n", write_msg);
        close(fd[1]); // 关闭写入端口
    }

    return 0;
}