#include <stdio.h>
#include <stdlib.h>
#include <locale.h>Projeto-de-C

#include <ctype.h>

#define MAX_ESCOLA 1
#define MAX_ALUNOS 3
#define MAX_EMAIL 80
#define MAX_TRASANCAO 10
//Estrutura escola
typedef struct // nome da estrutura
{
    int id_escola;
    char nome[80], abv[5], campus[10], localidade[25];
} t_estrutura_escola;

//Estrutura alunos
typedef struct // nome da estrutura
{
    int id_aluno, id_escola, nif;
    float saldo;
    char nome[80], tipo_utilizador[50], email[80];
} t_estrutura_aluno;

//Estrutura transações
typedef struct // nome da estrutura
{
    int id_transacao, id_aluno;
    char tipo_trasancao[80], morada[50]; // campos
    float valor_transicao;               // estrutura
} t_transacoes;

int menu_inicial();
int menu_de_estatisticas();
int menu_registar_importar();
int menu_registar_mostrar();
int prenche_escola(t_estrutura_escola escola[MAX_ESCOLA], int n_alunos);
void mostrar_escola(t_estrutura_escola escola[MAX_ESCOLA], int n_alunos);
void prenche_alunos(t_estrutura_aluno aluno[MAX_ALUNOS], t_estrutura_escola escola[MAX_ESCOLA], int n_alunos);
void prenche_id_escola(t_estrutura_aluno aluno[MAX_ALUNOS], t_estrutura_escola escola[MAX_ESCOLA], int n_alunos);
void verifica_email(t_estrutura_aluno aluno[MAX_ALUNOS], int pos);
void tipo_utilizador(t_estrutura_aluno aluno[MAX_ALUNOS], int pos);
void mostrar_aluno(t_estrutura_aluno aluno[MAX_ALUNOS]);

int main()
{
    setlocale(LC_ALL, "Portuguese"); //defenir a lingua portuguesa
    t_estrutura_escola escola[MAX_ESCOLA];
    t_estrutura_aluno aluno[MAX_ALUNOS];
    int op;
    int op_estatisticas, op_resgitar_importar;
    int n_alunos = 0, n_escola = 0, n_trasancoes = 0;
    do
    {
        op = NULL;
        system("cls");

        op = menu_inicial();

        switch (op)
        {
        case 1:
            //Registar/importar os dados das escolas
            op_resgitar_importar = menu_registar_importar();
            switch (op_resgitar_importar)
            {
            case 1:
                if (n_alunos < 5)
                {
                    system("cls");
                    n_alunos = prenche_escola(escola, n_alunos);
                                }
                else
                {
                    printf("Maximo de escolas atigindas");
                    getch();
                }
                break;

            case 2:
                if (n_alunos > 0)
                {
                    system("cls");
                    mostrar_escola(escola, n_alunos);
                    break;
                }
                else
                {
                    printf("Insira dados primeiro");
                    getch();
                }
            }
            break;
        case 2:
            op_resgitar_importar = menu_registar_mostrar();
            switch (op_resgitar_importar)
            {
            case 1:
                system("cls");
                prenche_alunos(aluno, escola, n_alunos);
                //mostrar_escola(escola);
                break;

            case 2:
                system("cls");
                mostrar_aluno(aluno);
                break;
            }
            break;

            break;
        case 3:
            //Registar e consultar os dados das transações
            break;
        case 4:
            //Estatísticas
            system("cls");
            op_estatisticas = menu_de_estatisticas();
            switch (op_estatisticas)
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

    } while (op != 0);
    return 0;
}

// INICIO MENU

//FUNÇÃO MENU Inicial
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
        scanf("%d", &op);
        if (op < 0 || op > 6)
        {
            printf("\n Opção invalida");
            sleep(2);
        }
    } while (op < 0 || op > 6);

    return op;
}
//FIM DE MENU Inicial

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
        scanf("%d", &op);
        if (op < 0 || op > 2)
        {
            printf("\n Opção invalida");
            sleep(2);
        }
    } while (op < 0 || op > 2);

    return op;
}

//FIM MENU de Registar/Importar
int menu_registar_mostrar()
{
    int op;
    do
    {

        printf("\n\t\t\t\tMenu Registar/importar");
        printf("\n 1 - Registar");
        printf("\n 2 - Mostrar");
        printf("\n 0 - Voltar atras");
        printf("\n Opção-->");
        scanf("%d", &op);
        if (op < 0 || op > 2)
        {
            printf("\n Opção invalida");
            sleep(2);
        }
    } while (op < 0 || op > 2);

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
    scanf("%d", &op);
    return op;
}
//FIM MENU de estaticas

//FIM MENU

//Inicio Escola

//Função preenche escola
int prenche_escola(t_estrutura_escola escola[MAX_ESCOLA], int n_alunos)
{

    //printf("Introduza a indentificação da escola nº%d: ",n_alunos);
    //scanf("%d", &escola[n_alunos].id_escola);
    printf("Indentifiçao da escola:%d", n_alunos + 1);
    escola[n_alunos].id_escola = n_alunos;
    printf("\nIntroduza nome da escola: ");
    fflush(stdin);
    scanf("%[^\n]", escola[n_alunos].nome);
    printf("Introduza a abreviatura da escola: ");
    fflush(stdin);
    scanf("%[^\n]", escola[n_alunos].abv);
    printf("Introduza o campus: ");
    fflush(stdin);
    scanf("%[^\n]", escola[n_alunos].campus);
    printf("Introduza a localidade da escola: ");
    fflush(stdin);
    scanf("%[^\n]", escola[n_alunos].localidade);
    n_alunos++;
    return n_alunos;
}
//FIM preenche escolas

void mostrar_escola(t_estrutura_escola escola[MAX_ESCOLA], int n_alunos)
{

    for (int posicao = 0; posicao < n_alunos; posicao++)
    {
        printf("\nIdentidade: %d\n", escola[posicao].id_escola + 1);
        printf("Nome: %s\n", escola[posicao].nome);
        printf("Abreviatura: %s\n", escola[posicao].abv);
        printf("Campus: %s\n", escola[posicao].campus);
        printf("Localidade: %s\n", escola[posicao].localidade);
    }
    printf("\nClique em algo para voltar ao menu inicial");
    getch();
}

//FIM ESCOLA

//INICIO ALUNO

//Função preenche so alunos
void prenche_alunos(t_estrutura_aluno aluno[MAX_ALUNOS], t_estrutura_escola escola[MAX_ESCOLA], int n_alunos)
{
    int posicao;
    for (posicao = 0; posicao <= 1; posicao++)
    {
        printf("\nIndentificação do aluno nº:%d ", posicao + 1);
        aluno[posicao].id_aluno = posicao;
        printf("\nIntroduza nome do aluno: ");
        fflush(stdin);
        scanf("%[^\n]", &aluno[posicao].nome);
        prenche_id_escola(aluno, escola, n_alunos);
        verifica_email(aluno, posicao);
        tipo_utilizador(aluno, posicao);
        printf("Introduza o nif:");
        scanf("%d", &aluno[posicao].nif);
        printf("Introduza o saldo:");
        scanf("%f", &aluno[posicao].saldo);
    }
}
//FIM preenche so alunos

//Inicio de mostra o id _escola
void prenche_id_escola(t_estrutura_aluno aluno[MAX_ALUNOS], t_estrutura_escola escola[MAX_ESCOLA], int n_alunos)
{
    int cont;
    int aux;
    do
    {
        for (cont = 0; cont < n_alunos; cont++)
        {
            printf("%d: %s\n", escola[cont].id_escola + 1, escola[cont].abv);
        }
        printf("Introduza a escola que ferquenta:");
        scanf("%d", &aux);
        if (aux < 0 || aux > 6)
        {
            printf("\n Opção invalida");
            sleep(2);
        }
    } while (aux < 0 || aux > 6);
}
//fim de mostra o id escola

//Inicio de verifica email
void verifica_email(t_estrutura_aluno aluno[MAX_ALUNOS], int pos)
{
    char email[80];
    int posicao = 0;
    printf("Introduza email do aluno: ");
    fflush(stdin);
    scanf("%[^\n]", email);

    for (posicao = 0; posicao < strlen(email); posicao++)
    {
        //printf("%c",email[posicao]);
        if (email[posicao] == '@')
            strcpy(aluno[pos].email, email);
    }
    //printf(" %s",email);
}
//Fim de verifica email

//Inicio de tipo_utilizador
void tipo_utilizador(t_estrutura_aluno aluno[MAX_ALUNOS], int pos)
{

    //return "my String";

    int utilizador;
    do
    {

        printf("\n 1 - Estudante");
        printf("\t 2 - Docente");
        printf("\t 3 - Funcionario");
        printf("\n Tipo de utilizador-->");
        scanf("%d", &utilizador);

        switch (utilizador)
        {
        case 1:
            //printf("Estudante");
            strcpy(aluno[pos].tipo_utilizador, "Estudante");
            break;
        case 2:
            strcpy(aluno[pos].tipo_utilizador, "Docente");
            break;
        case 3:
            strcpy(aluno[pos].tipo_utilizador, "Funcionario");
            break;
        default:
            printf("Insira o valor certo");
        }
    } while (utilizador < 0 || utilizador > 3);
}
//Fim de tipo_utilizador

//inicio mostar alunos
void mostrar_aluno(t_estrutura_aluno aluno[MAX_ALUNOS])
{
    int pos;
    char sair;
    for (pos = 0; pos < 1; pos++)
    {
        printf("\nIdentidade: %d", aluno[pos].id_aluno + 1);
        printf("\nId escola: %d", aluno[pos].id_escola + 1);
        printf("\nNome: %s", aluno[pos].nome);
        printf("\nEmail: %s", aluno[pos].email);
        printf("\nTipo de user: %s", aluno[pos].tipo_utilizador);
        printf("\nSaldo:%.2f", aluno[pos].saldo);
        printf("\nNif: %d", aluno[pos].nif);
    }
    printf("\nClique em algo para voltar ao menu inicial");
    getch();
}

// fim de mostrar alunos

//FIM DOS ALUNOS
