#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char Cadena[100];
int main()
{   
        int i,contador=0;
        printf("Ingrese la cadena\n");
        fgets(Cadena, 100, stdin);
        i = strlen(Cadena);
        printf("Primer cadena invertida: ");
        for (int k = 0; k <= i; k++)
        {
            printf("%c", Cadena[i - k]);
        }
        printf("\n\n");
        for(int j=0;j<i;j++)
        {
            printf("Cadena[%d] = %c\n",j+1,Cadena[j]);
        }
        for(int j=0;j<i;j++)
        {
            if (((Cadena[j]==' ' )|| (Cadena[j]=='\n')) || (Cadena[j]=='\0'))
            {
               contador++; 
            }
        }
        printf("numero de palabras es: %d\n ",contador);
}
