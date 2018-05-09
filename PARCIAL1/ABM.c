#include "ABM.h"

char menu(void)
{
    char opcion;

    printf(" 1) Agregar producto\n");
    printf(" 2) Borrar producto\n");
    printf(" 3) Modificar Producto\n");
    printf(" 4) Listar\n");
    printf(" 5) Ordenar\n");
    printf(" 6) Salir\n");
    printf("Opcion ingresada: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
}
void inicializar(eProducto pro[],int tam)
{
    for(int i=0 ; i<tam ; i++)
    {
        pro[i].isEmpty=VACIO;
    }
}
int buscaLibre(eProducto pro[],int tam)
{
    int indice=-1;

    for(int i=0 ; i<tam ; i++)
    {
        if(pro[i].isEmpty==VACIO)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
int BuscarPro(eProducto pro[], int tam, int codigoDP)
{
    int hallado=-1;

    for(int i=0 ; i<tam ; i++)
    {
        if(pro[i].codigoDP==codigoDP && pro[i].isEmpty==LLENO)
        {
            hallado=i;
            break;
        }
    }

    return hallado;
}
void mostrarPro(eProducto pro[],int hallado)
{
    int set;
    char linea[100], aux[80];
    eSector sector[5];

    //codigoDP
    sprintf(linea,"|%d",pro[hallado].codigoDP);
    sprintf(aux,"%d",pro[hallado].codigoDP);
    set=10-strlen(aux);
    for(int i=0 ; i<set ; i++)
    {
        strcat(linea," ");
        if(i==set-1)
        {
            strcat(linea,"|");
        }
    }
    //descripcion
    sprintf(aux,"%s",pro[hallado].descripcion);
    set=30-strlen(pro[hallado].descripcion);
    for(int i=0 ; i<set ; i++)
    {
        strcat(aux," ");
        if(i==set-1)
        {
            strcat(aux,"|");
        }
    }
    strcat(linea,aux);
    //importe
    sprintf(aux,"%c",pro[hallado].importe);
    for(int i=0 ; i<3 ; i++)
    {
        strcat(aux," ");
        if(i==2)
        {
            strcat(aux,"|");
        }
    }
    strcat(linea,aux);
    //cantidad
    sprintf(aux,"%.2f",pro[hallado].cantidad);
    set=10-strlen(aux);
    for(int i=0 ; i<set ; i++)
    {
        strcat(aux," ");
        if(i==set-1)
        {
            strcat(aux,"|");
        }
    }
    strcat(linea,aux);
}
void mostrarPro2(eProducto pro[],int hallado)
{
    printf("%d\t\t\t%s\t\t\t%c\t%d/%d/%d\t%.2f\n", pro[hallado].codigoDP, pro[hallado].descripcion, pro[hallado].importe, pro[hallado].cantidad);
}
void AgregarProducto(eProducto pro[],int tam)
{
    int indice, hallado, error=0, codigoDP;
    char aux[5], auxF[6];

    system("cls");
    indice=buscaLibre(pro,tam);
    if(indice==-1)
    {
        printf("\nNo hay espacio en agenda, borre alguno primero\n");
        system("pause");
    }
    else
    {
        printf("---Agregar producto---\n");
        //codigoDP
        printf("\nIngrese Codigo de producto: ");
        fflush(stdin);
        scanf("%s",aux);
        for(int i=0 ; i<strlen(aux) ; i++)
        {
            if(!isdigit(aux[i]))
            {
                error=1;
                while(error==1)
                {
                    printf("\nIngrese Codigo de producto correctamente: ");
                    fflush(stdin);
                    scanf("%s",aux);
                    i=-1;
                    error=0;
                }
            }
        }
        codigoDP=atoi(aux);
        hallado=BuscarPro(pro,tam,codigoDP);
        printf("\n");
        if(hallado!=-1)
        {
            printf("El siguiente empleado ya ha sido agregado previamente\n");
            printf("----------------------------------------------------------------------------\n");
            printf("|Codigo de producto    |descripcion                        |importe|cantidad\n");
            printf("----------------------------------------------------------------------------\n");
            mostrarPro(pro,hallado);
        }
        else
        {
            pro[indice].isEmpty=LLENO;
            pro[indice].codigoDP=codigoDP;
            //descripcion
            printf("Ingrese descripcion: ");
            fflush(stdin);
            scanf("%[^\n]",pro[indice].descripcion);
            strlwr(pro[indice].descripcion);
            for(int i=0 ; pro[indice].descripcion[i]!='\0' ; i++)
            {
                if(i==0)
                {
                    pro[indice].descripcion[i]=toupper(pro[indice].descripcion[i]);
                }
                if(pro[indice].descripcion[i]==' ')
                {
                    pro[indice].descripcion[i+1]=toupper(pro[indice].descripcion[i+1]);
                }
            }
            //importe
            printf("\nIngrese Importe: ");
            fflush(stdin);
            scanf("%c",&pro[indice].importe);
            while(pro[indice].importe<0)
            {
                printf("\nIngrese un importe correcto: ");
                fflush(stdin);
                scanf("%c",&pro[indice].importe);
            }
            //cantidad
            printf("\nIngrese cantidad: ");
            fflush(stdin);
            scanf("%s",aux);
            for(int i=0 ; i<strlen(aux) ; i++)
            {
                if(!isdigit(aux[i]))
                {
                    error=1;
                    while(error==1)
                    {
                        printf("\nIngrese cantidad correctamente: ");
                        fflush(stdin);
                        scanf("%s",aux);
                        i=-1;
                        error=0;
                    }
                }
            }
            pro[indice].cantidad=atof(aux);
        }
    }
}
void BorrarProducto(eProducto pro[],int tam)
{
    int hallado, error=0, codigoDP;
    char aux[15], confirma;

    system("cls");
    printf("---Eliminar producto---\n");
    printf("\nIngrese Codigo de producto: ");
    fflush(stdin);
    scanf("%s",aux);
    for(int i=0 ; i<strlen(aux) ; i++)
    {
        if(!isdigit(aux[i]))
        {
            error=1;
            while(error==1)
            {
                printf("\nIngrese Codigo de producto correctamente: ");
                fflush(stdin);
                scanf("%s",aux);
                i=-1;
                error=0;
            }
        }
    }
    codigoDP=atoi(aux);
    hallado=BuscarPro(pro,tam,codigoDP);
    if(hallado==-1)
    {
        printf("\nEl Codigo de producto %d no corresponde a ningun producto registrado\n",codigoDP);
    }
    else
    {

        printf("Seguro que desea eliminar el porducto s/n? \n");
        fflush(stdin);
        scanf("%c",&confirma);
        confirma=tolower(confirma);
        while(confirma!='s' && confirma!='n')
        {
            printf("\nRespuesta invalida, desea eliminar el producto?\n");
            fflush(stdin);
            scanf("%c",&confirma);
        }
        if(confirma=='s')
        {
            pro[hallado].isEmpty=VACIO;
            printf("\n\nEl producto se ha eliminado exitosamente\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n");
        }
    }
}
char menuModif(void)
{
    char opcion;

    system("cls");
    printf("Seleccione que desea modificar\n\n");
    printf(" 1 - Codigo de producto\n");
    printf(" 2 - descripcion\n");
    printf(" 3 - importe\n");
    printf(" 4 - cantidad\n");
    printf(" 7 - Salir\n\n\n");
    printf("Opcion ingresada: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
}
void modifEmp(eProducto pro[],int tam)
{
    int hallado, error=0, seguir=1, codigoDP;
    char aux[80], auxF[15], confirma, opcion;

    system("cls");
    printf("---Modificacion de Datos---\n");
    printf("\nIngrese Codigo de producto: ");
    fflush(stdin);
    scanf("%s",aux);
    for(int i=0 ; i<strlen(aux) ; i++)
    {
        if(!isdigit(aux[i]))
        {
            error=1;
            while(error==1)
            {
                printf("\nIngrese Codigo de producto correctamente: ");
                fflush(stdin);
                scanf("%s",aux);
                i=-1;
                error=0;
            }
        }
    }
    codigoDP=atoi(aux);
    hallado=BuscarPro(pro,tam,codigoDP);
    if(hallado==-1)
    {
        printf("\nEl Codigo de producto %d no corresponde a ningun empleado registrado\n",codigoDP);
    }
    else
    {
        printf("\n");
        printf("Confirma la modificacion? s/n \n");
        fflush(stdin);
        scanf("%c",&confirma);
        confirma=tolower(confirma);
        while(confirma!='s' && confirma!='n')
        {
            printf("\nRespuesta invalida, confirma la modificacion?\n");
            fflush(stdin);
            scanf("%c",&confirma);
        }
        if(confirma=='s')
        {
            do
            {
                opcion=menuModif();
                while(opcion<49 || opcion>55 || !isdigit(opcion))
                {
                    system("cls");
                    printf("Ingrese correctamente una de las siguientes opciones\n\n");
                    opcion=menuModif();
                }
                switch(opcion)
                {

                case '1':
                {
                    system("cls");
                    printf("\nIngrese nuevo descripcion: ");
                    fflush(stdin);
                    scanf("%[^\n]",aux);
                    strlwr(aux);
                    printf("\n");
                    for(int i=0 ; aux[i]!='\0' ; i++)
                    {
                        if(i==0)
                        {
                            aux[i]=toupper(aux[i]);
                        }
                        if(aux[i]==' ')
                        {
                            aux[i+1]=toupper(aux[i+1]);
                        }
                    }
                    strcpy(pro[hallado].descripcion,aux);
                    printf("\nModificacion exitosa!\n\n\n");
                    system("pause");
                    break;
                }
                case '2':
                {
                    system("cls");
                    printf("---importe---\n");
                    printf("\nIngrese nuevo importe: ");
                    fflush(stdin);
                    scanf("%c",aux);
                    printf("\n");

                     while(aux[0]<0)
                     {
                         printf("\nIngrese importe correctamente: ");
                         fflush(stdin);
                         scanf("%c",aux);

                    pro[hallado].importe=aux[0];
                    printf("\nModificacion exitosa!\n\n\n");
                    system("pause");
                    break;

                     }
                }
                case '3':
                {
                    system("cls");
                    printf("---Cantidad---\n");
                    printf("\nIngrese nuevo cantidad: ");
                    fflush(stdin);
                    scanf("%s",aux);
                    error=0;
                    printf("\n");
                    for(int i=0 ; i<strlen(aux) ; i++)
                    {
                        if(!isdigit(aux[i]))
                        {
                            error=1;
                            while(error==1)
                            {
                                printf("\nIngrese cantidad correctamente: ");
                                fflush(stdin);
                                scanf("%s",aux);
                                i=-1;
                                error=0;
                            }
                        }
                    }
                    pro[hallado].cantidad=atof(aux);
                    printf("\nModificacion exitosa!\n\n\n");
                    system("pause");
                    break;
                }
                case '4':
                {
                    seguir=0;
                    break;
                }
              }
            }
            while(seguir==1);
        }
        else
        {
            printf("\nSe ha cancelado la modificacion\n\n\n");
        }
    }
}
void listarEmp(eProducto pro[],int tam)
{
    int encuentra=1, vacio=1;

    system("cls");
    printf("---Listar productos---\n");
    for(int i=0 ; i<tam ; i++)
    {
        if(pro[i].isEmpty==LLENO)
        {
            if(encuentra==1)
            {

                printf("|Codigo de producto    |descripcion                |importe|cantidad        |\n");
                encuentra=0;
                vacio=0;
            }
                mostrarPro(pro,i);
            //mostrarPro(pro,i);
        }
    }
    if(vacio==1)
    {
        printf("\nLa agenda esta vacia, no hay nada que listar\n");
    }
}
void orderEmp(eProducto pro[],int tam)
{
    int vacio=1;
    eProducto aux;

    system("cls");
    printf("\n---Ordenar Empleados---\n");
    for(int i=0 ; i<tam-1 ; i++)
    {
        for(int j=i+1 ; j<tam ; j++)
        {
            if(pro[i].cantidad>pro[j].cantidad && pro[i].isEmpty==LLENO && pro[j].isEmpty==LLENO)
            {
                vacio=0;
                aux=pro[i];
                pro[i]=pro[j];
                pro[j]=aux;
            }
            else if(pro[i].cantidad==pro[j].cantidad && pro[i].isEmpty==LLENO && pro[j].isEmpty==LLENO)
            {
                if(strcmp(pro[i].descripcion,pro[j].descripcion)>0)
                {
                    vacio=0;
                    aux=pro[i];
                    pro[i]=pro[j];
                    pro[j]=aux;
                }
            }
        }
    }
    if(vacio==0)
    {
        printf("\n\n***Ordenamiento exitoso!***\n\n\n");
    }
    else
    {
        printf("\nNo hay nada para ordenar\n\n\n");
    }
}
