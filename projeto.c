#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>

#define MAX_ESCOLA 2
#define MAX_UTILIZADORES 4
#define MAX_EMAIL 80
#define MAX_TRASANCAO 10
// Estrutura escola
typedef struct
{
    int id_escola;
    char nome[80], abv[5], campus[10], localidade[25];
} t_estrutura_escola;

// Estrutura utilizadores
typedef struct
{
    int id_aluno, id_escola, nif;
    float saldo;
    char nome[80], tipo_utilizador[50], email[80];
} t_estrutura_utilizadores;

// Estrutura transações
typedef struct
{
    int id_transacao, nif_aluno, horas_da_transicao, minutos_da_transicao, segundos_da_transicao, dia_da_transicao, mes_da_trasicao, ano_da_transicao;
    int status; // Os status verificam se a trasanção foi bem sucedida ou não 0-nao sucedida 1-bem sucedida
    char tipo_trasancao[80];
    float valor_transicao;
} t_transacoes;

int menu_inicial();
int menu_de_estatisticas();
int menu_secundario(char opcao1[50], char opcao2[50]);
int menu_registar_mostrar();
char confirmar_saida(char texto[50]);

// Escola
int prenche_escola(t_estrutura_escola escola[MAX_ESCOLA], int n_escola);
void mostrar_escola(t_estrutura_escola escola[MAX_ESCOLA], int n_escola);

// Utilizadores
int prenche_utilizadores(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], t_estrutura_escola escola[MAX_ESCOLA], int n_utilizadores, int n_escola);
int prenche_id_escola(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], t_estrutura_escola escola[MAX_ESCOLA], int n_escola);
void verifica_email(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], int pos);
void tipo_utilizador(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], int pos);
void mostrar_aluno(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], int n_utilizadores);

// Trasações
int preenche_transacoes(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], t_transacoes transacoes[MAX_TRASANCAO], int n_trasacoes, int n_utilizadores);
void tipo_trasancao(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], t_transacoes transacoes[MAX_TRASANCAO], int n_trasacoes, int n_utilizador, int nif_utilizador, int valor);
int verifica_nif(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], int n_utilizadores);
int pagamento(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], int n_utilizador, int nif_utilizador, int valor);
int carregamento(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], int n_utilizador, int nif_utilizador, int valor);
void mostrar_transacao(t_transacoes trasancao[MAX_TRASANCAO], int n_trasacoes);

// Ficheiros
void guadar_dados_escola(t_estrutura_escola utilizador[MAX_UTILIZADORES], int n_utilizador);

int ler_dados_fichiero_escola(t_estrutura_escola utilizador[MAX_UTILIZADORES], int n_utilizador);

int main()
{
    setlocale(LC_ALL, "Portuguese"); // defenir a lingua portuguesa
    t_estrutura_escola escola[MAX_ESCOLA];
    t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES];
    t_transacoes transacoes[MAX_UTILIZADORES];
    int opcao1, opcao2;
    int n_utilizadores = 0, n_escola = 0, n_trasancoes = 0;
    do
    {
        opcao1 = NULL;
        system("cls");

        opcao1 = menu_inicial();

        switch (opcao1)
        {
        case 1:
            // Registar/importar os dados das escolas
            opcao2 = menu_secundario("Registar", "Importar");
            switch (opcao2)
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
            opcao2 = menu_secundario("Registar", "Mostrar");
            switch (opcao2)
            {
            case 1:
                system("cls");
                n_utilizadores = prenche_utilizadores(utilizadores, escola, n_utilizadores, n_escola);
                // mostrar_escola(escola);
                break;

            case 2:
                system("cls");
                mostrar_aluno(utilizadores, n_utilizadores);
                break;
            }
            break;
        case 3:
            // Trasacoes
            opcao2 = menu_secundario("Registar", "Mostrar");
            switch (opcao2)
            {
            case 1:
                system("cls");
                n_trasancoes = preenche_transacoes(utilizadores, transacoes, n_trasancoes, n_utilizadores);
                // mostrar_escola(escola);
                break;

            case 2:
                system("cls");
                mostrar_transacao(transacoes, n_trasancoes);
                break;
            }
            break;
        case 4:
            // Estatísticas
            system("cls");
            opcao2 = menu_de_estatisticas();
            switch (opcao2)
            {
            case 1:
                // Total faturado por escola
                break;
            case 2:
                // Total faturado por escola
                break;
            case 3:
                // Total faturado por escola
                break;
            case 0:
                // voltar atras
                break;
            }
            break;
        case 5:
            opcao2 = menu_secundario("Guardar", "Importar");
            switch (opcao2)
            {
            case 1:

                guadar_dados_escola(escola, n_escola);

                break;

            case 2:
                n_escola = ler_dados_fichiero_escola(escola, n_escola);
            }
            break;
            break;
        case 0:
            // sair
            break;
        }

    } while (opcao1 != 0);
    return 0;
}

// MENU Inicial - 22 LINHAS
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

// MENU de Registar/Importar - 21 LINHAS
int menu_secundario(char opcao1[50], char opcao2[50])
{
    int op;
    do
    {

        printf("\n\t\t\t\tMenu %s/%s", opcao1, opcao2);
        printf("\n 1 - %s", opcao1);
        printf("\n 2 - %s", opcao2);
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

// FUNCÃO CONFIRMAR SAIDA - 6 LINHAS
char confirmar_saida(char texto[50])
{
    char sair;
    printf("\n%s", texto);
    scanf(" %c", &sair);
    return toupper(sair);
}

//  MENU de estaticas - 11 LINHAS
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

// Função preenche escola -19 LINHAS
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

// FUNÇÃO QUE MOSTRA OS DADOS REFERENTES A ESCOLA - 13 LINHAS
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

// INICIO ALUNO

// FUNÇÃO QUE PREENCHE OS UTILIZADOR - 16 LINHAS
int prenche_utilizadores(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], t_estrutura_escola escola[MAX_ESCOLA], int n_utilizadores, int n_escola)
{
    printf("\nIndentificação:nº:%d ", n_utilizadores + 1);
    utilizadores[n_utilizadores].id_aluno = n_utilizadores;
    printf("\nIntroduzao o nome:");
    fflush(stdin);
    scanf("%[^\n]", utilizadores[n_utilizadores].nome);
    utilizadores[n_utilizadores].id_escola = prenche_id_escola(utilizadores, escola, n_escola);
    verifica_email(utilizadores, n_utilizadores);
    tipo_utilizador(utilizadores, n_utilizadores);
    printf("Introduza o nif:");
    scanf("%d", &utilizadores[n_utilizadores].nif);
    printf("Introduza o saldo:");
    scanf("%f", &utilizadores[n_utilizadores].saldo);
    n_utilizadores++;
    return n_utilizadores++;
}

// FUNÇÃO QUE E RESPONSAVEL POR MOSTRAR OS IDS E ABREVIATURAS JA REGISTADAS NO PROGRAMA
// PARA O UTLIZADOR PODER ESCOLHER -20 LINHAS
int prenche_id_escola(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], t_estrutura_escola escola[MAX_ESCOLA], int n_escola)
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

// FUNÇÃO RESPONSAVEL POR VERIFICAR O EMAIL DE CADA UTILIZADOR
// E VERIFICAR SE ESTA BEM INTRODUZIDO - 23 LINHAS
void verifica_email(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], int posicao_aluno)
{
    char email[80];
    int posicao = 0, email_verdadeiro = 0;
    do
    {
        printf("\nInsira o email:");
        fflush(stdin);
        scanf("%[^\n]", email);

        for (posicao = 0; posicao < strlen(email); posicao++)
        {
            if (email[posicao] == '@')
            {
                strcpy(utilizadores[posicao_aluno].email, email);
                email_verdadeiro = 1;
            }
        }
        if (email_verdadeiro == 0)
        {
            printf("\nEmail invalido!!!!!");
        }
    } while (email_verdadeiro == 0);
}

// FUNCÃO QUE SERVE PARA O UTILIZADOR PODER ESCOLHER O SEU TIPO DE UTILIZADOR
// PARA QUE O MESMO NAO SE POSSA ENGANAR - 25 LINHAS
void tipo_utilizador(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], int posicao_aluno)
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
            strcpy(utilizadores[posicao_aluno].tipo_utilizador, "Estudante");
            break;
        case 2:
            strcpy(utilizadores[posicao_aluno].tipo_utilizador, "Docente");
            break;
        case 3:
            strcpy(utilizadores[posicao_aluno].tipo_utilizador, "Funcionario");
            break;
        default:
            printf("Insira o valor certo");
        }
    } while (utilizador < 0 || utilizador > 3);
}

// FUNÇÃO RESPONSAVEL POR CARREGAR O TIPO DE UTILIZADORES
void mostrar_aluno(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], int n_utilizadores)
{
    int posicao;
    for (posicao = 0; posicao < n_utilizadores; posicao++)
    {
        printf("\n\nIdentidade: %d", utilizadores[posicao].id_aluno + 1);
        printf("\nId escola: %d", utilizadores[posicao].id_escola);
        printf("\nNome: %s", utilizadores[posicao].nome);
        printf("\nEmail: %s", utilizadores[posicao].email);
        printf("\nTipo de user: %s", utilizadores[posicao].tipo_utilizador);
        printf("\nSaldo:%.2f", utilizadores[posicao].saldo);
        printf("\nNif: %d", utilizadores[posicao].nif);
    }
    printf("\nClique em algo para voltar ao menu inicial");
    getch();
}

// FUNÇÃO REPONSAVEL POR CARREGAR O TIPO DE UTILIZADORES - 25 LINHAS
int preenche_transacoes(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], t_transacoes transacoes[MAX_TRASANCAO], int n_trasacoes, int n_utilizadores)
{
    time_t now;
    printf("Indentifiçao da trasação:%d", n_trasacoes + 1);
    transacoes[n_trasacoes].id_transacao = n_trasacoes;
    transacoes[n_trasacoes].nif_aluno = verifica_nif(utilizadores, n_utilizadores);
    printf("\nIntroduza o valor:");
    scanf("%f", &transacoes[n_trasacoes].valor_transicao);
    tipo_trasancao(utilizadores, transacoes, n_trasacoes, n_utilizadores, transacoes[n_trasacoes].nif_aluno, transacoes[n_trasacoes].valor_transicao);

    // recebe o valor das horas do
    time(&now);
    transacoes[n_trasacoes].horas_da_transicao = localtime(&now)->tm_hour;  // recebe a horas entre o intervalo (0-23)
    transacoes[n_trasacoes].minutos_da_transicao = localtime(&now)->tm_min; // recebe a horas entre o intervalo (0-23)
    transacoes[n_trasacoes].segundos_da_transicao = localtime(&now)->tm_sec;

    // valor da data atual
    transacoes[n_trasacoes].dia_da_transicao = localtime(&now)->tm_mday;        // recebe o dia do ano (1-31)
    transacoes[n_trasacoes].mes_da_trasicao = localtime(&now)->tm_mon + 1;      // como a função copmecça a contar do mes 0 temos de somar +1 para dar o mes atual
    transacoes[n_trasacoes].ano_da_transicao = localtime(&now)->tm_year + 1900; // e preciso de somar 1900 pois esta função so começa a contar a partir do ano 1900
    printf("\nData : %02d/%02d/%d", transacoes[n_trasacoes].dia_da_transicao, transacoes[n_trasacoes].mes_da_trasicao, transacoes[n_trasacoes].ano_da_transicao);
    printf("\nHoras: %02d:%02d:%02d", transacoes[n_trasacoes].horas_da_transicao, transacoes[n_trasacoes].minutos_da_transicao, transacoes[n_trasacoes].segundos_da_transicao);
    printf("\nstatus:%d", transacoes[n_trasacoes].status);
    getch();
    n_trasacoes++;
    return n_trasacoes;
}

// FUNÇÃO RESPONSAVEL POR VERIFICAR SE O NIF JA EXISTE REGISTADO- 25 LINHAS
int verifica_nif(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], int n_utilizadores)
{
    int posicao, nif_trasacao, verifica_aluno = 0;
    char confirmar;
    do
    {
        printf("\nIntroduza o nif:");
        scanf("%d", &nif_trasacao);
        for (posicao = 0; posicao < n_utilizadores; posicao++)
        {
            if (nif_trasacao == utilizadores[posicao].nif)
            {
                printf("Nome do aluno: %s", utilizadores[posicao].nome);
                printf("\nNif do aluno: %d", utilizadores[posicao].nif);
                confirmar = confirmar_saida("Este e o nif?(S/N)");
                if (confirmar == 'S')
                    verifica_aluno = 1;
            }
        }
        if (verifica_aluno == 0)
        {
            printf("Introduza um nif valido");
        }
    } while (verifica_aluno == 0 && confirmar != 'S');
    return nif_trasacao;
}

// FUNÇÃO QUE E REPONSAVEL POR VERIFICAR SE O UTILIZADOR QUER CARREGAR OU PAGAR E PROCEDER AS OPERAÇÕES DA MESMA - 23 LINHAS
void tipo_trasancao(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], t_transacoes transacoes[MAX_TRASANCAO], int n_trasacoes, int n_utilizador, int nif_utilizador, int valor)
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

            strcpy(transacoes[n_trasacoes].tipo_trasancao, "Pagamento");
            transacoes[n_trasacoes].status = pagamento(utilizadores, n_utilizador, nif_utilizador, valor);
            break;

        case 2:

            strcpy(transacoes[n_trasacoes].tipo_trasancao, "Carregamento");
            transacoes[n_trasacoes].status = carregamento(utilizadores, n_utilizador, nif_utilizador, valor);
            break;

        default:
            printf("Insira o valor certo");
        }
    } while (trasacao < 0 || trasacao > 2);
}

// FUNÇÃO CASO O UTILIZADOR DESEJE PAGAR
//  ESTA FUNÇÃO E UM INT POIS ELA RETORNA 1 OU 0 CONSOANTE CORRA O PROCESSO
int pagamento(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], int n_utilizador, int nif_utilizador, int valor)
{
    int indice, status = 0;

    for (indice = 0; indice < n_utilizador; indice++)
    {
        if (nif_utilizador == utilizadores[indice].nif)
        {
            if (valor > utilizadores[indice].saldo)
            {
                printf("Valor Insuficiente");
            }
            else
            {
                utilizadores[indice].saldo = utilizadores[indice].saldo - valor;
                status = 1;
                printf("Pagamento com sucesso");
            }
        }
    }

    return status;
}

// FUNÇÃO CASO O UTILIZADOR DESEJE CARREGAR
//  ESTA FUNÇÃO E UM INT POIS ELA RETORNA 1 OU 0 CONSOANTE CORRA O PROCESSO
int carregamento(t_estrutura_utilizadores utilizadores[MAX_UTILIZADORES], int n_utilizador, int nif_utilizador, int valor)
{
    int indice, status = 0;

    for (indice = 0; indice < n_utilizador; indice++)
    {
        if (nif_utilizador == utilizadores[indice].nif)
        {
            utilizadores[indice].saldo = utilizadores[indice].saldo + valor;
            status = 1;
        }
    }
    if (status == 0)
        printf("Ocorreu um erro");
    return status;
}

// FUNÇÃO QUE MOSTRA AS TRASAÇÕES FEITAS
void mostrar_transacao(t_transacoes trasancao[MAX_TRASANCAO], int n_trasacoes)
{

    for (int posicao = 0; posicao < n_trasacoes; posicao++)
    {
        // caso os status sejam 0 quer dizer que ocorreu um erro
        if (trasancao[posicao].status == 1)
        {
            printf("\nIdentificação da trasação: %d", trasancao[posicao].id_transacao + 1);
            printf("\nNif do aluno: %d", trasancao[posicao].nif_aluno);
            printf("\nValor: %.2f", trasancao[posicao].valor_transicao);
            printf("\nData : %02d:%02d:%d", trasancao[posicao].dia_da_transicao, trasancao[posicao].mes_da_trasicao, trasancao[posicao].ano_da_transicao);
            printf("\nHoras: %02d/%02d/%02d\n", trasancao[posicao].horas_da_transicao, trasancao[posicao].minutos_da_transicao, trasancao[posicao].segundos_da_transicao);
        }
    }
    printf("\nClique em algo para voltar ao menu inicial");
    getch();
}

// FICHEIROS

void guadar_dados_escola(t_estrutura_escola utilizador[MAX_UTILIZADORES], int n_utilizador)
{
    FILE *ficheiro;

    ficheiro = fopen("dados.dat", "wb");
    if (ficheiro == NULL)
    {
        printf("Ficheiro Inexistente");
    }
    else
    {
        fwrite(utilizador, sizeof(t_estrutura_escola), n_utilizador, ficheiro);
        fclose(ficheiro);
        printf("Guadado com sucesso");
        getch();
    }
}

int ler_dados_fichiero_escola(t_estrutura_escola utilizador[MAX_UTILIZADORES], int n_utilizador)
{
    int numero_bytes;
    FILE *ficheiro;
    ficheiro = fopen("dados.dat", "rb");
    if (ficheiro == NULL)
    {
        printf("Ficheiro Inexistente");
    }
    else
    {
        fseek(ficheiro, 0L, SEEK_END);
        numero_bytes = ftell(ficheiro);
        n_utilizador = numero_bytes / sizeof(t_estrutura_escola);
        fseek(ficheiro, 0L, SEEK_SET);
        fread(utilizador, sizeof(t_estrutura_escola), n_utilizador, ficheiro);

        fclose(ficheiro);
    }
    // printf("N aluno:%d", n_utilizador);
    printf("\nClique num caracter:");
    getch();
    return n_utilizador;
}
