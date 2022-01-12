#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>

#define MAX_ESCOLA 2
#define MAX_ALUNOS 4
#define MAX_EMAIL 80
#define MAX_TRASANCAO 10
//Estrutura escola
typedef struct
{
    int id_escola;
    char nome[80], abv[5], campus[10], localidade[25];
} t_estrutura_escola;

//Estrutura alunos
typedef struct
{
    int id_aluno, id_escola, nif;
    float saldo;
    char nome[80], tipo_utilizador[50], email[80];
} t_estrutura_alunos;

//Estrutura transações
typedef struct
{
    int id_transacao, nif_aluno, horas_da_transicao, minutos_da_transicao, segundos_da_transicao, dia_da_transicao, mes_da_trasicao, ano_da_transicao;
    char tipo_trasancao[80], morada[50];
    float valor_transicao;
} t_transacoes;

int menu_inicial();
int menu_de_estatisticas();
int menu_registar_importar();
int menu_registar_mostrar();
int prenche_escola(t_estrutura_escola escola[MAX_ESCOLA], int n_escola);
void mostrar_escola(t_estrutura_escola escola[MAX_ESCOLA], int n_escola);
int prenche_alunos(t_estrutura_alunos alunos[MAX_ALUNOS], t_estrutura_escola escola[MAX_ESCOLA], int n_alunos, int n_escola);
int prenche_id_escola(t_estrutura_alunos alunos[MAX_ALUNOS], t_estrutura_escola escola[MAX_ESCOLA], int n_escola);
void verifica_email(t_estrutura_alunos alunos[MAX_ALUNOS], int pos);
void tipo_utilizador(t_estrutura_alunos alunos[MAX_ALUNOS], int pos);
void mostrar_aluno(t_estrutura_alunos alunos[MAX_ALUNOS], int n_alunos);
int preenche_transacoes(t_estrutura_alunos alunos[MAX_ALUNOS], t_transacoes transacoes[MAX_TRASANCAO], int n_trasacoes, int n_alunos);
void tipo_trasancao(t_transacoes transacoes[MAX_TRASANCAO], int n_trasacoes);
int verifica_nif(t_estrutura_alunos alunos[MAX_ALUNOS], int n_alunos);

int main()
{
    setlocale(LC_ALL, "Portuguese"); //defenir a lingua portuguesa
    t_estrutura_escola escola[MAX_ESCOLA];
    t_estrutura_alunos alunos[MAX_ALUNOS];
    t_transacoes transacoes[MAX_ALUNOS];
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
                if (n_escola < MAX_ESCOLA)
                {
                    system("cls");
                    n_escola = prenche_escola(escola, n_escola);
                }
                else
                {
                    printf("Maximo de escolas atigindas");
                    getch();
                }
                break;

            case 2:
                if (n_escola > 0)
                {
                    system("cls");
                    mostrar_escola(escola, n_escola);
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
                n_alunos = prenche_alunos(alunos, escola, n_alunos, n_escola);
                //mostrar_escola(escola);
                break;

            case 2:
                system("cls");
                mostrar_aluno(alunos, n_alunos);
                break;
            }
            break;
        case 3:
            //Trasacoes
            op_resgitar_importar = menu_registar_mostrar();
            switch (op_resgitar_importar)
            {
            case 1:
                system("cls");
                n_trasancoes = preenche_transacoes(alunos, transacoes, n_trasancoes, n_alunos);
                //mostrar_escola(escola);
                break;

            case 2:
                system("cls");
                mostrar_aluno(alunos, n_alunos);
                break;
            }
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
int prenche_escola(t_estrutura_escola escola[MAX_ESCOLA], int n_escola)
{

    printf("Indentifiçao da escola:%d", n_escola + 1);
    escola[n_escola].id_escola = n_escola;
    printf("\nIntroduza nome da escola: ");
    fflush(stdin);
    scanf("%[^\n]", escola[n_escola].nome);
    printf("Introduza a abreviatura da escola: ");
    fflush(stdin);
    scanf("%[^\n]", escola[n_escola].abv);
    printf("Introduza o campus: ");
    fflush(stdin);
    scanf("%[^\n]", escola[n_escola].campus);
    printf("Introduza a localidade da escola: ");
    fflush(stdin);
    scanf("%[^\n]", escola[n_escola].localidade);
    n_escola++;
    return n_escola;
}
//FIM preenche escolas

void mostrar_escola(t_estrutura_escola escola[MAX_ESCOLA], int n_escola)
{

    for (int posicao = 0; posicao < n_escola; posicao++)
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
int prenche_alunos(t_estrutura_alunos alunos[MAX_ALUNOS], t_estrutura_escola escola[MAX_ESCOLA], int n_alunos, int n_escola)
{
    printf("\nIndentificação do aluno nº:%d ", n_alunos + 1);
    alunos[n_alunos].id_aluno = n_alunos;
    printf("\nIntroduza nome do aluno: ");
    fflush(stdin);
    scanf("%[^\n]", alunos[n_alunos].nome);
    alunos[n_alunos].id_escola = prenche_id_escola(alunos, escola, n_escola);
    verifica_email(alunos, n_alunos);
    tipo_utilizador(alunos, n_alunos);
    printf("Introduza o nif:");
    scanf("%d", &alunos[n_alunos].nif);
    printf("Introduza o saldo:");
    scanf("%f", &alunos[n_alunos].saldo);
    n_alunos++;
    return n_alunos++;
}
//FIM preenche so alunos

//Inicio de mostra o id _escola
int prenche_id_escola(t_estrutura_alunos alunos[MAX_ALUNOS], t_estrutura_escola escola[MAX_ESCOLA], int n_escola)
{
    int cont;
    int aux;
    do
    {

        for (cont = 0; cont < n_escola; cont++)
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
    return aux;
}
//fim de mostra o id escola

//Inicio de verifica email
void verifica_email(t_estrutura_alunos alunos[MAX_ALUNOS], int posicao_aluno)
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
            strcpy(alunos[posicao_aluno].email, email);
    }
    //printf(" %s",email);
}
//Fim de verifica email

//Inicio de tipo_utilizador
void tipo_utilizador(t_estrutura_alunos alunos[MAX_ALUNOS], int posicao_aluno)
{
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
            strcpy(alunos[posicao_aluno].tipo_utilizador, "Estudante");
            break;
        case 2:
            strcpy(alunos[posicao_aluno].tipo_utilizador, "Docente");
            break;
        case 3:
            strcpy(alunos[posicao_aluno].tipo_utilizador, "Funcionario");
            break;
        default:
            printf("Insira o valor certo");
        }
    } while (utilizador < 0 || utilizador > 3);
}
//Fim de tipo_utilizador

//inicio mostar alunos
void mostrar_aluno(t_estrutura_alunos alunos[MAX_ALUNOS], int n_alunos)
{
    int posicao;
    for (posicao = 0; posicao < n_alunos; posicao++)
    {
        printf("\n\nIdentidade: %d", alunos[posicao].id_aluno);
        printf("\nId escola: %d", alunos[posicao].id_escola);
        printf("\nNome: %s", alunos[posicao].nome);
        printf("\nEmail: %s", alunos[posicao].email);
        printf("\nTipo de user: %s", alunos[posicao].tipo_utilizador);
        printf("\nSaldo:%.2f", alunos[posicao].saldo);
        printf("\nNif: %d", alunos[posicao].nif);
    }
    printf("\nClique em algo para voltar ao menu inicial");
    getch();
}

int preenche_transacoes(t_estrutura_alunos alunos[MAX_ALUNOS], t_transacoes transacoes[MAX_TRASANCAO], int n_trasacoes, int n_alunos)
{
    time_t now;
    printf("Indentifiçao da trasação:%d", n_trasacoes + 1);
    transacoes[n_trasacoes].id_transacao = n_trasacoes;
    transacoes[n_trasacoes].nif_aluno = verifica_nif(transacoes, n_alunos);
    tipo_trasancao(transacoes, n_trasacoes);
    printf("\nIntroduza o valor:");
    scanf("%f", &transacoes[n_trasacoes].valor_transicao);
    // Obtain current time
    // recebe o valor das horas do
    time(&now);
    transacoes[n_trasacoes].horas_da_transicao = localtime(&now)->tm_hour;  //recebe a horas entre o intervalo (0-23)
    transacoes[n_trasacoes].minutos_da_transicao = localtime(&now)->tm_min; //recebe a horas entre o intervalo (0-23)
    transacoes[n_trasacoes].segundos_da_transicao = localtime(&now)->tm_sec;

    transacoes[n_trasacoes].dia_da_transicao = localtime(&now)->tm_mday;        // recebe o dia do ano (1-31)
    transacoes[n_trasacoes].mes_da_trasicao = localtime(&now)->tm_mon + 1;      // como a função copmecça a contar do mes 0 temos de somar +1 para dar o mes atual
    transacoes[n_trasacoes].ano_da_transicao = localtime(&now)->tm_year + 1900; // e preciso de somar 1900 pois esta função so começa a contar a partir do ano 1900
    printf("\nData : %02d/%02d/%d\n", transacoes[n_trasacoes].dia_da_transicao, transacoes[n_trasacoes].mes_da_trasicao, transacoes[n_trasacoes].ano_da_transicao);
    printf("\nHoras: %02d:%02d:%02d", transacoes[n_trasacoes].horas_da_transicao, transacoes[n_trasacoes].minutos_da_transicao, transacoes[n_trasacoes].segundos_da_transicao);
    getch();
    n_trasacoes++;
    return n_trasacoes;
}

//Verifica qual se o utilizador que fazer um pagamento ou carregamento
void tipo_trasancao(t_transacoes transacoes[MAX_TRASANCAO], int n_trasacoes)
{
    int trasacao;
    do
    {

        printf("\n 1 - Pagamento");
        printf("\t 2 - Carregamento");
        printf("\n Tipo de utilizador-->");
        scanf("%d", &trasacao);

        switch (trasacao)
        {
        case 1:
            //printf("Estudante");
            strcpy(transacoes[n_trasacoes].tipo_trasancao, "Pagamento");
            break;
        case 2:
            strcpy(transacoes[n_trasacoes].tipo_trasancao, "Carregamento");
            break;
        default:
            printf("Insira o valor certo");
        }
    } while (trasacao < 0 || trasacao > 2);
}

//Verifica se o nif que o utilizador inserio
int verifica_nif(t_estrutura_alunos alunos[MAX_ALUNOS], int n_alunos)
{
    int posicao, nif_trasacao;
    int verifica_aluno;
    char confirmar;
    do
    {
        printf("Introduza o nif do estudante:");
        scanf("%d", &nif_trasacao);
        for (posicao = 0; posicao < n_alunos; posicao++)
        {
            if (nif_trasacao == alunos[posicao].nif)
            {
                printf("Nome do aluno: %s", alunos[posicao].nome);
                printf("\nNif do aluno: %d", alunos[posicao].nif);
                printf("\nÉ este aluno(S/N)");
                scanf(" %c", confirmar);
                verifica_aluno = 1;
            }
        }

    } while ((confirmar != 's' || confirmar != 'S') && verifica_aluno != 0);
}

// fim de mostrar alunoss

//FIM DOS alunosS
