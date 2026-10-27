#include <stdio.h>

int main() { 
    //iniciando variaveis
    int assentos[5][5] = {0};
    int opcao, fileira, cadeira, livres;
    
    //assentos já reservados
    assentos[0][1] = 1;
    assentos[0][2] = 1;
    assentos[0][3] = 1;
    assentos[1][2] = 1;
    assentos[2][0] = 1;
    assentos[2][3] = 1;
    assentos[2][4] = 1;
    assentos[3][2] = 1;
    assentos[4][1] = 1;

    do { //iniciando o menu 
        printf("\n===== SISTEMA DE RESERVA DE ASSENTOS DO CINEMA HPINHO =====\n");
        printf("1 - Visualizar assentos\n");
        printf("2 - Reservar assento\n");
        printf("3 - Cancelar reserva\n");
        printf("4 - Consultar disponibilidade\n");
        printf("5 - Sair\n");
        printf("===========================================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1: //mostrando o menu de todos os assentos
                printf("\n===== MAPA DE ASSENTOS =====\n");
                printf("L = Livre | R = Reservado\n");

                printf("          "); //espaços pros numeros ficarem em cima de cada assento nas fileiras
                for (int j = 0; j < 5; j++) {
                    printf("%d  ", j + 1);
                }
                printf("\n");

                for (int i = 0; i < 5; i++) {
                    printf("Fileira %d ", i + 1);

                    for (int j = 0; j < 5; j++) {
                        if (assentos[i][j] == 0) {
                            printf("L  ");
                        } else {
                            printf("R  ");
                        }
                    }

                    printf("\n");
                }
                break;

            case 2: //mostrando o menu de reserva de assentos
                printf("\n========== RESERVAR ASSENTO ==========\n");

                printf("Digite o numero da fileira (1 a 5): ");
                scanf("%d", &fileira);

                printf("Digite o numero do assento (1 a 5): ");
                scanf("%d", &cadeira);

                while (fileira < 1 || fileira > 5 || //impedindo o usuario de escolher uma opção que não seja de 1 a 5
                       cadeira < 1 || cadeira > 5) {
                    printf("\nFileira ou assento invalido\n");

                    printf("Digite a fileira (1 a 5): ");
                    scanf("%d", &fileira);

                    printf("Digite o numero do assento (1 a 5): ");
                    scanf("%d", &cadeira);
                }
                //fazendo o assento seja reservado ou mostrando que outra pessoa já o reservou
                if (assentos[fileira - 1][cadeira - 1] == 0) { 
                    assentos[fileira - 1][cadeira - 1] = 1;
                    printf("\nReserva realizada com sucesso\n");
                } else {
                    printf("\nEsse assento foi já foi reservado por outra pessoa\n");
                }
                break;

            case 3: //mostrando o menu de cancelamento de reserva
                printf("\n========== CANCELAR RESERVA ==========\n");

                printf("Digite a fileira (1 a 5): ");
                scanf("%d", &fileira);

                printf("Digite o numero do assento (1 a 5): ");
                scanf("%d", &cadeira);

                while (fileira < 1 || fileira > 5 || //impedindo o usuario de escolher uma opção que não seja de 1 a 5
                       cadeira < 1 || cadeira > 5) {
                    printf("\nFileira ou assento invalido\n");

                    printf("Digite o numero da fileira (1 a 5): ");
                    scanf("%d", &fileira);

                    printf("Digite o numero do assento (1 a 5): ");
                    scanf("%d", &cadeira);
                }

                if (assentos[fileira - 1][cadeira - 1] == 1) {
                    assentos[fileira - 1][cadeira - 1] = 0;
                    printf("\nReserva cancelada com sucesso\n");
                } else {
                    printf("\nEsse assento ja esta livre\n");
                }
                break;

            case 4: //mostrando o menu de disponibilidade dos assentos
                livres = 0;

                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (assentos[i][j] == 0) {
                            livres++;
                        }
                    }
                }

                printf("\n===== DISPONIBILIDADE =====\n");
                printf("Total de assentos: 25\n");
                printf("Assentos livres: %d\n", livres);
                printf("Assentos reservados: %d\n", 25 - livres);
                break;

            case 5: // fechando o programa
                printf("\nEncerrando o programa...");
                break;

            default: 
                printf("\nOpcao invalida, Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}