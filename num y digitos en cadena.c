#include<stdio.h>
#include<string.h>
int main()
{
    int contnum=0,contdigitos=0,m=0,i,j;
    char arr[10001];
    printf("\ndigite la cadena\n");
    fgets(arr, 10001, stdin);
    j=strlen(arr);
    printf("\e[1;1H\e[2J\n");  //
    printf("cadena ingresada %s",arr);
    for(i=1;i<j;i++)
    if ((arr[i]>=48)&&(arr[i]<=57))    
    {
        if(m==0)
        {
            contnum++;
        }
        contdigitos++;
        m=1;
    }
    else
    {
        m=0;
    }
    printf("\n%d\n",contnum);
    printf("\n%d\n",contdigitos);
}
