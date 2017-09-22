#include "funciones.h"
#define US 20

int main()
{
    EPersona Persona[US];
    char confirm='s';
    char ans='S';
    int opcion=0;
    int libre,auxDni,auxEdad;;
    char auxNombreAr[50];
    char auxDniAr[50];
    char auxEdadAr[50];
    int menores18=0;
    int de19a35=0;
    int mayor35=0;
    //COLOCA 0 EN EL VECTOR ESTRUCTURA PERSONA
    inicializarEstructura(Persona,US);
    //MENU PRINCIPAL
    while(confirm=='s')
    {
        printf("1- AGREGAR PERSONA\n");
        printf("2- BORRAR PERSONA\n");
        printf("3- MOSTRAR LISTA ORDENADA POR NOMBRE\n");
        printf("4- MOSTRAR GRAFICO DE EDADES\n");
        printf("5- SALIR\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        //ALTA
        case 1:
            //OBTIENE INDICE LIBRE DE LA ESTRUCTURA
            libre=obtenerEspacioLibre(Persona,US);
            if(libre == -1)
            {
                printf("No quedan lugares libres\n");
                break;
            }
            //VALIDA QUE NO HAYA LETRAS EN EL DNI
            if(!getStringNumeros("Ingrese dni: ",auxDniAr))
            {
                printf("El DNI solo debe tener numeros.\n");
                break;
            }
            auxDni = atoi(auxDniAr);
            //VALIDA QUE EL DNI NO ESTE REPETIDO
            if(!validarDni(Persona,auxDni,US))
            {
                printf("El DNI ingresado ya existe.\n");
                break;
            }
            //VALIDA QUE NO HAYA NUMEROS EN EL NOMBRE
            if(!getStringLetras("Ingrese nombre: ",auxNombreAr))
            {
                printf("El nombre tiene que tener solo letras.\n");
                break;
            }
            //VALIDA QUE NO HAYA LETRAS EN LA EDAD
            if(!getStringNumeros("Ingrese edad: ",auxEdadAr))
            {
                printf("La edad solo debe tener numeros.\n");
                break;
            }
            auxEdad = atoi(auxEdadAr);
            //VALIDA QUE LA EDAD ESTE ENTRE 0 Y 100
            if(!validarEdad(auxEdad))
            {
                printf("La edad debe estar entre 0 y 100.\n");
                break;
            }
            //ACUMULADORES PARA EL GRAFICO
            if(auxEdad<19)
            {
                menores18++;
            }
            else if(auxEdad>18 || auxEdad<36)
            {
                de19a35++;
            }
            else
            {
                mayor35++;
            }
            //TRANSFIERE LOS DATOS DE AUXILIARES A LA ESTRUCTURA ORIGINAL
            transferirOriginal(Persona,auxDni,auxEdad,auxNombreAr,libre);
            break;
        case 2:
            //BAJA
            //VALIDA QUE EL DNI INGRESADO NO CONTENGA LETRAS
            if(!getStringNumeros("Ingrese DNI a dar de baja: ",auxDniAr))
            {
                printf("DNI invalido.\n");
                break;
            }
            //BUSCA EL DNI INGRESADO Y VALIDA SI NO SE ENCUENTRA
            libre=buscarPorDni(Persona,atoi(auxDniAr),US);
            if(libre==-1)
            {
                printf("El DNI es inexistente.\n");
                break;
            }
            printf("¿Seguro que quiere dar de baja a esta persona? s/n \nDni:%d\nNombre:%s\nEdad:%d\n",Persona[libre].dni,Persona[libre].nombre,Persona[libre].edad);
            ans=getche();
            //ELIMINA A LA PERSONA O LO CANCELA
            if(ans=='s')
            {
                printf("\nPersona eliminada satisfactoriamente.\n");
                Persona[libre].estado=0;
                // RESTA EL CONTADOR DE EDAD DE ESA PERSONA ELIMINADA
                if(Persona[libre].edad<19)
                {
                    menores18--;
                }
                else if(Persona[libre].edad>18 || Persona[libre].edad<36)
                {
                    de19a35--;
                }
                else
                {
                    mayor35--;
                }
            }
            else
            {
                printf("Accion cancelada.\n");
            }
            break;
        case 3:
            //ORDENA LOS NOMBRES DE A-Z
            ordenarNombre(Persona,US);
            //MUESTRA TODOS Y VALIDA SI HAY PERSONA PARA MOSTRAR
            if(!mostrarTodo(Persona,US))
            {
                printf("No hay altas.\n");
            }
            break;
        case 4:
            //VALIDA QUE HAYA EDADES (USO LOS ACUMULADORES Y NO LA ESTRUCTURA PARA HARDCODEAR SI SE NECESITA PROBAR.)
            if(menores18==0 && de19a35==0 && mayor35==0)
            {
                printf("No hay altas suficientes para realizar el grafico.\n");
                break;
            }
            //GRAFICA CON LOS 3 ACUMULADORES
            graficoBarras(menores18,de19a35,mayor35);
            break;
        case 5:
            confirm = 'n';
            break;
        default:
            // VALIDA QUE NO SE INGRESE OTRA OPCION
            printf("ERROR: Opcion invalida.\n");
            break;
        }
        //TERMINA PIDE UNA LETRA PARA CONTINUAR Y LIMPIA PANTALLA
        getch();
        system("cls");
    }
    return 0;
}
