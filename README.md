# Truco_online
Jogo de Truco online simples em C 

Como executar: 

server.c:

gcc server.c -o server
./server 5000

client.c:

gcc client.c -o client
./client localhost 5000


Para dar inicio ao jogo é necessário que os quatro clientes estejam conectados ao servidor, caso contrário as cartas não são distribuídas. 
Depois que as cartas são distribuidas, cada cliente escolhe entre uma das opções 1,2 e 3, que são as cartas ques estão na sua "mão".
A opção '4-pedir truco' não funciona.

