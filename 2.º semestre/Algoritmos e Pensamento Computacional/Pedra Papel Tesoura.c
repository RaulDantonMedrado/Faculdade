//chamando bibliotecas e iniciando variaveis
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int _pedra = 1;
const int _papel = 2;
const int _tesou = 3;

int main(){
    int usuario, computador, placar[2]={0,0};
    float porcentagem;
    char c;
    srand(time(NULL));
    
    do {
        do { //pedindo pro usuario escolher entre as 4 opções
            printf("=============== PEDRA, PAPEL OU TESOURA =============== ");
            printf("\nEscolha: 1-Pedra, 2-Papel, 3-Tesoura (9-Desistir): "); 
            scanf ("%d", &usuario);
        } while (usuario!=1 && usuario!=2 && usuario!=3 && usuario!=9);
        
        if(usuario==9){ //fechando o programa
            break;
        }
        
        computador=rand() %3 + 1; 
        printf("\n");
        
        if (usuario==_pedra){ //opções caso o usuario escolha pedra
            if(computador==_pedra){
                printf("Pedra! Empatamos!");
            }
            else if(computador==_papel){
                printf("Papel! Voce perdeu!");
                placar[1]++; //placar computador
            }
            else if(computador==_tesou){
                printf("Tesoura! Você ganhou!");
                placar[0]++; //placar usuario
            }
        }
        else if(usuario==_papel){ //opções caso o usuario escolha papel
            if(computador==_pedra){
                printf("Pedra! Você ganhou!");
                placar[0]++; //placar usuario
            }
            else if(computador==_papel){
                printf("Papel! Empatamos!");
            }
            else if(computador==_tesou){
                printf("Tesoura! Voce perdeu !");
                placar[1]++; //placar computador
            }
        }
        else if(usuario==_tesou){ //opções caso o usuario escolha tesoura
            if(computador==_pedra){
                printf("Pedra! Voce perdeu!");
                placar[1]++; //placar computador
            }
            else if(computador==_papel){
                printf("Papel ! Você ganhou!");
                placar[0]++; //placar usuario
            }
            else if(computador==_tesou){
                printf("Tesoura! Empatamos!");
            }
        }
        
        if (placar[0] + placar[1] > 0) { //calculos do placar
            porcentagem = (float) placar[0] / (placar[0] + placar[1]) * 100;
        } else {
            porcentagem = 0.0;
        }
        //mostrando o placar
        printf("\nPlacar: %d usuário X computador %d (%.1f%%)\n", placar[0], placar[1], porcentagem);
        printf("Tenta de novo?  (S/N) "); 
        scanf(" %c", &c);
        
    } while(c=='s' || c=='S'); //vendo se o usuario aceitou mais uma partida
    
    return 0;
}