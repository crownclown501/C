#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define n 3 //define la cantidad de nombres que va a meter el usuario

int cadenasIngresadas,nombresIngresados, longitudPrimerCadena, longitudSegundaCadena,opc,opc2,opc1,opc3;
char cadenaabuscar[1001], primerCadena[1001], segundaCadena[1001],chan[30],nom[n][30],namae[1001];

void mayusculas (void)
{
    int i;
    getchar();
    for ( i = 0;primerCadena[i]!='\0' ; i++)
    {
        primerCadena[i]= toupper(primerCadena[i]);
    }
    printf("\nprimer cadena en mayusculas: ");
    printf("%s\n\n",primerCadena );
    for ( i = 0;segundaCadena[i]!='\0' ; i++)
    {
        segundaCadena[i]= toupper(segundaCadena[i]);
    }
    printf("\nsegunda cadena en mayusculas: ");
    printf("%s\n",segundaCadena );
}

void minusculas (void)
{
    int i;
    getchar();
    for ( i = 0;primerCadena[i]!='\0' ; i++)
    {
        primerCadena[i]= tolower(primerCadena[i]);
    }
    printf("\nprimer cadena en minusculas: ");
    printf("%s\n\n",primerCadena );
    for ( i = 0;segundaCadena[i]!='\0' ; i++)
    {
        segundaCadena[i]= tolower(segundaCadena[i]);
    }
    printf("\nsegunda cadena en minusculas: ");
    printf("%s\n",segundaCadena );
}

void vocales(void)
{
    getchar();
    int contvocales1=0,i,j,k,contvocales2=0;
    printf("\e[1;1H\e[2J\n"); 
    if(opc==1)
    {
        j=strlen(primerCadena);
        printf("\e[1;1H\e[2J\n");  //
        printf("cadena ingresada %s\n",primerCadena);
        for(i=1;i<j;i++)
        if ((primerCadena[i]==97)||(primerCadena[i]==101)||(primerCadena[i]==105)||(primerCadena[i]==111)||(primerCadena[i]==117))    
        {
            contvocales1++;
        }    
        printf("\n%d\n",contvocales1);
    }

    else if (opc==2)
    {
        j=strlen(segundaCadena);
        printf("\e[1;1H\e[2J\n");  //
        printf("cadena ingresada %s\n",segundaCadena);
        for(i=1;i<j;i++)
        if ((segundaCadena[i]==97)||(segundaCadena[i]==101)||(segundaCadena[i]==105)||(segundaCadena[i]==111)||(segundaCadena[i]==117))    
        {
            contvocales1++;
        }    
        printf("\n%d\n",contvocales1);
    }

    else if (opc==3)
    {
        j=strlen(primerCadena);
        k=strlen(segundaCadena);
        printf("\nprimer cadena  %s\n",primerCadena);
        for(i=1;i<j;i++)
        if ((primerCadena[i]==97)||(primerCadena[i]==101)||(primerCadena[i]==105)||(primerCadena[i]==111)||(primerCadena[i]==117))    
        {
            contvocales1++;
        } 
        printf("\nsegunda cadena %s\n",segundaCadena);
        for(i=1;i<k;i++)
        if ((segundaCadena[i]==97)||(segundaCadena[i]==101)||(segundaCadena[i]==105)||(segundaCadena[i]==111)||(segundaCadena[i]==117))    
        {
            contvocales2++;
        }       
        printf("\n%d\n",contvocales1);
        
        printf("\n%d\n",contvocales2);
    }
}

void changecaracter(void)
{
    char a,b;
    int i=0;

    if (opc1==1)
    {
        printf("\ningrese caracter a sustituir:");
        getchar();
        a=getchar();

        printf("\ningrese nuevo caracter:");
        getchar();
        b=getchar(); 
        while(primerCadena[i]!='\0')
        {
            if (primerCadena[i]==a)
            primerCadena[i]=b;
            i+=1;
        }  
        printf("nueva cadena: %s",primerCadena);
    }

    else if (opc1==2)
    {
        printf("\ningrese caracter a sustituir:");
        getchar();
        a=getchar();
        printf("\ningrese nuevo caracter:");
        getchar();
        b=getchar(); 
        while(segundaCadena[i]!='\0')
        {
            if (segundaCadena[i]==a)
            segundaCadena[i]=b;
            i+=1;
        }  
        printf("\nnueva cadena: %s\n",segundaCadena);
    }
    
}

void contador_caracteres(void)
{
    char b;
    int i=0,contador=0;
    if (opc2==1)
    {
        printf("\ningrese caracter a buscar:");
        getchar();
        b=getchar();
        while(primerCadena[i]!='\0')
        {
            if (primerCadena[i]==b)
            {
                contador+=1;
            }
            i+=1;
        }  
        printf("numero de veces que aparece %c: %d",b,contador);
    }

    else if (opc2==2)
    {
        printf("\ningrese caracter a buscar:");
        getchar();
        b=getchar();

        while(segundaCadena[i]!='\0')
        {
            if (segundaCadena[i]==b)
            {
                contador+=1;
            }
            i+=1;
        }  

        printf("numero de veces que aparece %c: %d",b,contador);
    }
}

int longitud(char cadenaAMedir[])
{
    int longitud = 0;
    while (cadenaAMedir[longitud] != '\n')
    {
        longitud++;
    }
    return longitud;
}

void comparar(void)
{
    int i = longitud(primerCadena), j = longitud(segundaCadena), sonIguales = 1;
    if (i != j)
    {
        printf("Las cadenas son diferentes\n");
    }
    else
    {
        for (int k = 0; k <= i; k++)
        {
            if (primerCadena[k] != segundaCadena[k])
            {
                sonIguales = 0;
                break;
            }
        }

        if (sonIguales == 1)
        {
            printf("Las cadenas son iguales\n");
        }

        else
        {
            printf("Las cadenas son diferentes\n");
        }
    }
}

void concatenar(void)
{
    char cadenaConjunta[2001], separador;
    int i = 0, j = 0;
    printf("Escriba un separador o nada para dejar las cadenas juntas.\n");
    getchar();
    separador = getchar();
    while (primerCadena[i] != '\n')
    {
        cadenaConjunta[i] = primerCadena[i];
        i++;
    }

    if (separador != '\n')
    {
        cadenaConjunta[i] = separador;
        i++;
    }

    while (segundaCadena[j] != '\n')
    {
        cadenaConjunta[i + j] = segundaCadena[j];
        j++;
    }

    cadenaConjunta[i + j] = '\0';
    printf("%s\n", cadenaConjunta);
}

void buscar (void)
{
    printf("\nIngrese cadena a buscar: ");
    fgets(cadenaabuscar,1000,stdin);

    if (opc3==1)
    {
        int i = longitud(primerCadena), j = longitud(cadenaabuscar), sonIguales = 1;
        if (i != j)
        {
            printf("Las cadenas son diferentes\n");
        }
        else
        {
            for (int k = 0; k <= i; k++)
            {
                if (primerCadena[k] != cadenaabuscar[k])
                {
                    sonIguales = 0;
                    break;
                }
            }
            if (sonIguales == 1)
            {
                printf("\nLas cadenas son iguales\n");
                printf("%s",primerCadena);
                printf("\n\n");
                printf("%s",cadenaabuscar);
            }
            else
            {
                printf("Las cadenas son diferentes\n");
            }
        }
    }

    else if (opc3==2)
    {
        int i = longitud(segundaCadena), j = longitud(cadenaabuscar), sonIguales = 1;
        if (i != j)
        {
            printf("Las cadenas son diferentes\n");
        }
        else
        {
            for (int k = 0; k <= i; k++)
            {
                if (segundaCadena[k] != cadenaabuscar[k])
                {
                    sonIguales = 0;
                    break;
                }
            }

            if (sonIguales == 1)
            {
                printf("\nLas cadenas son iguales\n");
                printf("%s",segundaCadena);
                printf("\n\n");
                printf("%s",cadenaabuscar);
            }

            else
            {
                printf("Las cadenas son diferentes\n");
            }
        }
    }
}

void nombres_ascendentemente(void)
{
    int i,j;
    float compare;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n-i; j++)
        {
            compare=strcmp(nom[j],nom[j+1]);
            if (compare > 0)
            {
                strcpy(chan,nom[j]);
                strcpy(nom[j],nom[j+1]);
                strcpy(nom[j+1],chan);
            }
        }
    }
    printf("\nnombres ordenados: \n");
    for (i=1;i<=n;i++)
    {
        printf("[%d] -> %s:\n",i,nom[i]);
    }
}

void buscar_nombre(void)
{
    int i=0,j;
    char name[30];
    getchar();
    printf("\ningrese nombre a buscar:");
    scanf("%s",name);
    
    int cont=0,v=0;
    for ( i = 1; i <= n; i++)
    {
        if ((strcmp(nom[i],name))==0)
        {
            cont=1;
            v=i;
        }
    }

    if (cont!=0)
    {
        printf("nombre %s encontado en la casilla %d\n",name,v);
    }
    
    else if (cont==0)
    {
        printf("no se encontro el nombre ingresado en la cadena\n");
    }
    
}

void ingresar_nombres(void)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("\ndigite un nombre:");
        scanf("%s",nom[i]);
    }
    nombresIngresados=1;
}

void ingresar(void)
{
    printf("Ingrese la primer cadena\n");
    fgets(primerCadena, 1000, stdin);
    printf("Ingrese la segunda cadena\n");
    fgets(segundaCadena, 1000, stdin);
    cadenasIngresadas = 1;
}

int	main(void)
{
  int seleccion;
    
    if (!cadenasIngresadas)
    {
        ingresar();
    }
    if(!nombresIngresados)
    {
        ingresar_nombres();
    }
    do 
    {
        printf("\nMenu de operaciones\n");
        printf(" 1) Convertir De Minusculas a Mayusculas\n");
        printf(" 2) Convertir De Mayusculas a Minusculas\n");
        printf(" 3) Contar el numero de Vocales De una cadena\n");
        printf(" 4) Cambiar un caracter por otro\n");
        printf(" 5) Contar el numero de veces de un caracter\n");
        printf(" 6) Determinar la longitud de una palabra\n");
        printf(" 7) Comparar Cadenas\n");
        printf(" 8) Concatenar dos Palabras\n");
        printf(" 9) Buscar Cadenas\n");
        printf(" 10) Ordenar nombres ascendentemente\n");
        printf(" 11) Buscar Nombre\n");
        printf("0)Salir\n");
        printf("Digite una opcion:\n");
        scanf("%d",&seleccion);
        switch (seleccion)
        {
        
            case 1:
            mayusculas();
            

            case 2:
            minusculas();
            

            case 3:
                getchar();
                printf("\n1)vocales primer cadena\n2)vocales segunda cadena\n3)ambas cadenas\n");
                scanf("%d",&opc);
                switch (opc)
                {
                    case 1:
                        vocales();
                        

                    case 2:
                        vocales();
                        

                    case 3:
                        vocales();
                        

                    default:
                    break;
                }

            case 4:
                getchar();
                printf("\n1)primer cadena\n2)segunda cadena\n");
                scanf("%d",&opc1);
                switch (opc1)
                {
                    case 1:
                    changecaracter();
                    
                    break;

                    case 2:
                    changecaracter();
                    
                    break;

                    default:
                    break;
                }

            case 5: 
                getchar();
                printf("\n1)primer cadena\n2)segunda cadena\n");
                scanf("%d",&opc2);
                switch (opc2)
                {
                    case 1:
                    contador_caracteres();
                    
                    break;

                    case 2:
                    contador_caracteres();
                    
                    break;

                    default:
                    break;
                }

            case 6:
            printf("\nLa longitud de la primer cadena es: %d\nLa longitud de la segunda cadena es: %d\n", longitud(primerCadena), longitud(segundaCadena));
            

            case 7: 
            comparar();
            

            case 8:
            concatenar();
            

            case 9:
                getchar();
                printf("\n1)primer cadena\n2)segunda cadena\n");
                scanf("%d",&opc3);
                switch (opc3)
                {
                    case 1:
                    buscar();
                    
                    break;

                    case 2:
                    buscar();
                    
                    break;

                    default:
                    break;
                }
                
            case 10:
            nombres_ascendentemente();
            break;

            case 11:
            buscar_nombre();
            break;
        
        }
    }while ((seleccion!=0)&&(seleccion<12));
}
