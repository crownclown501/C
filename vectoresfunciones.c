#include<stdio.h>
#include<math.h>
#include <stdlib.h>

typedef struct 
{
int X;
int Y;
}punto;
 punto vectores[2];int i,j,a;
 int z=0,opc2,nvx,nvy,dist;
    void llenar()
    {
        getchar();
        for (i=0;i<2;i++)
        {
            printf("DATOS INICIALES DEL PUNTO %d\n",i+1);
            printf("Coordenada en X del punto %d: ",i+1);
            scanf("%d",&vectores[i].X);
            printf("Coordenada en Y del punto %d: ",i+1);
            scanf("%d",&vectores[i].Y);
        }
        z+=1;
    }
    void imprimir(void)
    {   
        for(int j=0;j<2;j++)
        {
            printf("(%d,%d)",vectores[j].X,vectores[j].Y);
        }
    }
    void trasladar(void)
    {   
        getchar();
        if (opc2==1)
        {
            vectores[0].X=vectores[0].X+nvx;
            vectores[0].Y=vectores[0].Y+nvy;
        }
        else if (opc2==2)
        {
            vectores[1].X=vectores[1].X+nvx;
            vectores[1].Y=vectores[1].Y+nvy;
        }
    } 

    void calculardist(void)
    {
        getchar();
        dist= sqrt(pow(vectores[1].X-vectores[0].X,2)+pow(vectores[1].Y-vectores[0].Y,2));
        printf("\nDistancia entre P1(%d,%d) y P2(%d,%d) es %d\n",vectores[0].X,vectores[0].Y,vectores[1].X,vectores[1].Y,dist);
    }

int main ()
{   int opc;
   
    do{
    printf("\nMenu\n1)llenar\n2)Muestra coordenadas\n3)Traslada un punto\n4)Calcula distancia\n5)Finalizar\n");
    scanf("%d",&opc);
    printf("\e[1;1H\e[2J\n");
    switch (opc)
    {
        case 1:
        llenar();
        break;

        case 2:
        if(z!=0)
        {
        imprimir();
        }
        else
        {
            printf("no hay datos");
        }
        
        break;
        
        case 3:
        getchar();
        printf("\nMenu\n1)llenar\n2)Muestra coordenadas\n");
        scanf("%d",&opc2);
        printf("\e[1;1H\e[2J\n");
        switch(opc2)
        {
            case 1:
            if(z!=0)
            {
            trasladar();
            }
            else
            {
                printf("no hay datos");
            }
            break;
            case 2:
            if(z!=0)
            {
                trasladar();
            }
            else
            {
                printf("no hay datos");
            }
            break;
            default:printf("\nERROR... opcion invalida\n");
            break;
        }
        
        case 4:
        if(z!=0)
        {
        calculardist();
        }
        else
        {
            printf("no hay datos");
        }
        break;

        default:
        break;
    }
    }while(opc!=5);
}
