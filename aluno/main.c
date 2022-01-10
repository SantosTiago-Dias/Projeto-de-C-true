#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

#define MAX_ESCOLA 1
#define MAX_ALUNOS 200
#define MAX_EMAIL 50

//Estrutura escola
typedef struct   // nome da estrutura
{
    int id_escola;
    char nome[80],abv[5],campus[10],localidade[25];
} estrutura_escola;

//Estrutura alunos
typedef struct   // nome da estrutura
{
    int id_aluno,id_escola,nif;
    float saldo;
    char nome[80],tipo_utilizador[50],email[80];
} estrutura_aluno;

//Estrutura transações
typedef struct   // nome da estrutura
{
    char nome[80], morada[50]; // campos
    float salario; // da
    int numero_filhos; // estrutura
} teste;


int menu_inicial();
int menu_de_estatisticas();
int menu_registar_importar();
void prenche_escola(estrutura_escola escola[MAX_ESCOLA]);
void prenche_alunos(estrutura_aluno aluno[MAX_ALUNOS]);
void verifica_email(estrutura_aluno aluno[MAX_ALUNOS], int pos);
void tipo_utilizador(estrutura_aluno aluno[MAX_ALUNOS], int pos);
void mostrar_aluno(estrutura_aluno aluno[MAX_ALUNOS]);


int main()
{
    setlocale (LC_ALL, "Portuguese");//defenir a lingua portuguesa
    estrutura_escola escola[MAX_ESCOLA];
    estrutura_aluno aluno[MAX_ALUNOS];
    int op;
    int op_estatisticas,op_resgitar_importar;

    do
    {
        op=NULL;
        printf("%d",op);
        system("cls");
        op = menu_inicial();

        switch(op)
        {
        case 1:
            //Registar/importar os dados das escolas
            op_resgitar_importar=menu_registar_importar();
            switch (op_resgitar_importar)
            {
            case 1:
                system("cls");
                //prenche_escola(escola);
                prenche_alunos(aluno);
                break;

            case 2:
                system("cls");
                //prenche_escola(escola);
                mostrar_aluno(aluno);
                break;

            }
            break;
        case 2:


            break;
        case 3:
            //Registar e consultar os dados das transações
            break;
        case 4:
            //Estatísticas
            system("cls");
            op_estatisticas=menu_de_estatisticas();
            switch(op_estatisticas)
            {
            case 1:
                //Total faturado por escola
                break;
            case 2:
                //Total faturado por escola
                break;
            case 3:
                //Total faturado por escola
                break;
            case 0:
                //voltar atras
                break;
            }
            break;
        case 5:
            //Mostrar notas negativas
            break;
        case 0:
            //sair
            break;
        }


    }
    while(op != 0);
    return 0;
}

//FUNÇÃO MENU
int menu_inicial()
{
    int op;
    do
    {
        printf("\n\t\t\t\tMenu de opcões");
        printf("\n 1 - Registar ou importar os dados das escolas");
        printf("\n 2 - Registar e consultar os dados dos utilizadores");
        printf("\n 3 - Registar e consultar os dados das transações");
        printf("\n 4 - Estatísticas");
        printf("\n 5 - Guardar e ler de ficheiros binários os dados da aplicação");
        printf("\n 0 - Sair");
        printf("\n Opção-->");
        scanf("%d",&op);
        if(op<0 || op >6)
        {
            printf("\n Opção invalida");
            sleep(2);
        }
    }
    while(op<0 && op >6);

    return op;
}
//FIM DE MENU

//FUNÇÃO MENU de Registar/Importar
int menu_registar_importar()
{
    int op;
    do
    {

        printf("\n\t\t\t\tMenu Registar/importar");
        printf("\n 1 - Registar");
        printf("\n 2 - Importar");
        printf("\n 0 - Voltar atras");
        printf("\n Opção-->");
        scanf("%d",&op);
        if(op<0 || op >2)
        {
            printf("\n Opção invalida");
            sleep(2);
        }
    }
    while(op<0 && op >2);

    return op;
}
//FIM MENU de Registar/Importar

//FUNÇÃO MENU de estaticas
int menu_de_estatisticas()
{
    int op;
    printf("\n\t\t\t\tMenu de Estatísticas");
    printf("\n 1 - Total faturado por escola");
    printf("\n 2 - Percentagem de transações por escola");
    printf("\n 3 - Total de transações (pagamentos) entre duas datas (horizonte temporal) por tipo de utilizador");
    printf("\n 0 - Voltar atras");
    printf("\n Opção-->");
    scanf("%d",&op);
    return op;
}
//FIM MENU de estaticas

//Função preenche
void prenche_alunos(estrutura_aluno aluno[MAX_ALUNOS])
{
    int posicao;
    for (posicao = 0; posicao <= 1; posicao++)
    {
        printf("\nIndentificação do aluno nº:%d ",posicao+1);
        aluno[posicao].id_aluno=posicao+1;
        printf("\nIntroduza nome do aluno: ");
        fflush(stdin);
        scanf("%[^\n]",&aluno[posicao].nome);
        verifica_email(aluno,posicao);
       tipo_utilizador(aluno,posicao);
        printf("Introduza o nif:");
        scanf("%d",&aluno[posicao].nif);
        printf("Introduza o saldo:");
        scanf("%f",&aluno[posicao].saldo);
    }
}
//FIM array escolas

//Inicio de verifica email
void verifica_email(estrutura_aluno aluno[MAX_ALUNOS], int pos)
{
    char email[80];
    int posicao=0;
    printf("Introduza email do aluno: ");
    fflush(stdin);
    scanf("%[^\n]",email);

    for (posicao=0; posicao<strlen(email); posicao++)
    {
        //printf("%c",email[posicao]);
        if(email[posicao]=='@')
            strcpy(aluno[pos].email,email);

    }
    //printf(" %s",email);



}
//Fim de verifica email

//Inicio de tipo_utilizador
void tipo_utilizador(estrutura_aluno aluno[MAX_ALUNOS],int pos)
{

    //return "my String";

    int utilizador;
    do
    {

        printf("\n 1 - Estudante");
        printf("\t 2 - Docente");
        printf("\t 3 - Funcionario");
        printf("\n Tipo de utilizador-->");
        scanf("%d",&utilizador);

        switch(utilizador)
        {
        case 1:
            //printf("Estudante");
            strcpy(aluno[pos].tipo_utilizador,"Estudante");
            break;
        case 2:
            strcpy(aluno[pos].tipo_utilizador,"Docente");
            break;
        case 3:
            strcpy(aluno[pos].tipo_utilizador,"Funcionario");
            break;
        default:
            printf("Insira o valor certo");
        }
    }
    while(utilizador<0 && utilizador >=3);
}
//Fim de tipo_utilizador
void mostrar_aluno(estrutura_aluno aluno[MAX_ALUNOS])
{
    char sair;
    int posicao;
    for (posicao=0; posicao<= 1; posicao++)
    {
        printf("\nIdentidade: %d", aluno[posicao].id_aluno);
        //printf("Id escola: %d", aluno[i].id_escola);
        printf("\nNome: %s",aluno[posicao].nome);
        printf("Email: %s", aluno[posicao].email);
        printf("\nTipo de user: %s", aluno[posicao].tipo_utilizador);
        printf("\nSaldo:%.2f", aluno[posicao].saldo);
        printf("\nNif: %d", aluno[posicao].nif);
    }
    scanf(" %c",sair);
}

