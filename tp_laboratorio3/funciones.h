#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

typedef struct{
    int id;
    char titulo[51];
    char genero[41];
    int duracion;
    char descripcion[2000];
    int puntaje;
    char imagen[500];
    int estado;
}EMovie;


void menu(int cant);

/** \brief Agrega una pelicula al archivo
 *  \param estructura EMovie a agregar
 *  \param char con el titulo
 *  \param char con el genero
 *  \param int con la duracion
 *  \param char con la descripcion
 *  \param int con el puntaje
 *  \param char link de la imagen
 *  \param tamaño del puntero.
 */ void agregarPelicula(EMovie*,char[],char[],int,char[],int,char[],int);


/** \brief Inicializa los estados de la estructura
 *  \param estructura EMovie a agregar
 *  \param tamaño del puntero.
 */ void inicializarEstados(EMovie*,int);

 /** \brief Inicializa los estados de la estructura
 *  \param estructura EMovie a agregar
 *  \param tamaño del puntero.
 */ void inicializarIDs(EMovie* movie,int);


/** \brief Pide los datos a cargar en la estructura y en el archivo
 *  \param estructura EMovie a agregar
 *  \param tamaño del puntero.
 *  \return
 */ int cargarPelicula(EMovie*,int);


/** \brief Crea el archivo
 *  \param estructura EMovie a agregar
 *  \param tamaño del puntero.
 */ void crearArchivo(EMovie*,int);


/** \brief Elimina una pelicula
 *  \param estructura EMovie cob la pelicula a eliminar
 *  \param tamaño del puntero.
 */ void borrarPelicula(EMovie*,int);


/** \brief Modifica una pelicula
 *  \param estructura EMovie con la pelicula a modificar
 *  \param tamaño del puntero.
 */ void modificarPelicula(EMovie*,int);


/** \brief Crea una página web
 *  \param estructura EMovie con la que se creara la pagina
 *  \param tamaño del puntero.
 */ void crearPagina(EMovie*,int);

/** \brief Analiza un string para verificar que no este vacio.
 *  \param  Request: Cadena a analizar.
 *  \return Returns: 1 si la cadena tiene al menos una letra o un numero. 0 si esta vacio.
 */int noVoid(char str[]);

/** \brief Muestra un mensaje y pide al usuario ingresar un string.
 *  \param  Request: mensaje a ser mostrado.
 *  \param  Request: cadena en la que el usuario va a escribir.
 *  \return Returns: NULL.
 */ void getString(char mensaje[],char input[]);


/** \brief Muestra un mensaje, pide al usuario un string y despues valida que solo contenga letras.
 *  \param  Request: mensaje a ser mostrado.
 *  \param  Request: cadena en la que el usuario va a escribir.
 *  \return Returns: 1 si esta todo validado, sino devuelve 0.
 *
 */ int getStringLetras(char mensaje[],char input[]);


/** \brief Muestra un mensaje, pide al usuario un string y despues valida que solo contenga numeros.
 *  \param  Request: mensaje a ser mostrado.
 *  \param  Request: cadena en la que el usuario va a escribir.
 *  \return Returns: 1 si esta todo validado, sino devuelve 0.
 */ int getStringNumeros(char mensaje[],char input[]);


/** \brief Pide un string y valida que contenga solo letras.
 *  \param  Request: cadena que va a ser validada.
 *  \return Returns: 0 si la cadena tiene numero, sino devuelve 1.
 */ int esSoloLetras(char str[]);


/** \brief Pide un string y valida que contenga solo numeros.
 *  \param  Request: cadena que va a ser validada.
 *  \return Returns: 0 si la cadena tiene letras, sino devuelve 1.
 */ int esNumerico(char str[]);


/**
 * \brief Verifica si el valor recibido contiene solo letras y números.
 * \param str Array con la cadena a ser analizada.
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es.
 */ int esAlfaNumerico(char str[]);


/** \brief Pide un string y valida que contenga solo letras o numeros.
 *  \param  Request: Mensaje a mostrar.
 *  \param  Request: Cadena que va a ser validada.
 *  \return Returns: 0 si la cadena tiene simbolos, sino devuelve 1.
 */ int getStringAlfaNumerico(char mensaje[],char input[]);
