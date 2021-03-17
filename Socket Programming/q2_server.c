#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>


/*void chat(int sockfd)
{
	char buff[100];
	for(;;)
	{
		bzero(buff,sizeof(buff));
		read(sockfd,buff,100);
		printf("%s\n" , buff);
		bzero(buff,100);
		printf("enter message for client\n");
		scanf("%s" , buff);
		write(sockfd,buff,100);

		//if(strcmp(buff,"exit")==0)
		//{	
		//	printf("exiting");
		//	break;			
		//}
	}
}*/


int main()
{
	struct sockaddr_in servaddr,clienaddr;
	int sockfd,len,connfd;
	sockfd=socket(AF_INET, SOCK_STREAM,0);
	if(sockfd==-1)
		printf("socket creation failed\n");
	else
		printf("socket creation successful\n");
	
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(5050);

	if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))!=0)
		printf("socket binding failed\n");
	else
		printf("secket binding was successful\n");

	if(listen(sockfd,5)!=0)
	{
		printf("listen failed\n");
	}
	else
		printf("successfully listening\n");
	len=sizeof(clienaddr);
	connfd=accept(sockfd,(struct sockaddr*)&clienaddr,&len);
	if(connfd<0)
	{
		printf("Connection failed\n");
		//exit(1);	
	}
	else
	{
		printf("server successfully accepted client\n");
	}
	char buff[100];
	read(connfd,buff,100);
	printf("%s\n" , buff);
	bzero(buff,100);
	printf("enter message for client\n");
	scanf("%s" , buff);
	write(connfd,buff,100);

	//chat(connfd);
	close(sockfd);



}