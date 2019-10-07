#include <stdio.h>

/*
TODO:


Reservar, cancelar, pagar boletos.

*/

int asientos[4][10];

void mapaAsientos(void) {
    printf("    1  2  3  4  5  6  7  8  9  10\n  ---------------------------------\n");
    for(int f = 0; f < 4; f++) {
        if (f == 2) {
            printf("                                  |\n");
        }
        printf("%d | ", f + 1);
        for (int c = 0; c < 10; c++) {
            if (asientos[f][c] == 0) {
                printf("⚪  ");
            } else if (asientos[f][c] == 1) {
                printf("🔵  ");
            } else if (asientos[f][c] == 2) {
                printf("🟢  ");
            }
            if (c == 9) {
                printf("|");
            }
            
        }
        printf("\n");
    }
    printf("  ---------------------------------\n");
}

void mostrarMapa(void) {
    printf("\e[1;1H\e[2J");
    mapaAsientos();
}

void reservar(void){
    int c, f, cantidad, ocupado;
    do {
        mostrarMapa();
        if (ocupado == 1) {
            printf("El asiento [%d][%d] no esta disponible, elija otro.\n", f, c);
        }
        printf("Ingrese el asiento a reservar [Columna Fila] o 0 0 para salir al menú:\n", cantidad);
        scanf("%d%d", &c, &f);
        if (asientos[f - 1][c - 1] == 0) {
            asientos[f - 1][c - 1] = 1;
        } else {
            ocupado = 1;
        }
    } while (c != 0 || f != 0);
}

void cancelar(void) {
    int c, f, cantidad, ocupado;
    char continuar;
    do {
        mostrarMapa();
        printf("Ingrese el asiento a cancelar [Columna Fila] o 0 0 para salir al menú:\n", cantidad);
        scanf("%d%d", &c, &f);
        if (asientos[f - 1][c - 1] == 1) {
            asientos[f - 1][c - 1] = 0;
        } else if (asientos[f - 1][c - 1] == 2) {
            printf("El asiento está pagado ¿Desea cancelar de todos modos? [s/n]\n");
            continuar = getchar();
            if (continuar == 's') {
                asientos[f - 1][c - 1] = 0;
            }
        }
    } while (c != 0 || f != 0);
}

void pagar(void) {
    int c, f, cantidad, ocupado;
    char continuar;
    do {
        mostrarMapa();
        printf("Ingrese el asiento a pagar [Columna Fila] o 0 0 para salir al menú:\nSi el asiento no está apartado al pagar se apartará automaticamente\nCoste del asiento: $180\n", cantidad);
        scanf("%d%d", &c, &f);
        asientos[f - 1][c - 1] = 2;
    }
    while (c != 0 || f != 0);
}
int main (void) {
    mostrarMapa();
    int seleccion;
    printf("Menu:\n1) Reservar.\n2) Cancelar\n3) Pagar\n");
    scanf("%d", &seleccion);
    switch (seleccion)
    {
    case 1:
        getchar();
        reservar();
        main();
        break;
    case 2:
        getchar();
        cancelar();
        main();
        break;
    case 3:
        getchar();
        pagar();
        main();
        break;
    default:
        break;
    }
}