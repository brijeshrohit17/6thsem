//U19CS009
//Brijesh Rohit

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>

int main() {
//creating a socket for server
	int server_socket, client_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket < 0) 
	{
		perror("--> Server error !!!\n");
		exit(1);
	}
//define server_address and client_address
	struct sockaddr_in server_address, client_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002); 
	//passing port number 9002
	server_address.sin_addr.s_addr = INADDR_ANY; 
	//specifing local machine address
	//binding socket with specific IP and port number
	int bind_connection = bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
	printf("Bind to the port number : 9002");
	//listening to connection
	listen(server_socket, 4);
	printf("\nListening...........\n");
	//accept a connection
	int size_client_addr = sizeof(client_address);
	client_socket = accept(server_socket, (struct sockaddr *)&client_address, &size_client_addr);
	printf(".....Client is connected.....\n");
	//recive data from client
	char response_client[256];
	recv(client_socket, &response_client, sizeof(response_client), 0);
	//last parameter is optional so putting 0
	//print out the data received from client
	printf("Message from client : ");
	printf("%s", response_client);
	printf("\n");
	//close the socket
	close(server_socket);
	printf("\nClient disconnected…………..\n");
	return 0;
}
