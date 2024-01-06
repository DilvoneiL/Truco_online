#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include "truco.h"
#include "truco.c"
void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n, indice;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    JOGADOR jogador;
    char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    //printf("Please enter the message: ");
    while(1){
        //bzero(buffer,256);
        // fgets(buffer,255,stdin); 
        // //strcpy(buffer, "teste");
        // n = write(sockfd, buffer, 6 );

        // if (n < 0) error("ERROR writing to socket");
        bzero(buffer,256);
        n = read(sockfd,buffer,9);
        printf("---------------------------------\n");
        printf("PLACAR DO JOGO:\n");
        printf("%s \n", buffer);

        bzero(buffer,256);
        n = read(sockfd,buffer,3);
        printf("Voce e da dupla ");
        printf("%s \n", buffer);
        printf("---------------------------------\n");
        for(int i = 0; i < 3; i++){
            bzero(buffer,256);
            n = read(sockfd,buffer,6);
	        //printf("%s\n",buffer);
            strcpy(jogador.carta[i].nome_nipe, buffer);
        }
        for(int i = 0; i < 3; i++){
            printf("----------Mão-------------------\n");
            imprimir_mao(jogador);
            printf("---------------------------------\n");
            printf("Digite a carta desejada: \n");
            scanf("%d",&indice);
            // if(indice == 4){
            //     bzero(buffer,256);
            //     strncpy(buffer, "TRUCO", 6);  
            //     n = write(sockfd, buffer, 6);
            //     printf("Digite a carta desejada: \n");
            //     scanf("%d",&indice); 
            // }
            // bzero(buffer,256);
            // n = read(sockfd,buffer,6);
            // printf("%s \n", buffer);
            // if(strcmp(buffer, "TRUCO") == 0 ){
            //     printf("ACEITAR TRUCO S/N ?");  
            // }
            bzero(buffer,256);
            strcpy(buffer, jogador.carta[indice-1].nome_nipe);
            n = write(sockfd, buffer, 6); 
            strcpy(jogador.carta[indice-1].nome_nipe,"0");
            jogador.carta[indice-1].valor = 0;
            if (n < 0) error("ERROR reading from socket");
            
            bzero(buffer,256);
            n = read(sockfd,buffer,9);
            printf("------------------------------\n");
            printf("PLACAR DO TURNO:");
            printf("%s \n", buffer);
            printf("------------------------------\n");
        }
    }
    close(sockfd);
    return 0;
}