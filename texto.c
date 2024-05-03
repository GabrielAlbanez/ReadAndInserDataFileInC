#include <stdlib.h>
#include <stdio.h>
#define MAX_ALUNOS 4

typedef struct
{
    char nome[30];
    char sobreNome[30];
    float p1;
    float p2;

} dataAlunos;

void main()

{
    char nome[20];
    char sobreNome[30];
    float n1;
    float n2;
    int numeroEscolhido;
    dataAlunos alunos[3];

    printf("digite 1 para ver o relatorio | digite 2 para inserir dados no relatorio: ");
    scanf("%d", &numeroEscolhido);
    FILE *arquivo;

    switch (numeroEscolhido)
    {
    case 1:
        arquivo = fopen("alunos.txt", "r");
        if (arquivo == NULL)
        {
            printf("error ao carregar o arquivo alunos");
            return -1;
        }
        while (fscanf(arquivo, "%s %s %f %f", alunos[0].nome, alunos[0].sobreNome, &alunos[0].p1, &alunos[0].p2) != EOF)
        {
            printf("%s %s %.2f %.2f\n", alunos[0].nome, alunos[0].sobreNome, alunos[0].p1, alunos[0].p2);
        }
        fclose(arquivo);

        break;
    case 2:
        //inserir dados
        for (int i = 1; i < MAX_ALUNOS; i++)
        {
            printf("digite nome %d aluno:\n ", i);
            scanf("%s", alunos[i].nome);
            printf("digite sobrenome %d aluno:\n ", i);
            scanf("%s", alunos[i].sobreNome);
            printf("digite p1 %d aluno:\n ", i);
            scanf("%f", &alunos[i].p1);
            printf("digite p2 %d aluno:\n ", i);
            scanf("%f", &alunos[i].p2);
        }

        printf("NOME | SOBRENOME | P1 | P2\n");
        arquivo = fopen("alunos.txt", "w");
        for (int l = 1; l < MAX_ALUNOS; l++)
        {
            fprintf(arquivo, "%s %s %.2f %.2f\n", alunos[l].nome, alunos[l].sobreNome, alunos[l].p1, alunos[l].p2);
            printf("%s %s %.2f %.2f\n", alunos[l].nome, alunos[l].sobreNome, alunos[l].p1, alunos[l].p2);
        }
        fclose(arquivo);

        break;

    default:
        printf("opção de escolha invalida");
        break;
    }
    return 0;
}
