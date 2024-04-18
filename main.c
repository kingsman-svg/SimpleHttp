#include"Server.h"
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(int argc,char* argv[])
{
    if (argc < 3) {
        printf("./a.out port path\n");
        return -1;
    }
    unsigned short port = atoi(argv[1]);
    //切换服务器的工作路径
    chdir(argv[2]);
    //初始化一个用于监听的套接字
    int lfd = initListenFd(port);

    //基于该套接字启动服务器程序
    //使用epoll
    epollRun(lfd);
    return 0;
    
    //程序启动后，将基于该套接字，一直检测客户端是否有新连接
    //如果有新连接，建立连接
    //连接建立成功后，会得到一个用于通信的文件描述符
    //使用该文件描述符，与客户端进行通信

}