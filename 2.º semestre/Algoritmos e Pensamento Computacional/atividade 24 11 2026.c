//iniciando bibliotecas e variaveis
#include <stdio.h>
#include <string.h>

//struct que armazena os dados dos alunos
struct Aluno 
{
    int rgm;
    char nome[100];
    float nota1, nota2;
    int notasLancadas;
};

//cadastrar novos alunos
void cadastrarAluno(struct Aluno alunos[], int *total)
{
    int rgm;

    //impedindo de passar do limite de alunos cadastrados
    if (*total >= 100) 
    {
        printf("\nLimite maximo de alunos atingido\n");
        return;
    }

    //cadastro aluno
    printf("\n--- CADASTRO DE ALUNO ---\n");

    printf("Digite o RGM: ");
    scanf("%d", &rgm);
    getchar();

    //verificando se o rgm já existe
    for (int i = 0; i < *total; i++) 
    {
        if (alunos[i].rgm == rgm) 
        {
            printf("\nEsse RGM ja esta cadastrado\n");
            return;
        }
    }

    alunos[*total].rgm = rgm;

    printf("Digite o nome do aluno: ");
    fgets(alunos[*total].nome, 100, stdin);

    //removendo a quebra de linha do nome
    alunos[*total].nome[strcspn(alunos[*total].nome, "\n")] = '\0';

    alunos[*total].nota1 = 0;
    alunos[*total].nota2 = 0;
    alunos[*total].notasLancadas = 0;

    (*total)++;

    printf("\nAluno cadastrado com sucesso\n");
}

//lançar notas
void lancarNotas(struct Aluno alunos[], int total) 
{
    int rgm, encontrado = -1;

    printf("\n--- LANCAMENTO DE NOTAS ---\n");

    printf("Digite o RGM do aluno: ");
    scanf("%d", &rgm);

    //procura o aluno pelo rgm
    for (int i = 0; i < total; i++) 
    {
        if (alunos[i].rgm == rgm) 
        {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) 
    {
        printf("\nAluno nao encontrado\n");
        return;
    }

    printf("\nAluno: %s\n", alunos[encontrado].nome);

    //criando variaveis temporarias para validar as notas antes de armazenar
    float nota1, nota2;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    //impedindo dos numeros serem menores que 0 ou maiores que 10
    if (nota1 < 0 || nota1 > 10 || nota2 < 0 || nota2 > 10)
    {
        printf("\nNotas invalidas. Utilize valores entre 0 e 10.\n");
        return;
    }

    alunos[encontrado].nota1 = nota1;
    alunos[encontrado].nota2 = nota2;
    alunos[encontrado].notasLancadas = 1;

    //calculando a media das notas do aluno
    float media = (nota1 + nota2) / 2;

    printf("Media do aluno: %.2f\n", media);

    printf("\nNotas lancadas com sucesso\n");

}

//mostrando o relatorio
void imprimirRelatorio(struct Aluno alunos[], int total) 
{
    printf("\n--- RELATORIO DE ALUNOS ---\n");
    
    //avisando que não tem casdastro de nenhum aluno
    if (total == 0) 
    {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    for (int i = 0; i < total; i++) 
    {
        printf("\nAluno %d\n", i + 1);
        printf("RGM: %d\n", alunos[i].rgm);
        printf("Nome: %s\n", alunos[i].nome);

        if (alunos[i].notasLancadas == 1) 
        {
            printf("Nota 1: %.2f\n", alunos[i].nota1);
            printf("Nota 2: %.2f\n", alunos[i].nota2);
            printf("Media: %.2f\n",
                   (alunos[i].nota1 + alunos[i].nota2) / 2);
        } 
        else 
        {
            printf("Notas: Ainda nao lancadas.\n");
        }
    }
}

//calculando a media da turma
void calcularMediaGeral(struct Aluno alunos[], int total) 
{
    float soma = 0;
    int alunosComNotas = 0;

    for (int i = 0; i < total; i++) 
    {
        if (alunos[i].notasLancadas == 1) 
        {
            soma += (alunos[i].nota1 + alunos[i].nota2) / 2;
            alunosComNotas++;
        }
    }

    printf("\n--- MEDIA GERAL DA TURMA ---\n");

    //avisando que nenhuma nota foi lançada ainda
    if (alunosComNotas == 0) 
    {
        printf("Ainda nao existem notas lancadas.\n");
    } else 
    {
        printf("Alunos com notas: %d\n", alunosComNotas);
        printf("Media geral da turma: %.2f\n",
               soma / alunosComNotas);
    }
}

int main() 
{
    struct Aluno alunos[100];

    int total = 0;
    int opcao;

    do 
    {
        printf("\n============ MENU ============\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Lancar notas\n");
        printf("3 - Imprimir relatorio\n");
        printf("4 - Calcular media geral\n");
        printf("0 - Sair\n");
        printf("==============================\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                cadastrarAluno(alunos, &total);
                break;

            case 2:
                lancarNotas(alunos, total);
                break;

            case 3:
                imprimirRelatorio(alunos, total);
                break;

            case 4:
                calcularMediaGeral(alunos, total);
                break;

            case 0:
                printf("\nfechando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}