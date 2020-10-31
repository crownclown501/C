#include<stdio.h>

int main(void)
{
    int a;
    int cont = 0;
    int cont2 = 0;
    do
    {
        printf("Ingresa un numero \n \t");
        scanf("%d", & a);
        if(a%2==0)
        {
          printf("El numero %d es par \n \n", a);
          cont = cont + 1;
        }
        else
        {
          printf("El numero %d es non \n \n",  a);
          cont2 = cont2 +1;
        }
    }while(a!=0);
    printf("La cantidad de numeros pares dados son %d \n\n", cont-1);
    printf("La cantidad de numeros nones dados son %d \n\n", cont2);
    return 0;
}
