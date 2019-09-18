#include <stdio.h>

int matriz[5][5];

void ingresar(void)
{
    printf("Llenado de matriz:");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("\nIngrese el valor para la posición [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}
void imprimirMat(void)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
void buscar(void)
{
    int posicionI[25], posicionJ[25], contPos = 0, valor, fueEncontrado = 0;
    getchar();
    printf("Ingrese el valor a buscar\n");
    scanf("%d", &valor);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matriz[i][j] == valor)
            {
                posicionI[contPos] = i;
                posicionJ[contPos] = j;
                contPos += 1;
                fueEncontrado += 1;
            }
        }
    }
    if (fueEncontrado >= 1)
    {
        printf("El valor fue encontrado en la(s) posición(es)\n");
        for (int k = 0; k < fueEncontrado; k++)
        {
            printf("[%d][%d] ", posicionI[k] + 1, posicionJ[k] + 1);
        }
        printf("\n");
    }
}
void imprimirVal(void)
{
    int fila, columna;
    getchar();
    printf("Escriba el número de fila y de columna (Ejem: 2 4): \n");
    scanf("%d %d", &fila, &columna);
    printf("Valor: %d\n", matriz[fila][columna]);
}
int main(void)
{
    int seleccion, ingresada;
    if (!ingresada)
    {
        ingresar();
    }
    printf("\nMenú:\n1) Volver a ingresar matríz.\n2) Imprimir matríz.\n3) Buscar valor en matríz.\n4) Imprimir valor en matríz.\n");
    scanf("%d", &seleccion);
    switch (seleccion)
    {
    case 1:
        ingresar();
        ingresada = 1;
        main();
        break;
    case 2:
        imprimirMat();
        main();
        break;
    case 3:
        buscar();
        main();
        break;
    case 4:
        imprimirVal();
        main();
        break;
    case 0:
        return 0;
    default:
        printf("Opción inválida\n");
        break;
    }
}