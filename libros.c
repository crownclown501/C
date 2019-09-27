#include <stdio.h>
#include <string.h>

struct libro
{
    char titulo[100];
    char autor[100];
    char editorial[100];
    int edicion;
    int paginas;
} biblioteca[100];

int i = 0;

void ingresarLibros(void)
{
    char titulo[100], autor[100], editorial[100];
    getchar();
    printf("Ingrese el titulo del libro: ");
    fgets(titulo, 99, stdin);
    strcpy(biblioteca[i].titulo, titulo); //    Usamos strcpy para copiar el arreglo local a el arreglo de biblioteca[i] titulo -> biblioteca[i].titulo
    printf("Ingrese el autor del libro: ");
    fgets(autor, 99, stdin);
    strcpy(biblioteca[i].autor, autor);
    printf("Ingrese la editorial del libro: ");
    fgets(editorial, 99, stdin);
    strcpy(biblioteca[i].editorial, editorial);
    printf("Ingrese la edicion del libro: ");
    scanf("%d", &biblioteca[i].edicion);
    printf("Ingrese el numero de paginas del libro: ");
    scanf("%d", &biblioteca[i].paginas);
    i += 1;
}

void imprimirLibrosPorPaginas(void)
{
    for (int j = 0; j < i; j++)
    {
        if (biblioteca[j].paginas < 100)
        {
            printf("Titulo: %s", biblioteca[j].titulo);
        }
    }
}

void imprimirAutorPorEdicion(void)
{
    getchar();
    int edicion;
    printf("\nIngrese el año:\n");
    scanf("%d", &edicion);
    for (int j = 0; j < i; j++)
    {
        if (biblioteca[j].edicion == edicion)
        {
            printf("Autor: %s", biblioteca[j].autor);
        }
    }
}

void imprimirTitulosPorAutor(void)
{
    getchar();
    char autor[100];
    printf("\nIngrese el nombre del autor:\n");
    fgets(autor, 99, stdin);
    for (int j = 0; j < i; j++)
    {
        if (strcmp(biblioteca[j].autor, autor) == 0)
        {
            printf("Titulo: %s", biblioteca[j].titulo);
        }
    }
}

void imprimirDatosPorTitulo(void)
{
    getchar();
    char titulo[100];
    printf("\nIngrese el titulo del libro:\n");
    fgets(titulo, 99, stdin);
    for (int j = 0; j < i; j++)
    {
        if (strcmp(biblioteca[j].titulo, titulo) == 0)
        {
            printf("Titulo: %sAutor; %sEditorial: %sEdicion: %d\nPaginas: %d\n",
                   biblioteca[j].titulo, biblioteca[j].autor, biblioteca[j].editorial, biblioteca[j].edicion, biblioteca[j].paginas);
        }
    }
}

void imprimirAutoresPorEditorial(void)
{
    getchar();
    char editorial[100];
    printf("\nIngrese el nombre de la editorial:\n");
    fgets(editorial, 99, stdin);
    for (int j = 0; j < i; j++)
    {
        if (strcmp(biblioteca[j].editorial, editorial) == 0)
        {
            printf("Autor: %s", biblioteca[j].autor);
        }
    }
}

int main(void)
{
    int seleccion;
    printf("\nMenu:\n1) Ingresar libro\n2) Imprimir libros con menos de 100 pag.\n3) Imprimir autores de un año\n4) Imprimir libros de un autor\n5) Imprimir libro por titulo\n6) Imprimir autores de una editorial\n0) Terminar programa\n");
    scanf("%d", &seleccion);
    switch (seleccion)
    {
    case 1:
        ingresarLibros();
        main();
    case 2:
        if (i != 0)
        {
            imprimirLibrosPorPaginas();
        }
        else
        {
            printf("No hay libros a imprimir");
        }
        main();
    case 3:
        imprimirAutorPorEdicion();
        main();
    case 4:
        imprimirTitulosPorAutor();
        main();
    case 5:
        imprimirDatosPorTitulo();
        main();
    case 6:
        imprimirAutoresPorEditorial();
        main();
    case 0:
        break;
        return 0;
    default:
        printf("Opcion invalida, intente de nuevo.");
        main();
    }
}