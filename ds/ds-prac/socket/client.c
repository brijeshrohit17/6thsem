//U19CS009
//Brijesh Rohit

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>

int main() 
{
//Creating a socket for client
    int no_socket;
    no_socket = socket(AF_INET, SOCK_STREAM, 0);
//specifing address for client socket
    struct sockaddr_in client_addr;
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(9002); //passing port number 9002
    client_addr.sin_addr.s_addr = INADDR_ANY; //specifing local machine address (equivalent to 0.0.0.0)
    int connection_status = connect(no_socket, (struct sockaddr *)&client_addr, sizeof(client_addr)); // 0 OK -1 error
//Checking whether there is an error in connection
    if (connection_status < 0) 
    {
        perror("--->There was an error making connection with the remote socket\n\n");
        exit(1);
    }
    printf("Connected to the server.......\n");
    printf("Client information : ");
    FILE *client;
    char send_client[256] = "No such file exists!!\n";
    client = popen("cat a.c", "r");
    if (client != NULL) 
    {
        while (1)
        {
            char *line;
            line = fgets(send_client, sizeof(send_client), client);
            if (line == NULL)
                break;
            printf("%s", line); /* line includes '\n' */
        }
        pclose(client);
    }
    else {
        printf("No such file exists!!\n");
    }
    send(no_socket, send_client, sizeof(send_client), 0);
    // recv(no_socket, send_client, sizeof(send_client), 0);
    if(send_client <=0)
    {
        printf("No such file exists!!\n");
    }
    else
    {
        while (1)
        {
            char *line;
            line = fgets(send_client, sizeof(send_client), client);
            if (line == NULL)
                break;
            printf("%s", line); /* line includes '\n' */
        }
    }
//close the connection
    close(no_socket);
    printf("\n Disconnected from server...\n");
    return 0;
}