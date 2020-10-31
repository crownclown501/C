#include <stdio.h>

int main()
{
        int s,x=1;int i,a=0,y=1;
        printf("digite  valor \n");
        scanf("%d",&s);
        for (i=s;i>1;i--)
        {  
            x=x*i;       
            printf("%d * %d =%d\n", y, i,x);
            a=x;
            y=a;
        }
        printf ("\nfuncion factorial de %d es  %d\n", s, x);
}
