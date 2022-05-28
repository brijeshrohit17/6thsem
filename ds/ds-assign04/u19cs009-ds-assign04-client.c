//U19CS009
//Brijesh Rohit

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>

int main() {
//Creating a socket for client
	int no_socket;
	no_socket = socket(AF_INET, SOCK_STREAM, 0);
//specifing address for client socket
	struct sockaddr_in client_address;
	client_address.sin_family = AF_INET;
	client_address.sin_port = htons(9002);
//passing port number 9002
	client_address.sin_addr.s_addr = INADDR_ANY; 
	//specifing local machine address
	int connection_status = connect(no_socket, (struct sockaddr *)&client_address, sizeof(client_address)); 
	// 0 OK -1 error
//Checking whether there is an error in connection
	if (connection_status < 0) 
	{
		perror("--->There was an error making connection with the remote socket\n\n");
		exit(1);
	}
	printf("Connected to the server.......\n");
//send data to server
	char send_server[256];
	printf("Enter the message to send : ");
	scanf("%s", send_server);
	send(no_socket, send_server, sizeof(send_server), 0);
	printf("\n");
//close the connection
	close(no_socket);
	printf("\n Disconnected from server.......\n");
	return 0;
}
