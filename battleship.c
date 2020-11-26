/*luis fernando morones hernandez
matricula:201864246
fecha: 25-noviembre-2020*/

#include <stdio.h>
#include <stdlib.h>

int matriz[10][10],i,j;
int matri[10][10];
int mostrar[10][10];

void mapatablero(void)
{
    //  Imprimir filas
    printf("    0    1   2   3   4   5   6   7   8   9\n  -------------------------------------------\n");
    for (int f = 0; f < 10; f++)
    {
        //  Borde
        printf("%d | ", f );
        //  Recorrer arreglo para imprimir los asientos y su estado
        for (int c = 0; c < 10; c++)
        {
            if (matriz[f][c] == 0)
            {
                //  inicio tablero 
                printf("?  ");
            }
            else if (matriz[f][c] == 1)
            {
                //  fallado
                printf("??  ");
            }
            else if (matriz[f][c] == 4)
            {
                //  tiro en el blanco
                printf("??  ");
                
            }
            if (c == 9)
            {
                //  Borde
                printf("|");
            }
        }
        printf("\n");
    }
    printf("  -------------------------------------------\n\n");
}
void mapatablero2(void)
{
    //  Imprimir filas
    printf("    0    1   2   3   4   5   6   7   8   9\n  -------------------------------------------\n");
    for (int f = 0; f < 10; f++)
    {
        printf("%d | ", f );
        for (int c = 0; c < 10; c++)
        {
            if (mostrar[f][c] == 0)
            {
                printf("?  ");
            }
            else if (mostrar[f][c] == 2)
            {
                printf("??  ");
            }
            if (c == 9)
            {
                printf("|");
            }
        }
        printf("\n");
    }
    printf("  -------------------------------------------\n\n");
}

void mostrarMapa(void)
{   
    mapatablero();
}


void disparo()
{
    int c, f, contador=0, error,x=0,acierate=0,fallos=0,y=0;
    FILE *fichero;
    do 
    {
       
            if (error == 1)
            {
                printf("\n\nlas cordenadas [%d][%d] que dio ya fueron anteriormente dadas\n\n", f, c);
                error= 0;
            }
            printf("\nIngrese el lugar a disparar ejemplo: n,m\n"); //8,4
            scanf("%d,%d",&f,&c);
           
            if (matriz[f][c] == 0)
            {   
                if ((fichero = fopen("jugadores.txt", "a+")) != NULL)
                {
                    if(matri[f][c]==2)
                    {   
                        acierate++;
                        printf("acertaste %d puntos\n",acierate);
                        matriz[f][c]=4;
                        y++;
                    
                        if (y==30)
                        {       
                            y=y/3;            
                            printf("\nHAS GANADO!!!, derribaste todos %d los barcos\n",y);
                            
                            
                            
                            fprintf(fichero,"ganador\n"); 
                            fprintf(fichero,"\n");
                            
                            
                            contador=10;
                            x=10;
                        }
                        
                    }
                    else
                    {
                        fallos++;
                        contador++;
                        x++;
                        matriz[f][c]=1;
                        printf("\nfallaste\n");
                        if(fallos==10)
                        {
                            y=y/3;
                            fprintf(fichero,"perdedor  %dbh\n",y); 
                            fprintf(fichero,"\n");
                            mapatablero2();
                            x=10;
                            contador=10;
                        }
                    }
                }
                else
                {
                printf("No se pudo abrir el archivo.\n");  
                } 
                fclose(fichero);
            }
        else
        {
            error = 1;
        }
         mostrarMapa();
    }while((contador<10)&&(x<10));
  
}



void coord(FILE *coordenadas)
{
    
    int fila,column;
    int x;
    
    if ((coordenadas=fopen("coord.txt","r"))!=NULL)
    {
        for (i=0;i<10;i++)
        {
            fscanf(coordenadas,"%d %lc %d",&fila,&x,&column);
            for (int n=0;n<=2;n++)
            {
                matri[fila][column+n]=2;
                if (mostrar[fila][column+n] == 0)
            {
                mostrar[fila][column+n]=2;
            }
                
            }
             printf("%d%c%d\n",fila,x,column);
        }
    }

    fclose(coordenadas);
}


int main()
{   
    FILE *cordenadas;
    char nombre[21];
    int edad;
    int y;
    FILE *fichero;
    printf("Nombre: ");
    scanf("%s", nombre);
    printf("Edad: ");
    scanf("%d", &edad);
        if ((fichero = fopen("jugadores.txt", "a+")) != NULL)
            {
            
            fprintf(fichero,"%s\t %d años\t",nombre,edad); 
            
            }
            else
            {
                printf("No se pudo abrir el archivo.\n");  
            } 
            fclose(fichero);

        if(edad>12)
        {   
            mostrarMapa();
            coord(cordenadas);
            disparo();
        }
    return 1;
}
