#include "truco.h"

void atribui_nome(BARALHO *baralho){
    //nomes de cartas que são numeros, é o propio numero, e as Q,J,K e A estão em maisculo.
    strncpy(baralho->carta[0].nome_nipe,"4ouro",tamanho);
    strncpy(baralho->carta[1].nome_nipe,"4copa",tamanho);
    strncpy(baralho->carta[2].nome_nipe,"4espa",tamanho);
    
    strncpy(baralho->carta[3].nome_nipe,"5paus",tamanho);
    strncpy(baralho->carta[4].nome_nipe,"5ouro",tamanho);
    strncpy(baralho->carta[5].nome_nipe,"5copa",tamanho);
    strncpy(baralho->carta[6].nome_nipe,"5espa",tamanho);
    
    strncpy(baralho->carta[7].nome_nipe,"6paus",tamanho);
    strncpy(baralho->carta[8].nome_nipe,"6ouro",tamanho);
    strncpy(baralho->carta[9].nome_nipe,"6copa",tamanho);
    strncpy(baralho->carta[10].nome_nipe,"6espa",tamanho);

    strncpy(baralho->carta[11].nome_nipe,"7paus",tamanho);
    strncpy(baralho->carta[12].nome_nipe,"7espa",tamanho);

    strncpy(baralho->carta[13].nome_nipe,"Qpaus",tamanho);
    strncpy(baralho->carta[14].nome_nipe,"Qouro",tamanho);
    strncpy(baralho->carta[15].nome_nipe,"Qcopa",tamanho);
    strncpy(baralho->carta[16].nome_nipe,"Qespa",tamanho);

    strncpy(baralho->carta[17].nome_nipe,"Jpaus",tamanho);
    strncpy(baralho->carta[18].nome_nipe,"jouro",tamanho);
    strncpy(baralho->carta[19].nome_nipe,"Jcopa",tamanho);
    strncpy(baralho->carta[20].nome_nipe,"Jespa",tamanho);

    strncpy(baralho->carta[21].nome_nipe,"Kpaus",tamanho);
    strncpy(baralho->carta[22].nome_nipe,"Kouro",tamanho);
    strncpy(baralho->carta[23].nome_nipe,"Kcopa",tamanho);
    strncpy(baralho->carta[24].nome_nipe,"Kespa",tamanho);

    strncpy(baralho->carta[25].nome_nipe,"Apaus",tamanho);
    strncpy(baralho->carta[26].nome_nipe,"Aouro",tamanho);
    strncpy(baralho->carta[27].nome_nipe,"Acopa",tamanho);
   

    strncpy(baralho->carta[28].nome_nipe,"2paus",tamanho);
    strncpy(baralho->carta[29].nome_nipe,"2ouro",tamanho);
    strncpy(baralho->carta[30].nome_nipe,"2copa",tamanho);
    strncpy(baralho->carta[31].nome_nipe,"2espa",tamanho);

    strncpy(baralho->carta[32].nome_nipe,"3paus",tamanho);
    strncpy(baralho->carta[33].nome_nipe,"3ouro",tamanho);
    strncpy(baralho->carta[34].nome_nipe,"3copa",tamanho);
    strncpy(baralho->carta[35].nome_nipe,"3espa",tamanho);

    //MANILHAS
    strncpy(baralho->carta[36].nome_nipe,"Aespa",tamanho);
    strncpy(baralho->carta[37].nome_nipe,"7ouro",tamanho);
    strncpy(baralho->carta[38].nome_nipe,"7copa",tamanho);
    strncpy(baralho->carta[39].nome_nipe,"4paus",tamanho);
}

void atribui_valor(BARALHO *baralho){
    baralho->carta[0].valor = 1;
    baralho->carta[1].valor = 1;
    baralho->carta[2].valor = 1;
    baralho->carta[3].valor = 2;
    baralho->carta[4].valor = 2;
    baralho->carta[5].valor = 2;
    baralho->carta[6].valor = 2;
    baralho->carta[7].valor = 3;
    baralho->carta[8].valor = 3;
    baralho->carta[9].valor = 3;
    baralho->carta[10].valor = 3;
    baralho->carta[11].valor = 4;
    baralho->carta[12].valor = 4;
    baralho->carta[13].valor = 5;
    baralho->carta[14].valor = 5;
    baralho->carta[15].valor = 5;
    baralho->carta[16].valor = 5;
    baralho->carta[17].valor = 6;
    baralho->carta[18].valor = 6;
    baralho->carta[19].valor = 6;
    baralho->carta[20].valor = 6;
    baralho->carta[21].valor = 7;
    baralho->carta[22].valor = 7;
    baralho->carta[23].valor = 7;
    baralho->carta[24].valor = 7;
    baralho->carta[25].valor = 8;
    baralho->carta[26].valor = 8;
    baralho->carta[27].valor = 8;
    baralho->carta[28].valor = 9;
    baralho->carta[29].valor = 9;
    baralho->carta[30].valor = 9;
    baralho->carta[31].valor = 9;
    baralho->carta[32].valor = 10;
    baralho->carta[33].valor = 10;
    baralho->carta[34].valor = 10;
    baralho->carta[35].valor = 10;
    
    //MANILHAS, AS CARTAS COM MAIOR VALOR.
    baralho->carta[36].valor = 11;
    baralho->carta[37].valor = 12;
    baralho->carta[38].valor = 13;
    baralho->carta[39].valor = 14;
}

void imprimir_carta(CARTAS carta){
    printf("%s - %d \n", carta.nome_nipe, carta.valor );
}

void imprimir_baralho(BARALHO baralho, int tam){
    for(int i = 0; i < tam; i++){
        imprimir_carta(baralho.carta[i]);
    }
}
void imprimir_mesa(MESA mesa){
    printf("RODADAS: %d\nDUPLA 1 = %d\nDUPLA 2 = %d\n",mesa.num_rodadas, mesa.placar_dupla[0],mesa.placar_dupla[1]);
    printf("CARTAS NA MESA:\n");
    for(int i = 0; i < NUM_JOGADORES; i++){
        imprimir_carta(mesa.carta[i]);
    }
}
void imprimir_mao(JOGADOR jogador){
    for(int i = 0; i < 3; i++){
        printf(" %d - %s \n", i+1, jogador.carta[i].nome_nipe);
    }
    printf(" 4 - Pedir truco\n");
}
void cria_baralho(BARALHO *baralho){
    atribui_valor(baralho);
    atribui_nome(baralho);

}
void embaralhar(BARALHO *baralho){
    int j, aux_valor;
    char aux_nome[tamanho];
    srand(time(NULL));
    for(int i = 0; i < MAX; i++){
        j = rand()%40;
        if(j != i){
            /*salva a carta que está na posicao i em um auxiliar*/
            strncpy(aux_nome, baralho->carta[i].nome_nipe, tamanho);
		    aux_valor = baralho->carta[i].valor;
            /* recebe a carta da posicao aleatoria j e coloca na posicao i*/
		    strncpy(baralho->carta[i].nome_nipe, baralho->carta[j].nome_nipe, tamanho);
		    baralho->carta[i].valor = baralho->carta[j].valor;
            /*coloca a carta salva no aux na posicao aleatoria j*/
		    strncpy(baralho->carta[j].nome_nipe, aux_nome, tamanho);
		    baralho->carta[j].valor = aux_valor;
        }
    }
}
void distribuir_cartas(JOGADOR *jogador, BARALHO *baralho, int max_jogadores){
    //t_cartas = total de cartas que vão se retiradas do baralho e distribuidas para os jogadores
    int t_cartas = 0;
    for(int i = 0; i < max_jogadores; i++){
        for(int j = 0; j < 3; j++){
            strcpy(jogador[i].carta[j].nome_nipe, baralho->carta[t_cartas].nome_nipe);
		    jogador[i].carta[j].valor = baralho->carta[t_cartas].valor;
            t_cartas++;
            printf("lista jogador %i - ",i);
            imprimir_carta(jogador[i].carta[j]);
        }
    }
    if(t_cartas == 12){
        printf("Todas as Cartas foram distribuidas!!\n");
    }
}
void cria_mesa(JOGADOR *jogador, MESA *mesa, int indice){
    /*salva as cartas que são jogadas pelos jogadores*/
    for(int i = 0; i < 4; i++){
        strncpy( mesa->carta[i].nome_nipe, jogador[i].carta[indice].nome_nipe, tamanho);
	    mesa->carta[i].valor = jogador[i].carta[indice].valor;
    }
    mesa->placar_dupla[0] = 0;
    mesa->placar_dupla[1] = 0;
    mesa->num_rodadas = 0;
}
int maior_carta(MESA *mesa){
    /*retorna o indice da maior carta na mesa que é o indice do jogador que a jogou*/
    int maior = 0;
    for(int i = 1; i < 2; i++){
        if(mesa->carta[i].valor > mesa->carta[maior].valor){
            maior = i;
        }
    }
    printf("maior:%d", maior);
    imprimir_carta(mesa->carta[maior]);
    return maior;
}
void placar(MESA *mesa, int *placar_dupla, int *id_dupla){
    /*recebe o id de quem tem a maior carta na mesa, e verifica de qual dupla ele é pelo seu id.
    e atribui pontuação para aquela dupla.*/
    int maior = maior_carta(mesa);
    if(maior % 2 == 0){
       placar_dupla[0] += 1;
    }
    if(maior % 2 != 0){
       placar_dupla[1] += 1;
    }
    /*falta colocar contexto das regras, como primeira rodada vale mais, se pediu truco ou não*/
}
int buscar_valor(char *nome_nipe, BARALHO *baralho){
    int valor;
    for(int i = 0; i < MAX; i++){
        if(strcmp(nome_nipe, baralho->carta[i].nome_nipe) == 0){
            valor = baralho->carta[i].valor;
        }
    }
    return valor;
}
void menu(){
    // MESA mesa;
    // BARALHO baralho;
    // JOGADOR jogador[2];
    // int indice;
    // cria_baralho(&baralho);
    // embaralhar(&baralho);
    // distribuir_cartas(jogador, &baralho, 4);
    // cria_mesa(jogador, &mesa, 2);
    // imprimir_mesa(mesa);
    // indice = maior_carta(&mesa);
    // printf("maior carta:");
    // imprimir_carta(mesa.carta[indice]);
    // placar(&mesa, &(mesa.placar_dupla[0]), );
    // imprimir_mesa(mesa);
    // cria_mesa(jogador, &mesa, 1);
}
// int main(){
    
//     menu();

//     return 0;
// }
