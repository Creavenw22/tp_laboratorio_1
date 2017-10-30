#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"

int menu (void)
{
    int opcion;

    system("cls");
    printf("**Menu de opciones**\n\n");
    printf("1. Agregar pelicula\n");
    printf("2. Modificar pelicula\n");
    printf("3. Borrar pelicula\n");
    printf("4. Generar pagina web\n");
    printf("5. Salir\n\n");

    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


void altaPelicula(eMovie* pelicula)
{
    FILE *BD;
    int flag = 0;
    char seguir;
    eMovie* pAux;

    pAux = pelicula;

    do
    {
        system("cls");

        if(flag == 0)
        {
            pAux = malloc(sizeof(eMovie));
            pAux = calloc(10, sizeof(eMovie));

            if(pAux == NULL)
            {
                system("cls");
                printf("ERROR TIPO 1, NO SE PUDO ALOJAR MEMORIA");
                exit(1);
            }

            flag = 1; //el flag permite que la primera vuelta se aloje memoria por primera vez, y a partir de la segunda vuelta se REaloje memoria

        }

        printf("Ingrese titulo:\n");
        fflush(stdin);
        gets(pAux->titulo);

        printf("Ingrese genero:\n");
        fflush(stdin);
        gets(pAux->genero);

        printf("Ingrese duracion: (hh:mm)\n");
        fflush(stdin);
        gets(pAux->duracion);

        printf("Ingrese descripcion:\n");
        fflush(stdin);
        gets(pAux->descripcion);

        printf("Ingrese puntaje: (0 a 100)\n");
        scanf("%f", &pAux->puntaje);

        printf("Ingrese link de imagen:\n");
        fflush(stdin);
        gets(pAux->linkImagen);

        pAux->state = 1;


        printf("\n\nDesea seguir? s/n:");
        fflush(stdin);
        seguir = getch();

        if((BD = fopen("BaseDatos.txt", "wb")) == NULL) //crea archivo binario de base de datos
        {
            BD = fopen("BaseDatos.txt", "ab");
        }

        fflush(stdin);
        fseek(BD, 0L, SEEK_END);
        fwrite(&pAux, sizeof(eMovie), 1, BD);

        fclose(BD);

    }
    while(seguir == 's' || seguir == 'S');




}

void bajaPelicula(eMovie* pelicula)
{
    FILE *BD;
    char Aux[50];
    eMovie *auxPel;
    char decision;
    int flag = 0;
    int flag1 = 0;
    int cont = 0;

    auxPel = pelicula;

    system("cls");

    if((BD = fopen("BaseDatos.txt", "rb")) == NULL) //crea archivo binario de base de datos
    {
        printf("Error, no existe base de datos!\n\n\n");
        system("pause");
    }
    else
    {
        flag1 = 1;
    }

    if(flag1 == 1)
    {

        printf("Ingrese titulo de pelicula a dar de baja: ");
        fflush(stdin);
        gets(Aux);

        rewind(BD);


        while(!feof(BD))
        {
            fseek(BD, cont, SEEK_CUR);
            fread(auxPel, sizeof(eMovie), 1, BD);

            if(strcmp(Aux, auxPel->titulo) == 0 && auxPel->state == 1)
            {

                flag = 1;
                printf("Está seguro que desea realizar la baja? s/n");
                fflush(stdin);
                decision = getch();

                if(decision == 's' || decision == 'S')
                {
                    printf("Accion completada!");
                    auxPel->state = 0;

                }
                else
                {
                    printf("Accion cancelada!");
                }


            }
            else
            {
                cont++;
            }


        }

        if(flag == 0)
        {
            printf("Error, no se encontro pelicula!\n\n");
            system("pause");
        }

    }
}


void modPelicula(eMovie* pelicula)
{
    FILE *BD;
    char Aux[50];
    eMovie *auxPel;
    int flag = 0;
    int flag1 = 0;
    int cont = 0;
    int opcion;

    system("cls");

    if((BD = fopen("BaseDatos.txt", "rb")) == NULL) //crea archivo binario de base de datos
    {
        printf("Error, no existe base de datos!\n\n\n");
        system("pause");
    }
    else
    {
        flag1 = 1;
    }

    if(flag1 == 1)
    {

        printf("Ingrese titulo de pelicula a modificar: ");
        fflush(stdin);
        gets(Aux);

        rewind(BD);

        while(!feof(BD))
        {
            fseek(BD, cont, SEEK_CUR);
            fread(auxPel, sizeof(eMovie), 1, BD);

            if(strcmp(Aux, auxPel->titulo) == 0 && auxPel->state == 1)
            {
                if(strcmp(Aux, auxPel->titulo) == 0)
                {
                    printf("\n\nIngrese opcion a modificar:\n\n");
                    printf("1. Titulo\n2. Genero\n3. Duracion\n4. Descripcion\n5. Puntaje\n6. Link de Imagen\n\nIngrese opcion: ");
                    scanf("%d", &opcion);

                    switch(opcion)
                    {
                    case 1:
                        printf("Ingrese nuevo titulo: ");
                        fflush(stdin);
                        gets(auxPel->titulo);
                        break;
                    case 2:
                        printf("Ingrese nuevo genero: ");
                        fflush(stdin);
                        gets(auxPel->genero);
                        break;
                    case 3:
                        printf("Ingrese nueva duracion: ");
                        fflush(stdin);
                        gets(auxPel->duracion);
                        break;
                    case 4:
                        printf("Ingrese nuvea descripcion: ");
                        fflush(stdin);
                        gets(auxPel->descripcion);
                        break;
                    case 5:
                        printf("Ingrese nuevo puntaje: ");
                        fflush(stdin);
                        scanf("%f", &auxPel->puntaje);
                        break;
                    case 6:
                        printf("Ingrese nuevo link de imagen: ");
                        fflush(stdin);
                        gets(auxPel->linkImagen);
                        break;
                    default:
                        printf("\nError, opcion no valida!");
                        break;
                    }

                    system("cls");
                    printf("Modificacion realizada con exito");
                    system("pause");
                }

            }
            else
            {
                cont++;
            }


        }

        if(flag == 0)
        {
            printf("Error, no se encontro pelicula!\n\n");
            system("pause");
        }

    }

}

void generaWeb(eMovie* pelicula)
{
    FILE *BD;
    eMovie* Aux;

    BD = fopen("BaseDatos.html", "w");

    fread(&Aux, sizeof(eMovie), 1, BD);

    fprintf(BD, "</a> <h3><a href='#'>");
    fprintf(BD, "Titulo: ");
    fprintf(BD, pelicula->titulo); //TITULO
    fprintf(BD, "</a> </h3> <ul>");
    fprintf(BD, "<li>");
    fprintf(BD, "Género:"); //GENERO
    fprintf(BD, pelicula->genero);
    fprintf(BD, "</li>");
    fprintf(BD, "<li>");
    fprintf(BD, "Puntaje: "); //PUNTAJE
    fprintf(BD, &pelicula->puntaje);
    fprintf(BD, "</li>");
    fprintf(BD, "<li>");
    fprintf(BD, "Duración: "); //DURACION
    fprintf(BD, pelicula->duracion);
    fprintf(BD, "</li> </ul>");
    fprintf(BD, "<p>Descripcion: "); //DESCRIPCION
    fprintf(BD, pelicula->descripcion);
    fprintf(BD, "</p> </article>");

    fclose(BD);

    system("cls");
    printf("Pagina Web generada con exito. Encuentrela en el directorio de este programa\n\n\n");
    system("pause");

}

