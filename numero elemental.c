#include <stdio.h>
int main() 
{	
int a;
printf("Digite un numero: ");
scanf("%d",&a);	
	if(((a%4==0)&&(a%3==0))||((a%4==0)&&(a%5==0))||(a%4==0))
	{
		printf("the number %d isn't an elemental number\n",a);
	}
    else if((a%3==0)||(a%5==0))
	{
		printf("the number %d is an elemental number\n",a);
	}
	else
	{
		printf("the number %d isn't an elemental number\n",a);
	}
	
}
