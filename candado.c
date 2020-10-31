#include<stdio.h>
int main(){
	
	int x=3; int y=7; int z=5;//variables de combinacion
     int a; int b; int c; //nuevas variables para adivinar combinacion
      int n; int m; int o; 
      int opc;  //opcion
	
	do{
	
	    printf("Ingresa un digito \n");
	    scanf("%d", & a);
 	      printf("Ingresa un digito \n");         //pide al usuario los numeros 
	        scanf("%d", & b);
	          printf("Ingresa un digito \n");
	            scanf("%d", & c);
	            
		if(a==x && b==y && c==z){     //si todos los datos coincien con los ya pre-establecidos entra 
     	printf("¿Desea cambiar la contraseña?\n1)si \n2)no \n");    //quiere cambiar la combinacion o contraseña ok digite 1 si quiere cambiarla o 2 si no quiere
     	scanf("%d", & opc);
         
     	switch(opc){
     		case 1: // si digito 1 entonces entra en el case 1 y asigna una nueva combinacion o contraseña
     		printf("Digite nuevo numero \n");
     		scanf("%d", & n);
     		    x=n;  // se cambian los valores anteriores por los nuevos
     		printf("Digite nuevo numero \n");
     			scanf("%d", & m);
     			y=m;
     		printf("Digite nuevo numero \n");
     			scanf("%d", & o);
     			z=o;
     		printf("Su nueva contraseña es %d %d %d \n", x, y, z); 
     		break;
     				
     		case 2: // aqui digito un 2 que significaa que no quiere dar una nueva combinacion 
     			printf("Regrese pronto :) \n");
     			break;
		 }
	 } 
			else   // este else es por si algun digito de los que digito de aqui arriba no concuerda con la combinacion 
			printf("\nError\n\n");  //imprimimos en pantalla un error si se equivoco en un digito
     }while(a!=x || b!=y || c!=z);   //el while es para hace un ciclo hasta que se cumpla lo que se quiere 
	 return 0;  

}
