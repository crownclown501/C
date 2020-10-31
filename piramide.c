#include<stdio.h>
#include<stdlib.h>
int i,j,n=9;
int main(void)
{
    for(i=1;i<=n;i++)       //i=1
    { printf(".");
        for(j=0;j<n-i;j++)  //j=0,1,2,3,..,8  primero entra en el j y lo incrementa hasta que j ya no sea menor a n-i en este caso 8
        { 
            printf(" ");    // imprime j espacios " "
        } 
        for (int k=0;k<2*i-1;k++)  // cuenta la cantidad de asteriscos en una fila k=0   por ejemplo cuando k vale 0 entra e imprime la 
        {                           // x pero despues entra de nuevo y k vale 1 compara y dice 1<que dos por i que vale ahorita 1 menos 1 sale automaticamente del programa 
           printf("x");           //x
        }
       putchar('\n');          
    }  
   printf("\n"); //salto de linea para que no este amontonado con lo que aprece en mi compilador al finalizar 
}
