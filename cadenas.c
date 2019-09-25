#include <stdio.h>

int cadenasIngresadas, longitudPrimerCadena, longitudSegundaCadena;
char primerCadena[1001], segundaCadena[1001];

int longitud(char cadenaAMedir[])
{
    int longitud = 0;
    while (cadenaAMedir[longitud] != '\n')
    {
        longitud++;
    }
    return longitud;
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
void invertir(void)
{
    int i = longitud(primerCadena), j = longitud(segundaCadena);
    printf("Primer cadena invertida: ");
    for (int k = 0; k <= i; k++)
    {
        printf("%c", primerCadena[i - k]);
    }
    printf("\nSegunda cadena invertida: ");
    for (int k = 0; k <= j; k++)
    {
        printf("%c", segundaCadena[j - k]);
    }
    printf("\n");
}
void copiar(void)
{
    int i = longitud(primerCadena), j = longitud(segundaCadena);
    char cadenaCopiada[1001];
    for (int k = 0; k <= i; k++)
    {
        cadenaCopiada[k] = primerCadena[k];
    }
    for (int k = 0; k < j; k++)
    {
        cadenaCopiada[k] = segundaCadena[k];
    }
    printf("%s\n", cadenaCopiada);
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
void buscar(void)
{
    int encontrada = -1, cadena;
    char letra;
    printf("Ingrese letra a buscar:\n");
    getchar();
    letra = getchar();
    printf("Ingrese en cual cadena buscarla ( 1 | 2 )\n");
    getchar();
    cadena = getchar();
    if (cadena == 49)
    {
        int i = longitud(primerCadena);
        for (int k = 0; k <= i; k++)
        {
            if (primerCadena[k] == letra)
            {
                encontrada = k;
                break;
            }
        }
        printf("La letra se encontró en la posición: %d\n", encontrada);
    }
    else if (cadena == 50)
    {
        int j = longitud(segundaCadena);
        for (int k = 0; k <= j; k++)
        {
            if (segundaCadena[k] == letra)
            {
                encontrada = k;
                break;
            }
        }
        printf("La letra se encontró en la posición: %d\n", encontrada);
    }
    else
    {
        printf("El número de cadena no es valido, intente de nuevo\n");
    }
}
void ingresar(void)
{
    printf("Ingrese la primer cadena\n");
    fgets(primerCadena, 1000, stdin);
    printf("Ingrese la segunda cadena\n");
    fgets(segundaCadena, 1000, stdin);
    cadenasIngresadas = 1;
}
int main(void)
{
    int seleccion;
    if (!cadenasIngresadas)
    {
        ingresar();
    }
    printf("\nMenú:\n1) Obtener longitud de cadenas.\n2) Concatenar cadenas.\n3) Invertir cadenas.\n4) Copiar una cadena en otra.\n5) Comparar cadenas.\n6) Buscar índice de letra en cadenas.\n7) Ingresar cadenas de nuevo.\n0) Salir\n");
    scanf("%d", &seleccion);
    switch (seleccion)
    {
    case 1:
        printf("La longitud de la primer cadena es: %d\nLa longitud de la segunda cadena es: %d\n", longitud(primerCadena), longitud(segundaCadena));
        main();
    case 2:
        concatenar();
        main();
    case 3:
        invertir();
        main();
    case 4:
        copiar();
        main();
    case 5:
        comparar();
        main();
    case 6:
        buscar();
        main();
    case 7:
        getchar();
        ingresar();
        main();
    case 0:
        return 0;
    default:
        printf("No seleccionó una opción valida, intente de nuevo.\n");
        break;
    }
}