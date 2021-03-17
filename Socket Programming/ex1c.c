#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define PORT 5000
#define MAXLINE 1000
int main()
{
	
	int arr1[] = {1,2,3};
	int arr2[] = {4,5,6};
	int arr3[] = {7,8,9};
	int serversock, cli, len, n;
	struct sockaddr_in serveraddr, clientaddr;
	bzero(&serveraddr, sizeof(serveraddr));
	//create socket
	serversock = socket(AF_INET, SOCK_DGRAM, 0);
	//binding
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(PORT);
	serveraddr.sin_family = AF_INET;

	//bind
	bind(serversock, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

	//send datagram socket
	sendto(serversock, arr1, MAXLINE, 0, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
	sendto(serversock, arr2, MAXLINE, 0, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
	sendto(serversock, arr3, MAXLINE, 0, (struct sockaddr*)&serveraddr, sizeof(serveraddr));	
	
	
	
	getchar();
	close(serversock);
}