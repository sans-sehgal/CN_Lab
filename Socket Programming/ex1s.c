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
int main(){
	int arr[3];
	int buffer[3][3];
	for(int i=0; i<3; i++){
		for(int j=0; j<3;j++)
			buffer[i][j]=0;
	}
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

	len = sizeof(clientaddr);
	
	for(int i=0; i<3; i++){
		n = recvfrom(serversock, arr, sizeof(arr), 0, (struct sockaddr*)&clientaddr, &len);
		for(int k=0; k<3; k++){
			buffer[i][k] = arr[k];
		}
	}
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3;j++)
			printf("%d\t", buffer[i][j]);
		printf("\n");
	}
	
	getchar();

	close(serversock);

}