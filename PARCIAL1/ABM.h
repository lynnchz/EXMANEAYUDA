#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define TAM 1
#define VACIO 1
#define LLENO 0


typedef struct
{
    int codigoDP;
    char descripcion[30];
    float importe;
    int cantidad;
    int isEmpty;
    int idSector;
}eProducto;

typedef struct
{
    int id;
    char descripcion[30];
    int isEmpty;
}eSector;

char menu(void);
char menuModif(void);
void init(eProducto[],int);
int buscaLibre(eProducto[],int);
int buscaEmp(eProducto[],int,int);
void mostrarEmp(eProducto[],int);
void AgregarProducto(eProducto[],int);
void BorrarProducto(eProducto[],int);
void modifEmp(eProducto[],int);
void listarEmp(eProducto[],int);
void orderEmp(eProducto[],int);
void mostrarEmp2(eProducto[],int);
