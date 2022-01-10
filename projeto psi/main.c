#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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
} estrutura_escola;

//Estrutura alunos
typedef struct // nome da estrutura
{
    int id_aluno, id_escola, nif;
    float saldo;
    char nome[80], tipo_utilizador[50], email[80];
} estrutura_aluno;

//Estrutura transa��es
typedef struct // nome da estrutura
{
    int id_transacao, id_aluno;
    char tipo_trasancao[80], morada[50]; // campos
    float valor_transicao;               // estrutura
} transacao;

int menu_inicial();
int menu_de_estatisticas();
int menu_registar_importar();
int menu_registar_mostrar();
int ler_numeros(char texto[80], int valor);
char ler_dados(char texto, int tamanho);
void prenche_escola(estrutura_escola escola[MAX_ESCOLA]);
void mostrar_escola(estrutura_escola escola[MAX_ESCOLA]);
void prenche_alunos(estrutura_aluno aluno[MAX_ALUNOS], estrutura_escola escola[MAX_ESCOLA]);
void prenche_id_escola(estrutura_aluno aluno[MAX_ALUNOS], estrutura_escola escola[MAX_ESCOLA], int pos);
void verifica_email(estrutura_aluno aluno[MAX_ALUNOS], int pos);
void tipo_utilizador(estrutura_aluno aluno[MAX_ALUNOS], int pos);
void mostrar_aluno(estrutura_aluno aluno[MAX_ALUNOS]);

int main()
{
    setlocale(LC_ALL, "Portuguese"); //defenir a lingua portuguesa
    estrutura_escola escola[MAX_ESCOLA];
    estrutura_aluno aluno[MAX_ALUNOS];
    int op;
    int op_estatisticas, op_resgitar_importar;
    int a = 0;
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
                system("cls");
                prenche_escola(escola);
                a++;
                //mostrar_escola(escola);
                break;

            case 2:
                if (a != 0)
                {
                    system("cls");
                    mostrar_escola(escola);
                    break;
                }
                else
                {
                    printf("Insira dados primeiro");
                    sleep(2);
                }
            }
            break;
        case 2:
            op_resgitar_importar = menu_registar_mostrar();
            switch (op_resgitar_importar)
            {
            case 1:
                system("cls");
                prenche_alunos(aluno, escola);
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
            //Registar e consultar os dados das transa��es
            break;
        case 4:
            //Estat�sticas
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

//FUN��O MENU Inicial
int menu_inicial()
{
    int op;

    do
    {
        printf("\n\t\t\t\tMenu de opc�es");
        printf("\n 1 - Registar ou importar os dados das escolas");
        printf("\n 2 - Registar e consultar os dados dos utilizadores");
        printf("\n 3 - Registar e consultar os dados das transa��es");
        printf("\n 4 - Estat�sticas");
        printf("\n 5 - Guardar e ler de ficheiros bin�rios os dados da aplica��o");
        printf("\n 0 - Sair");
        printf("\n Op��o-->");
        scanf("%d", &op);
        if (op < 0 || op > 6)
        {
            printf("\n Op��o invalida");
            sleep(2);
        }
    } while (op < 0 || op > 6);

    return op;
}
//FIM DE MENU Inicial

//FUN��O MENU de Registar/Importar
int menu_registar_importar()
{
    int op;
    do
    {

        printf("\n\t\t\t\tMenu Registar/importar");
        printf("\n 1 - Registar");
        printf("\n 2 - Importar");
        printf("\n 0 - Voltar atras");
        printf("\n Op��o-->");
        scanf("%d", &op);
        if (op < 0 || op > 2)
        {
            printf("\n Op��o invalida");
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
        printf("\n Op��o-->");
        scanf("%d", &op);
        if (op < 0 || op > 2)
        {
            printf("\n Op��o invalida");
            sleep(2);
        }
    } while (op < 0 || op > 2);

    return op;
}
//FIM MENU de Registar/Importar

//FUN��O MENU de estaticas
int menu_de_estatisticas()
{
    int op;
    printf("\n\t\t\t\tMenu de Estat�sticas");
    printf("\n 1 - Total faturado por escola");
    printf("\n 2 - Percentagem de transa��es por escola");
    printf("\n 3 - Total de transa��es (pagamentos) entre duas datas (horizonte temporal) por tipo de utilizador");
    printf("\n 0 - Voltar atras");
    printf("\n Op��o-->");
    scanf("%d", &op);
    return op;
}
//FIM MENU de estaticas

//FIM MENU

//Inicio da fun�oes ler op��es
/*int ler_numeros(char texto[80], int valor)
{

    int temp_num;
    do
    {
        scanf("%d", &temp_num);

        if (temp_num < num_min || temp_num > num_max)
        {
            printf("\n Valor Invalido. Tente novamente: ");
        }

    } while (temp_num < num_min || temp_num > num_max);
    return temp_num;
}*/

char ler_dados(char texto, int tamanho)
{
    char valores[tamanho];
    printf("\n %c", texto);
    fflush(stdin);
    scanf("%[^\n]", valores);
    printf("\n %c", valores);
}

//Inicio de verifica email
void verifica_email(estrutura_aluno aluno[MAX_ALUNOS], int pos)
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
void tipo_utilizador(estrutura_aluno aluno[MAX_ALUNOS], int pos)
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
//Fim da fun�oes ler op��es
//Inicio Escola

//Fun��o preenche escola
void prenche_escola(estrutura_escola escola[MAX_ESCOLA])
{
    int pos;
    for (pos = 0; pos <= MAX_ESCOLA; pos++)
    {
        //printf("Introduza a indentifica��o da escola n�%d: ",pos);
        //scanf("%d", &escola[pos].id_escola);
        printf("\nIndentifica��o da escola:%d", pos + 1);
        escola[pos].id_escola = pos;
        escola[pos].nome = ler_dados("Introduza a nome da escola:",80);

        printf("Introduza a abreviatura da escola: ");
        fflush(stdin);
        scanf("%[^\n]", escola[pos].abv);
        printf("Introduza o campus: ");
        fflush(stdin);
        scanf("%[^\n]", escola[pos].campus);
        printf("Introduza a localidade da escola: ");
        fflush(stdin);
        scanf("%[^\n]", escola[pos].localidade);
    }
}
//FIM preenche escolas

void mostrar_escola(estrutura_escola escola[MAX_ESCOLA])
{

    for (int i = 0; i <= MAX_ESCOLA; i++)
    {
        printf("Identidade: %d\n", escola[i].id_escola);
        printf("Nome: %s\n", escola[i].nome);
        printf("Abreviatura: %s\n", escola[i].abv);
        printf("Campus: %s\n", escola[i].campus);
        printf("Localidade: %s\n", escola[i].localidade);
    }
    printf("\nClique em algo para voltar ao menu inicial");
    getch();
}

//FIM ESCOLA

//INICIO ALUNO

//Fun��o preenche so alunos
void prenche_alunos(estrutura_aluno aluno[MAX_ALUNOS], estrutura_escola escola[MAX_ESCOLA])
{
    int posicao;
    for (posicao = 0; posicao <= 1; posicao++)
    {
        printf("\nIndentifica��o do aluno n�:%d ", posicao + 1);
        aluno[posicao].id_aluno = posicao;
        printf("\nIntroduza nome do aluno: ");
        fflush(stdin);
        scanf("%[^\n]", &aluno[posicao].nome);
        prenche_id_escola(aluno, escola, posicao);
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
void prenche_id_escola(estrutura_aluno aluno[MAX_ALUNOS], estrutura_escola escola[MAX_ESCOLA], int pos)
{
    int cont;
    int aux;
    do
    {
        for (cont = 0; cont <= MAX_ESCOLA; cont++)
        {
            printf("%d: %s\n", escola[cont].id_escola + 1, escola[cont].abv);
        }
        printf("Introduza a escola que ferquenta:");
        scanf("%d", &aux);
        if (aux < 0 || aux > 6)
        {
            printf("\n Op��o invalida");
            sleep(2);
        }
    } while (aux < 0 || aux > 6);
    aluno[pos].id_escola = aux;
}
//fim de mostra o id escola

//inicio mostar alunos
void mostrar_aluno(estrutura_aluno aluno[MAX_ALUNOS])
{
    int pos;
    char sair;
    for (pos = 0; pos <= 1; pos++)
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
