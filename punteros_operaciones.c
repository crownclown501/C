#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 5

void ingresar(int p[],int size)
{
    int i;
    for (i=0;i<size;i++)
    {
        printf("array[%d]\n",i+1);
        scanf("%d",&*(p+i));
    }
}

void sumar(int p[],int size)
{
    int x=0,i;
    for (i=0;i<size;i++)
    {
        x=*(p+i)+x;
    }
    printf ("la suma es %d\n",x);
}

void mayor(int p[],int size)
{
    int mayor = p[0];

    for (int i = 0; i < n; ++i) 
    {
        mayor = mayor < *(p+i) ? *(p+i) : mayor;
    }
    printf("el valor mayor del arreglo es: %d\n",mayor);
}

void menor(int p[],int size)
{
    int menor = p[0];

    for (int i = 0; i < n; ++i) 
    {
        menor = menor > p[i] ? p[i] : menor;
    }
    printf("el valor menor del arreglo es: %d\n",menor);
}

int main ()
{
    int p[n];
    ingresar(p,n);
    sumar(p,n);
    mayor(p,n);
    menor(p,n);
    return 0;
}
