#include "ABM.h"

int main()
{
    int continuar=1;
    char opcion;
    eProducto pro[TAM];
    inicializar(pro,TAM);
    do
    {
        printf("Elija una de las siguientes opciones\n\n");
        opcion=menu();
        while(opcion<49||opcion>54||isdigit(opcion)==0)
        {
            system("cls");
            printf("Ingrese correctamente una de las siguientes opciones\n\n");
            opcion=menu();
        }
        switch(opcion)
        {
            case '1':
            {
                AgregarProducto(pro,TAM);
                system("pause");
                system("cls");
                break;
            }
            case '2':
            {
                BorrarProducto(pro,TAM);
                system("pause");
                system("cls");
                break;
            }
            case '3':
            {
                modifEmp(pro,TAM);
                system("pause");
                system("cls");
                break;
            }
            case '4':
            {
                listarEmp(pro,TAM);
                system("pause");
                system("cls");
                break;
            }
            case '5':
            {
                orderEmp(pro,TAM);
                system("pause");
                system("cls");
                break;
            }
            case '6':
            {
                continuar=0;
                break;
            }
        }
    }
    while(continuar==1);

    return 0;
}

