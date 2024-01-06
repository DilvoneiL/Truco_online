#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "truco.h"
#include "truco.c"
#define MAX_CLIENTS 4

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd[MAX_CLIENTS], portno;
     socklen_t clilen[MAX_CLIENTS];
     char buffer[1024];
     struct sockaddr_in serv_addr, cli_addr[MAX_CLIENTS];
     int n;
     MESA mesa;
     BARALHO baralho;
     JOGADOR jogador[MAX_CLIENTS];
     int rodada = 0, placar_total[2];
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");

    listen(sockfd, MAX_CLIENTS);
		for (int i = 0; i < MAX_CLIENTS; i++)
		{
            printf("aguardando clientes...\n");
            printf("conectados %d/%d\n",i, MAX_CLIENTS);
			clilen[i] = sizeof(cli_addr[i]);
			newsockfd[i] = accept(sockfd,(struct sockaddr *)&cli_addr[i], &clilen[i]);
			if(newsockfd[i] < 0){ 
				perror("accept");
				exit(EXIT_FAILURE);
			}
		}
        printf("conectados %d/%d\n",MAX_CLIENTS, MAX_CLIENTS);
     cria_baralho(&baralho);
     embaralhar(&baralho);
     mesa.num_rodadas = rodada;
     
     placar_total[0] = 0;
     placar_total[1] = 0;
    while(1) {
        while(1){
        /*envias as cartas para todos os clientes*/
            if(placar_total[0] == 12){
                break;
            }
            if(placar_total[1] == 12){
                break;
            }
            mesa.placar_dupla[0] = 0;
            mesa.placar_dupla[1] = 0;
            printf("placar total:\n D1:%d e D2:%d\n", placar_total[0], placar_total[1]);
            bzero(buffer, 256);
            sprintf(buffer, "D1:%d-D2:%d", placar_total[0], placar_total[1]);
            n = write(newsockfd[0], buffer, strlen(buffer));
            n = write(newsockfd[1], buffer, strlen(buffer));
            n = write(newsockfd[2], buffer, strlen(buffer));
            n = write(newsockfd[3], buffer, strlen(buffer));
                    
            bzero(buffer, 256);
            strcpy(buffer ,"D1");
            n = write(newsockfd[0], buffer, strlen(buffer));
            n = write(newsockfd[2], buffer, strlen(buffer));
            bzero(buffer, 256);
            strcpy(buffer ,"D2");
            n = write(newsockfd[1], buffer, strlen(buffer));
            n = write(newsockfd[3], buffer, strlen(buffer));
            for(int turno = 0 ; turno < 3; turno++){
                /*somente no turno 0 que as cartas são enviadas*/
                if( turno == 0){
                    embaralhar(&baralho);
                    for(int i = 0; i < MAX_CLIENTS; i++){
                        distribuir_cartas(jogador, &baralho, MAX_CLIENTS);
                        // bzero(buffer, 256);
                        // printf("Aguardando leitura\n");
                        // n = read(newsockfd[i],buffer, 6);
                        // printf("Envio realizado\n");
                        // if (n < 0) error("ERROR reading from socket");
                        for(int j = 0; j< 3; j++){
                            bzero(buffer, 256);
                            strcpy(buffer, jogador[i].carta[j].nome_nipe);
                            n = write(newsockfd[i], buffer, 6);  
                        }
                    }
                }
                /*recebe uma carta de cada cliente e adiciona a mesa*/
                for(int i = 0; i < MAX_CLIENTS; i++){
                    /*Imprimi o placar do turno*/
                    


                    bzero(buffer, 256);
                    printf("Aguardando leitura\n");
                    n = read(newsockfd[i],buffer,6);
                    printf("Envio realizado\n");

                    // if(strcmp(buffer, "TRUCO") == 0){
                    //     printf("buffer: %s",buffer);
                    //     if( i % 2 == 0){
                    //         bzero(buffer, 256);
                    //         strcpy(buffer ,"TRUCO");
                    //         n = write(newsockfd[1], buffer, strlen(buffer));
                    //         n = write(newsockfd[3], buffer, strlen(buffer));
                    //     }
                    //     if( i % 2 != 0){
                    //         bzero(buffer, 256);
                    //         strcpy(buffer ,"TRUCO");
                    //         n = write(newsockfd[1], buffer, strlen(buffer));
                    //         n = write(newsockfd[3], buffer, strlen(buffer));
                    //     }
                    //     printf("truco:%s", buffer);
                    //     //continue;
                    // }
                    // else{
                    //     bzero(buffer, 256);
                    //     strcpy(buffer ,"NTRUC");
                    //     n = write(newsockfd[0], buffer, strlen(buffer));
                    //     n = write(newsockfd[1], buffer, strlen(buffer));
                    //     n = write(newsockfd[2], buffer, strlen(buffer));
                    //     n = write(newsockfd[3], buffer, strlen(buffer));
                    // }
                    /*coloca as cartas enviadas pelo jogadores na mesa*/
                    strncpy( mesa.carta[i].nome_nipe, buffer, tamanho);
	                mesa.carta[i].valor = buscar_valor(mesa.carta[i].nome_nipe, &baralho);
                    printf("%s\n", buffer);
                    if( i % 2 == 0){
                        mesa.id_dupla[0] = i;
                        printf("dupla par: %d\n",i);
                    }
                    if(i % 2 != 0){
                        printf("dupla impar: %d\n", i);
                        mesa.id_dupla[1] = i;
                    }
                }
                placar( &mesa, &(mesa.placar_dupla[0]) , mesa.id_dupla);
                bzero(buffer, 256);
                sprintf(buffer, "D1:%d-D2:%d", mesa.placar_dupla[0], mesa.placar_dupla[1]);
                n = write(newsockfd[0], buffer, strlen(buffer));
                n = write(newsockfd[1], buffer, strlen(buffer));
                n = write(newsockfd[2], buffer, strlen(buffer));
                n = write(newsockfd[3], buffer, strlen(buffer));
                /*guardar ip da dupla pra contabilizar certo*/
                imprimir_mesa(mesa);
            }
            if(mesa.placar_dupla[0] > mesa.placar_dupla[1]){
                placar_total[0] += 2;
            }
            if(mesa.placar_dupla[0] < mesa.placar_dupla[1]){
                placar_total[1] += 2;
            }
        }

        if(n == 2 && buffer[0] == '\r' && buffer[1] == '\n' ) {
            break;
        }
        break;
    }

     //n = write(newsockfd,"I got your message",18);
     //if (n < 0) error("ERROR writing to socket");
     for (int i = 0; i < MAX_CLIENTS; i++)
     {
        close(newsockfd[i]);
     }
     close(sockfd);
     return 0; 
}