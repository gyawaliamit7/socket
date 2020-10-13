#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "soc.h"

int main (int argc , char *argv[])
{
    int err;
    int cSocket;
    struct sockaddr_in sAddr;
    struct sockaddr_in cAddr;
    int cSocLen;

    //create socket
    memset(&cAddr, 0, sizeof(struct sockaddr_in));
    cAddr.sin_family = AF_INET;
    cAddr.sin_port = htons(SERVERPORT);

    //uncomment to use you inet ip address
   // cAddr.sin_addr.s_addr = inet_addr(SERVERIP);
    cAddr.sin_addr.s_addr = INADDR_ANY;


    cSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (cSocket == -1)
    {
        printf("client: socket creation failed");
        exit(1);
    }
    else
    {
        printf("client created successfully \n");
    }
    

    //connect to a server
    err = connect(cSocket , (struct sockaddr *) &cAddr, sizeof(struct sockaddr_in));
    if (err == -1)
    {
        printf("client connection failed");
    }
    else
    {
        printf("client successfully connected \n");
    }
    

    //send/receive message to server
    err = send (cSocket, "Connection made! \n", 17,0);

    printf("client: number of bytes sent to server: %d\n", err );
    exit (0);

    //shutdown

    //close

}

