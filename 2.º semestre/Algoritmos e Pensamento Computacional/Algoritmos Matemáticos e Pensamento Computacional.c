#include <stdio.h> //inciando bibliotecas
#include <math.h>

int main() {
    int opcao;

    do {
        printf("\n==========  MENU DE CALCULOS ==========\n");
        printf("1 - Calcular media\n");
        printf("2 - Calcular fatorial\n");
        printf("3 - Converter metros para centimetros\n");
        printf("4 - Calcular Bhaskara\n");
        printf("5 - Sair\n");
        printf("=======================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) { //mostrando a calculadora que o usuario escolheu

            case 1: { //calculo de media
                float nota1, nota2, nota3, nota4, media; //iniciando variaveis

                printf("\n----- CALCULO DA MEDIA -----\n");

                printf("Digite a primeira nota: ");
                scanf("%f", &nota1);

                printf("Digite a segunda nota: ");
                scanf("%f", &nota2);

                printf("Digite a terceira nota: ");
                scanf("%f", &nota3);

                printf("Digite a quarta nota: ");
                scanf("%f", &nota4);

                media = (nota1 + nota2 + nota3 + nota4) / 4; //calculando a media

                printf("A media e: %.2f\n", media); //mostrando a media e se o usuario foi aprovado ou reprovado

                if (media <= 5.50)
                {
                    printf("Voce foi reprovado\n");
                }
                else
                {
                    printf("Voce foi aprovado\n");
                }

                break;
            }

            case 2: { //calculo fatorial
                int numero; //iniciando variaveis
                int fatorial = 1;

                printf("\n--------- CALCULO DO FATORIAL ---------\n");

                printf("Digite um numero inteiro positivo: ");
                scanf("%d", &numero);

                if (numero <= 0) { //impedindo o usuario de colocar 0 ou um numero negativo
                    printf("Erro: o numero deve ser positivo!\n");
                } else {
                    for (int i = 1; i <= numero; i++) {
                        fatorial = fatorial * i;
                    }

                    printf("O fatorial de %d e: %d\n", numero, fatorial);
                }

                break;
            }

            case 3: { // calculadora centimetros
                float metros, centimetros; //iniciando variaveis

                printf("\n------- CONVERSAO DE METROS -------\n");

                printf("Digite o valor em metros: ");
                scanf("%f", &metros);

                if (metros <= 0) { //impedindo o usuario de colocar 0 ou um numero negativo
                    printf("Erro: o valor nao pode ser negativo!\n");
                } else {
                    centimetros = metros * 100;

                    printf("%.2f metros = %.2f centimetros\n",
                           metros, centimetros);
                }

                break;
            }

            case 4: { // calculo de Bhaskara
                float a, b, c, delta, x1, x2; //iniciando variaveis

                printf("\n---- CALCULO DE BHASKARA ----\n");

                printf("Digite o valor de A: ");
                scanf("%f", &a);

                printf("Digite o valor de B: ");
                scanf("%f", &b);

                printf("Digite o valor de C: ");
                scanf("%f", &c);

                if (a == 0) {
                    printf("Erro: o valor de A nao pode ser zero!\n");
                }
                else {

                    delta = (b * b) - (4 * a * c); //calculando o delta

                    printf("Delta = %.2f\n", delta);

                    if (delta < 0) {
                        printf("Nao existem raizes reais.\n");
                    }
                    else if (delta == 0) {

                        x1 = -b / (2 * a);

                        printf("Existe apenas uma raiz real.\n");
                        printf("X = %.2f\n", x1);

                    }
                    else {

                        x1 = (-b + sqrt(delta)) / (2 * a);
                        x2 = (-b - sqrt(delta)) / (2 * a);

                        printf("X1 = %.2f\n", x1);
                        printf("X2 = %.2f\n", x2);
                    }
                }

                break;
            }

            case 5: // fechando o programa
                printf("\nPrograma encerrado!\n");
                break;

            default:
                printf("\nOpcao invalida! Voltando ao menu...\n");
        }

    } while (opcao != 5);

    return 0;
}