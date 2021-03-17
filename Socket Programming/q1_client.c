#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

int main()
{
	char buffer[100];
	char *message="hello you";
	int socketfd,n;
	struct sockaddr_in servaddr,clienaddr;
	

	socketfd=socket(AF_INET, SOCK_DGRAM, 0);
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(5000);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

	sendto(socketfd, message,strlen(message),0,(struct sockaddr*)&servaddr , sizeof(servaddr));
	int len=sizeof(servaddr);
	n=recvfrom(socketfd,buffer, 100,0,(struct sockaddr*)&servaddr,&len);
	buffer[n]='\0';
	printf("%s" , buffer);
	close(socketfd);



}
