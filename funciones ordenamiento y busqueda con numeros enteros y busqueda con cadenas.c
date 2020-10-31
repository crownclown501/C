#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define _TAMAN 8
#define _TAMANC 80
int opc,opc1,opc2,opc4,opc5,cont,b;
int opc3,opc6;
void numerosporteclado(int x[],int taman);
void numerosaleatorios(int x[],int taman);
void ordenamientoInsercion(int x[],int taman);
void ordenamientoBurbuja(int x[], int taman);
void ordenamientoSeleccion(int x[],int taman );
void ordshell(int x[],int taman);
void busqueda_binaria(int x[],int taman);
void busqueda_secuencial(int x[],int taman);
void chain (char a[],int tamanc);
void busqueda_secuencial_cad(char a[],int tamanc);
void impri(int x[],int taman);

int main ()
{
    int x[_TAMAN];
    char a[_TAMANC];
    printf("MENU:\n1)meter datos enteros por teclado\n2)generar numeros aleatorios\n3)Cadena\n4)salir\n");
	scanf("%d",&opc);
    switch (opc)
    {
    case 1:
        
        printf("numeros dados sin ordenar\n");
        numerosporteclado(x, _TAMAN);
        printf("MENU:\n1)Ordenamiento\n2)busqueda");
        scanf("%d",&b);
        switch (b)
        {
        case 1:
        printf("MENU:\n1)ordenamiento Insercion\n2)ordenamiento burbuja\n3)ordenamiento seleccion\n4)shell\n");
        scanf("%d",&opc1);
        switch (opc1)
        {
        case  1:impri(x, _TAMAN );
        printf("############ Ordenando con Insercion ############\n");
        ordenamientoInsercion(x, _TAMAN);
        printf("Numeros Ordenados");
        impri(x, _TAMAN); 
        break;

        case 2 :impri(x, _TAMAN );
            printf("############ Ordenando con Burbuja ############\n");
            
            ordenamientoBurbuja(x, _TAMAN);
            printf("Numeros Ordenados");
            
            impri(x, _TAMAN);
        break;
            case 3:impri(x, _TAMAN );
            printf("############ Ordenando seleccion ############\n");
            ordenamientoSeleccion(x,_TAMAN);
            printf("Numeros Ordenados");
            
            impri(x, _TAMAN);
            break;
            case 4:impri(x, _TAMAN );
            printf("############ Ordenando shell ############\n");
            ordshell(x,_TAMAN);
            printf("Numeros Ordenados");
            
            impri(x, _TAMAN);
            break;
        
        default:
            break;  
        }

        break;

        case 2:
        printf("MENU:\n1)busqueda binaria\n2)busqueda secuencial\n");
        scanf("%d",&opc3);
        switch (opc3)
        {
        case 1:
            busqueda_binaria(x,_TAMAN);
            break;
            case 2:
            busqueda_secuencial(x,_TAMAN);
            break;
        
        default:
            break;
        }

        default:
            break;
        }
        break;
    case 2:
        printf("numeros dados sin ordenar\n");
        numerosaleatorios(x,_TAMAN);
        impri(x,_TAMAN);
        printf("MENU:\n1)Ordenamiento\n2)busqueda\n");
        scanf("%d",&opc4);
        switch (opc4)
        {
        case 1:
        printf("MENU:\n1)ordenamiento Insercion\n2)ordenamiento burbuja\n3)ordenamiento seleccion\n4)shell\n");
        scanf("%d",&opc2);
        switch (opc2)
        {
            case 1:
            printf("############ Ordenando con Insercion ############\n");
            ordenamientoInsercion(x, _TAMAN);
            printf("Numeros Ordenados");
            impri(x, _TAMAN);
            break;
            case 2:
            printf("############ Ordenando con Burbuja ############\n");
            ordenamientoBurbuja(x, _TAMAN);
            printf("Numeros Ordenados");

            impri(x, _TAMAN);
            break;
            case 3:
            printf("############ Ordenando con seleccion ############\n");
            ordenamientoSeleccion(x,_TAMAN);
            printf("Numeros Ordenados");
            
            impri(x, _TAMAN);
            break;
            case 4:
            printf("############ Ordenando shell ############\n");
            ordshell(x,_TAMAN);
            printf("Numeros Ordenados");
            
            impri(x, _TAMAN);
            break;
            default:
            break;
            break;
        }
        
            break;
            case 2:
            printf("MENU:\n1)busqueda binaria\n2)busqueda secuencial\n");
            scanf("%d",&opc5);
            switch (opc5)
            {
            case 1:
            busqueda_binaria(x,_TAMAN);
            break;
            case 2:
            busqueda_secuencial(x,_TAMAN);
            break;
        
            default:
            break;
            }
            default:
            break;
        }   
    
    case 3:
    chain(a,_TAMANC);
    printf("Menu:\n1)busqueda secuencial\n2)salir\n");
    scanf("%d",&opc6);
    switch (opc6)
    {
    case 1:
        busqueda_secuencial_cad(a,_TAMANC);
        break;
    case 2: 
    break;
    default:
        break;
    }
    break;
    default:
    break;
    }
    
}

void numerosporteclado(int x[],int taman)
{
    int i;
    for(i=0; i<taman; i++)
    {
	printf("Digite un valor:\n");
	scanf("%d",&x[i]);
    }
}

void numerosaleatorios(int x[], int taman)
{  
    int i;
    cont = cont + 1;
    srand(time(NULL)*cont);
    {
    for(i=0; i<taman; i++)
    x[i]=rand()%100;
    }
}

void ordenamientoInsercion(int x[],int taman)
{
	int i,j,aux;
	for(i=0;i<taman;i++)
	{
		j=i;
		aux=x[i];
		while(j>0&&aux<x[j-1])
		{
			x[j]=x[j-1];
			j--;
		}
		x[j]=aux;
	}
	for(i=0;i<taman;i++)
	{
		printf("Posicion %d = %d\n",i+1,x[i]);
	}
}

void ordenamientoSeleccion(int x[],int taman)
{
    int i,j,k,y;
    for (i=0;i<taman-1;i++)
    {
         k=i;
        for(j=i+1;j<taman;j++)
        {
            if (x[j]<x[k])
            {
                k=j;
            }
        }
        if(i!=k)
        {
            y = x[i];
            x[i] = x[k];
            x[k] = y;
        }
    }
}

void ordenamientoBurbuja(int x[],int taman)
{
    int  i,j,aux;
    for(i=0;i<taman;i++)
    {
        for(j=0;j<taman-1;j++)
        {
            if(x[j]>x[j+1])
            {
                aux=x[j];
                x[j]=x[j+1];
                x[j+1]=aux;
            }
        }
    }
}
void ordshell(int x[],int taman)
{
    int i,j,y,tmp;

    for(i = 1; i < taman; i = i*3+1) {} //la idea es que SOLO se incremente i a razón de i*3+1 por repetición

        while (i > 0)
        {
            for(j = i; j < taman; j++) 
            {
                y = j;
                tmp = x[j];
                while (y >= i && x[y - i] > tmp) {
                x[y] = x[y - i];
                y = y - i;
                }
                x[y] = tmp;
            }
            i = i / 2;
        }
}

void busqueda_binaria(int x[],int taman)
{
    int inf,sup,mit,dato;
    printf("dato a buscar:\n");
    scanf("%d",&dato);
    inf=0;
    sup=taman;
    while (inf<=sup)
    {
        mit=(inf+sup)/2;
        if (x[mit]==dato)
        {
            printf("dato %d encontrado posicion %d\n",dato,mit+1);
            break;
        }
        if (x[mit]>dato)
        {
        sup=mit;
        mit=(inf+sup)/2;
        }
        if (x[mit]<dato)
        {
        inf=mit;
        mit=(inf+sup)/2;
        }
            
    }
}

void busqueda_secuencial(int x[],int taman)
{
    int i,valor,ubicado=0;
    printf("dato a buscar:\n");
    scanf("%d",&valor);
    for(i=0;i<taman;i++)
    {
        if(x[i]==valor)
        {
            ubicado+=1;
            printf("\nEl numero %d se encuentra en la posicion x[%d]de la lista ",valor,i+1);
        }
    }
    if (ubicado==0)
    {
        printf("\nEl numero ingresado %d no se encuentra en la lista\n ",valor);
    }
    printf("se encontro %d veces\n",ubicado);
}

void chain (char a[],int taman)
{
    printf("Escriba una cadena sin espacios:\n");
    scanf("%s",a);
}

void impri(int x[], int taman)
{
    int i;
    printf("[ ");
    for(i=0; i<taman; i++)
    printf("%d ", x[i]);
    printf("]\n");
}

void busqueda_secuencial_cad(char a[],int tamanc)
{
    int i,ubicado=0;
    char valor;
    printf("letra a buscar:\n");
    scanf("%s",&valor);
    for(i=0;i<tamanc;i++)
    {
        if(a[i]==valor)
        {
            ubicado+=1;
            printf("\nla letra %c se encuentra en la posicion x[%d]de la lista ",valor,i+1);
        }
    }
    printf("se encontro %d veces\n",ubicado);
    if (ubicado==0)
    {
        printf("\nla letra ingresada %c no se encuentra en la lista\n ",valor);
    }
}
