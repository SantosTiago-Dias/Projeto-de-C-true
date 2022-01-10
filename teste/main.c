#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>


void idc(char *email);
int main()
{

    char email;
    idc(&email);
    printf("aqui\n");
    printf("%s",email);
    return 0;
}
void idc(char *email)
{
    printf("Introduza email do aluno: ");
    fflush(stdin);
    scanf("%[^\n]",&email);

    for (int i=0; i<80; i++)
    {
        if(email[i]=='@')
        {
            *email;
        }

    }
}
