#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

int main()
{

    int a;
    int b = 0;
    do
    {
        printf("a:%d \n", a);
        scanf("%d", &a);
        printf("\nb:%d", b);
        if (b == a)
        {
            printf("aqui");
            b++;
        }
    } while (b == 0);
}