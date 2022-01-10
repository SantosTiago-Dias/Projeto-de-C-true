#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

#define MAX_ESCOLA 1
#define MAX_ALUNOS 3
#define MAX_EMAIL 80

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
void mostrar_escola(estrutura_escola escola[MAX_ESCOLA]);


int main()
{
    setlocale (LC_ALL, "Portuguese");//defenir a lingua portuguesa
    estrutura_escola escola[MAX_ESCOLA];
    estrutura_aluno aluno[MAX_ALUNOS];
    int op;
    int op_estatisticas,op_resgitar_importar;

    do
    {
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
                prenche_escola(escola);
                mostrar_escola(escola);
                break;

            case 2:
                system("cls");
                prenche_escola(escola);
                break;

            }
            break;
        case 2:
            //prenche_alunos(aluno);
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

//Função preenche escola
void prenche_escola(estrutura_escola escola[MAX_ESCOLA])
{
    int pos;
    for (pos = 0; pos <= MAX_ESCOLA; pos++)
    {
        //printf("Introduza a indentificação da escola nº%d: ",pos);
        //scanf("%d", &escola[pos].id_escola);
        printf("\nIndentificação da escola:%d",pos);
        escola[pos].id_escola=pos;
        printf("\nIntroduza nome da escola: ");
        fflush(stdin);
        scanf("%[^\n]",escola[pos].nome);
        printf("\nIntroduza a abreviatura da escola: ");
        fflush(stdin);
        scanf("%[^\n]",escola[pos].abv);
        printf("\nIntroduza o campus: ");
        fflush(stdin);
        scanf("%[^\n]",escola[pos].campus);
        printf("\nIntroduza a localidade da escola: ");
        fflush(stdin);
        scanf("%[^\n]", escola[pos].localidade);
    }
}
//FIM preenche escolas

void mostrar_escola(estrutura_escola escola[MAX_ESCOLA])
{

    for (int i=0; i<=MAX_ESCOLA; i++)
    {
        printf("Identidade: %d\n", escola[i].id_escola);
        printf("Nome: %s\n",escola[i].nome);
        printf("Abreviatura: %s\n", escola[i].abv);
        printf("Campus: %s\n", escola[i].campus);
        printf("Localidade: %s\n", escola[i].localidade);
    }
    sleep(2);
}

