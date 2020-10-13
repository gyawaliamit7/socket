#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "soc.h"


#define BUFL 100
int main (int argc , char * argv[]) 
{
    int err;
    int sSocket;
    int cSocket;
    struct sockaddr_in sAddr;
    struct sockaddr_in cAddr;
    int cSocLen;
    char Buf[BUFL];


    //creating a socket
    sSocket = socket(AF_INET, SOCK_STREAM,0);
    if (sSocket == -1)
    {
        printf("server socket creation failed");
        exit(1);
    }
    else 
    {
        printf("server successfully created \n");
    }

    //bind the socket to an address
    memset(&sAddr, 0, sizeof(struct sockaddr_in));
    sAddr.sin_family =AF_INET;
    sAddr.sin_port = htons(SERVERPORT);
    sAddr.sin_addr.s_addr = INADDR_ANY;
    err = bind (sSocket, (struct sockaddr*)& sAddr, sizeof (struct sockaddr_in));

    if (err == -1)
    {
        printf("failed bind address to socket ");
        exit(2);
    }
    else 
    {
        printf("Successfully bind to address \n");
    }

    //listen 
    err = listen(sSocket, 5);
    if (err == -1)
    {
        printf("failed to listen client");
        exit(3);
    }
    else 
    {
        printf("successfully listening to client \n");


    }

    //accept the connection from client
    cSocket = accept(sSocket, (struct sockaddr *) &cAddr, &cSocLen);
    if (cSocket == -1)
    {
        printf("server: accept failed \n");
        exit(4);

    }
    else 
    {
        printf("server accepted the client \n ");
    }

    //read from the client socket
    err = recv(cSocket, Buf, BUFL, 0);
    if (err == -1)
    {
        printf("server: read failed from client");
    }
    else
    {
        printf("successfully read from client \n");
    }
    

    //displaying message from the client 
    printf("server: msg from client: %s\n",Buf);

    //send

    //shutdown

    //close
    exit(0);
}

