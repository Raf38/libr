#ifndef __LIBR_SOCKET
#define __LIBR_SOCKET

#define SOCK_STREAM 1

// IPv4 AF_INET sockets:
struct in_addr {
    unsigned long s_addr;          // load with inet_pton()
};

struct sockaddr_in {
    short            sin_family;   // e.g. AF_INET, AF_INET6
    unsigned short   sin_port;     // e.g. htons(3490)
    struct in_addr   sin_addr;     // see struct in_addr, below
    char             sin_zero[8];  // zero this if you want to
};

#endif

