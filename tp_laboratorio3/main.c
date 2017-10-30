#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int opcion;
    int salir = 0;
    eMovie pelicula;
    eMovie* auxPelicula;

    auxPelicula = &pelicula;

    do
    {
        opcion = menu();

        switch(opcion)
        {
        case 1:
            altaPelicula(auxPelicula);
            break;
        case 2:
            modPelicula(auxPelicula);

            break;
        case 3:
            bajaPelicula(auxPelicula);
            break;
        case 4:
            generaWeb(auxPelicula);
            break;
        case 5:
            printf("\n\nHasta luego!\n\n");
            system("pause");
            salir = 1;
            break;
        default:
            printf("Error, opcion no valida\n\n");
            system("pause");
            break;

        }
    }while(salir == 0);


    return 0;
}
