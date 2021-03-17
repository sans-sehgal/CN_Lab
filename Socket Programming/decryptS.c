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
#include <ctype.h>

#define MAX 80
#define PORT 8080
//#define SA struct sockaddr
void serverfunction(int field, struct sockaddr_in clientaddr){
	char buff[MAX];
	int n;
	//while(1){
		bzero(buff, MAX);
		//read message from client
		read(field, buff, sizeof(buff));
		for(int i=0; i<strlen(buff); i++){
			int decrypt = buff[i];
			if(decrypt<=100){
				decrypt += 22;
			}
			else
				decrypt -= 4;
			buff[i] = decrypt;
		}
		printf("%s\n", buff);
		// clear buffer
		//bzero(buff, sizeof(buff));
		// read whatever message written by keyboard as in reply
		// n = 0;
		// while((buff[n++] = getchar()) != '\n');
		// send that reply to the client
		//write(field, buff, sizeof(buff));

		
	//}
}
int main(){
	char buffer[100];
	int sockfield, len, n, clientfield;
	struct sockaddr_in serveraddr, clientaddr;

	if((sockfield = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created\n");

	bzero(&serveraddr,sizeof(serveraddr));
	
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(PORT);

	if((bind(sockfield, (struct sockaddr*)&serveraddr, sizeof(serveraddr))) != 0){
		printf("socket binding failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully bound\n");
	//server listening only in tcp
	if((listen(sockfield, 5)) != 0 ){
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Listening successfully \n");
	len = sizeof(clientaddr);
	clientfield = accept(sockfield, (struct sockaddr*)&clientaddr, &len);
	if(clientfield < 0){
		printf("server accept failed...\n");
		exit(0);
	}
	else
		printf("Server successfully accepted client\n");
	serverfunction(clientfield, clientaddr);
	close(sockfield);

}
