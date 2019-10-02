/*
TODO: 

paciente {
    nombre,
    numero,
    coreo,
    celular,
    historial,
    edad,
    sexo,
    diaConsulta,
    horaConsulta,
    mesConsulta
}

Capturar pacientes
Asignar dia,hora,mes consulta
Buscar por numero de paciente y nombre

filtro {
   edad,
    sexo, f/m/o
    dia/mes Consulta
}

Meses de 28 días:
Febrero tiene 28 salvo en los años bisiestos que tiene 29 días.

Meses de 30 días:
Abril, junio, septiembre y noviembre.

Meses de 31 días:
Enero, marzo, mayo, julio, agosto, octubre y diciembre.


*/

#include <stdio.h>
#include <string.h>

struct paciente {
    char nombre[100];
    int numeroPaciente;
    char corre[100];
    int celular;
    char historial[10000];
    int edad;
    char sexo[1];
    int diaConsulta;
    char horaConsulta[5];
    int mesConsulta;

} pacientes[365*12];

struct mes {
    int enero[31][12];
    int febreo[28][12];
    int marzo[31][12];
    int abril[30][12];
    int mayo[31][12];
    int junio[30][12];
    int julio[31][12];
    int agosto[31][12];
    int septiembre[30][12];
    int octubre[31][12];
    int noviembre[30][12];
    int diciembre[31][12];
} meses;

int main()
{
    meses.enero[0][0] = 28876451;
    printf("%d\n", meses.enero[0][0]);
}