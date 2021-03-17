#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>


//server code

int main()
{
	char buffer[100];
	struct sockaddr_in servaddr,clieaddr;
	int len,n,sockfd;
	sockfd=socket(AF_INET, SOCK_DGRAM,0);
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(5000);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

	bind(sockfd, (struct sockaddr*)&servaddr,sizeof(servaddr));

	len=sizeof(clieaddr);
	n=recvfrom(sockfd, buffer, sizeof(buffer)/sizeof(char), 0,(struct sockaddr *)&clieaddr, &len);
	buffer[n]='\0';
	puts(buffer);
	//sendto()
	sendto(sockfd,buffer,n,0,(struct sockaddr*)&clieaddr , sizeof(clieaddr));

	close(sockfd);

}