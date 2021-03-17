#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#define PORT 5000
#define MAXLINE 1000





int main(){
	printf("-----------SERVER PROGRAM-------------\n");
	char buffer[100];
	int mat[3][4];
	int row[4];
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			mat[i][j]=0;
		}
	}
	int servsockfd,len,n;
	struct sockaddr_in servaddr,cliaddr;
	bzero(&servaddr,sizeof(servaddr));
	char *mssg="Data Received";

	//Create a UDP Socket

	servsockfd=socket(AF_INET,SOCK_DGRAM,0);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(PORT);
	servaddr.sin_family=AF_INET;

	//bind server address to socket descriptor

	bind(servsockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));


	//receive the datagram
	
	len=sizeof(cliaddr);
	for(int i=0;i<3;i++){
		n=recvfrom(servsockfd,row,sizeof(row),0,(struct sockaddr*)&cliaddr,&len);

		for(int j=0;j<4;j++){
			mat[i][j]=row[j];
		}


	}
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	
	

	//Echoing back to the client 
	sendto(servsockfd,mssg,n,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
	getchar();


	//Close the descriptor
	close(servsockfd);
}