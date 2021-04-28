#include<iostream>
#include<vector>
#include<memory>

#include<sys/socket.h>
#include<sys/epoll.h>
#include<netinet/in.h>
using namespace std;

const int MAXLINE   = 500;
const int PORT      = 37501;
const int MAXEPOLL  = 255;
const int MAXEVENTS = 20;

int main() {
    char line[MAXLINE];

    struct sockaddr_in servaddr;
    bzero( &servaddr, sizeof( servaddr ) );
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);
	
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0) {
        cout << " socket error" << endl;
        exit(1);
    }

    //把socket设置为阻塞方式
    etnonblocking(listenfd);

    if(bind(listenfd, (sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        cout << "bind error" << endl;
        exit(1);
    }

    if(listen(listenfd, 20)）< 0) {
        cout << "listen error" << endl;
        exit(1);
    }


    struct epoll_event ev, events[20];
    ev.data.fd = listenfd;
    ev.events = EPOLLIN | EPOLLET;

    int epfd = epoll_create(MAXEPOLL);
    if(epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev) < 0){
        cout << "epoll_ctl error" << endl;
        exit(1);
    }


    struct sockaddr_in clientaddr, serveraddr;

    int cur_fds = 0;
    while(1) {
        int nfds = epoll_wait(epfd, events, MAXEVENTS, 500);
        for(int i = 0; i < nfds; ++i) {
            if(events[i].data.fd == listenfd) {//如果是主socket的事件，则表示有新的连接, 需要加入epoll_ctl
                socklen_t clien;
                int connfd = accept(listenfd, (sockaddr*)&clentaddr, &clien);
                if(connfd < 0) {
                    perror("connfd < 0");
                    exit(1);
                }

                char *str = inet_ntoa(clientaddr.sin_port);
                cout << "accept a connection from " << str << endl;
                
                ev.data.fd = connfd;
                ev.events = EPOLLIN | EPOLLET;
                if(epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &ev)) < 0 {
                    cout << "epoll_ctl error" << endl;
                    exit(1);
                }
            } else if(events[i].events & EPOLLIN) { //已经连接的用户，收到数据，读入
                cout << "EPOLLIN" << endl;
                int sockfd = events[i].data.fd;
                if(sockfd < 0) {
                    continue;
                }

                int n = read(sockfd, line, sizeof(line));
                if(n < 0) {
                    cout << "read error" << endl;
                    exit(1);
                } else if(0 == n) {
                    // 如果设为非阻塞模式，当为0是表示socket已关闭，需要删除
                    // cout << "socket already closed" << endl;
                    // close(sockfd);
                    // epoll_ctl(epfd, EPOLL_CTL_DEL, sockfd, &events[i]);
                }

                line[line] = '\0';
                cout << "read " << line << endl;

                struct epoll_event event = events[i];
                event.events = EPOLLOUT | EPOLLET;
                epoll_ctl(epfd, EPOLL_CTL_MOD, sockfd, &event);
            } else if(events[i].events & EPOLLOUT){
                cout << "EPOLLOUT" << endl;
                int sockfd = events[i].data.fd;
                write(sockfd, line, MAXLINE);

                struct epoll_event event;
                event.data.fd = sockfd;
                event.events = EPOLLIN | EPOLLET;
                epoll_ctl(epfd, EPOLL_CTL_MOD, sockfd, &event);
            }
        }
    }

    

    return 0;
}