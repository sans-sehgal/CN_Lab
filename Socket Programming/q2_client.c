#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
//client code tcp

/*void chat(int sockfd)
{
	char buff[100];
	for(;;)
	{
		printf("enter message for server\n");
		scanf("%s" , buff);
		write(sockfd,buff, sizeof(buff));
		bzero(buff,100);
		read(sockfd,buff,sizeof(buff));

		printf("%s" , buff);
		//if(strcmp(buff,"exit"))
		//{
		//	printf("exiting\n");
		//	break;
		//}
	}
}*/

int main()
{
	int sockfd,len,n;
	struct sockaddr_in servaddr,clienaddr;

	sockfd=socket(AF_INET, SOCK_DGRAM,0);

	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(5050);
	


	len=sizeof(servaddr);

	if(connect(sockfd,(struct sockaddr*)&servaddr , len)!=0)
		printf("connection failed\n");
	else
		printf("now connected!\n");
	char buff[100];
	printf("enter message for server\n");
	n = 0;
	while((buff[n++] = getchar()) != '\n');
	printf("%s" , buff);
	
		write(sockfd,buff, sizeof(buff));
		//printf("write successful!\n");
		bzero(buff,100);
		read(sockfd,buff,sizeof(buff));
		printf("%s" , buff);
	
	
	//chat(sockfd);

	close(sockfd);

}