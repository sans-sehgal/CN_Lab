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

#define MAX 80
#define PORT 8080
//#define SA struct sockaddr
void clientfunction(int field){
	char buff[MAX];
	int n;
	while(1){
		bzero(buff, sizeof(buff));
		printf("Enter message for server : \n");
		n = 0;
		while((buff[n++] = getchar()) != '\n');
		// send that message to the server
		write(field, buff, sizeof(buff));
		bzero(buff, sizeof(buff));
		//read reply from server
		read(field, buff, sizeof(buff));
		printf("From server %s\t",buff);
		if((strncmp("exit",buff,4))==0){
			printf("Client exit...\n");
			break;
		}
	}
}
int main(){
	int sockfield;
	struct sockaddr_in serveraddr, clientaddr;

	if((sockfield = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created\n");

	bzero(&serveraddr,sizeof(serveraddr));
	
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(PORT);

	if(connect(sockfield, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) != 0){
		printf("Connection to server failed...\n");
	}
	else
		printf("Connection established...\n");
	clientfunction(sockfield);
	close(sockfield);

}
