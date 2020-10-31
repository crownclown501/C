#include <stdio.h>
int n,m;
int  main()
{
    for (n=1;n<=10;n++)
    {
        for (m=10;m>=1;m--)
        {
            printf("%d vez de %d = %d \n", n, m, n*m);
        }
    }
}
