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
	printf("-----------CLIENT PROGRAM-------------\n");

	char buffer[100];
	int arr1[4];
	int arr2[4];
	int arr3[4];
	printf("Enter row 1 :\n");
	for(int i=0;i<4;i++){
		scanf("%d",&arr1[i]);
	}
	printf("Enter row 2 :\n");
	for(int i=0;i<4;i++){
		scanf("%d",&arr2[i]);
	}

	printf("Enter row 3 :\n");
		for(int i=0;i<4;i++){
			scanf("%d",&arr3[i]);
		}



	int sockfd,len,n;

	struct sockaddr_in servaddr,cliaddr;


	//Clear servaddr
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(PORT);
	servaddr.sin_family=AF_INET;

	//Create datagram socket 
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);


    sendto(sockfd,arr1, MAXLINE, 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
	
    sendto(sockfd,arr2, MAXLINE, 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
	
    sendto(sockfd,arr3, MAXLINE, 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
	

	len=sizeof(cliaddr);


	//Waiting for response 
	n=recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&cliaddr,&len);
	buffer[n]='\0';

	printf("Message from server is %s\n",buffer);
	getchar();

	//Close the descriptor
	close(sockfd);



}