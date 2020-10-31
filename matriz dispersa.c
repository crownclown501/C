#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x = 0, g = 0;
    float h = 0;
    int V[15],I[15],J[15];
    int i,j;
    printf("Ingresa matriz 3x5\n");
    int a[3][5];
    for ( i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("Digite numero posicion [%d][%d]\n", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 5; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 5; j++)
        {
            if (a[i][j] == 0)
            {
                x += 1;
            }
        }
    }
    g = 3 * 5;
    h = (x * 100) / g;
    int k=0,z=0;
    if (h < 60)
    {
        printf("no es matriz dispersa\n");
    }
    else if (h >= 60)
    {
     printf("es matriz dispersa\n");
        for ( i = 0; i < 3; i++)
        {
            for ( j = 0; j < 5; j++)
            {
                if (a[i][j] != 0)
                {
                    V[k]=a[i][j];
                    
                    I[k]=i;
                    J[k]=j;
                    z++;
                    k++;
                }
            }
        }
        printf("V={");
        for (i=0;i<z;i++)
        {
            printf("%d ", V[i]);
        }
        printf("}\n");
        printf("I={");
        for (i=0;i<z;i++)
        {
            printf("%d ", I[i]);
        }
        printf("}\n");
        printf("J={");
        for (i=0;i<z;i++)
        {
            printf("%d ", J[i]);
        }
        printf("}\n");
    }
    printf("\n");
    return 0;
}
