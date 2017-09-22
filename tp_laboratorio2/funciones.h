#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>

typedef struct
{
    int dni;
    char nombre[50];
    int edad;
    int estado;


} EPersona;

/** \brief Inicializa los estados en 0 de la estructura
 * \param Request: la estructura ePersona
 * \param Request: el tamaño maximo del vector Persona
 */
void inicializarEstructura(EPersona Persona[],int valor);
/** \brief Muestra nombre, edad y DNI de la estructura Persona
 * \param  Request: estructura ePersona
 * \param  Request: tamaño maximo del vector Persona
 * \return Si encontro al menos 1 persona devuelve valor 1 y sino encontro a nadie retorna 0
 */
int mostrarTodo(EPersona Persona[],int valor);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param Request: valor maximo de la estructura Persona
 * @return Returns: el primer indice disponible
 */
int obtenerEspacioLibre(EPersona Persona[],int valor);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param Request: dni a ser buscado en el array.
 * @param Request: valor maximo de la estructura Persona
 * @return Returns: el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona persona[],int dni,int valor);
/** \brief Muestra un mensaje y pide al usuario ingresar un string
 * \param  Request: mensaje a ser mostrado
 * \param  Request: cadena en la que el usuario va a escribir
 */
void getString(char mensaje[],char input[]);
/** \brief Muestra un mensaje, pide al usuario un string y despues valida que solo contenga letras
 * \param  Request: mensaje a ser mostrado
 * \param  Request: cadena en la que el usuario va a escribir
 * \return Returns: 1 si esta todo validado, sino devuelve 0
 *
 */
int getStringLetras(char mensaje[],char input[]);
/** \brief Muestra un mensaje, pide al usuario un string y despues valida que solo contenga numeros
 * \param  Request: mensaje a ser mostrado
 * \param  Request: cadena en la que el usuario va a escribir
 * \return Returns: 1 si esta todo validado, sino devuelve 0
 */
int getStringNumeros(char mensaje[],char input[]);
/** \brief Pide un string y valida que contenga solo letras
 * \param  Request: cadena que va a ser validada
 * \return Returns: 0 si la cadena tiene numero, sino devuelve 1
 */
int esSoloLetras(char str[]);
/** \brief Pide un string y valida que contenga solo numeros
 * \param  Request: cadena que va a ser validada
 * \return Returns: 0 si la cadena tiene letras, sino devuelve 1
 */
int esNumerico(char str[]);
/** \brief Valida que la edad sea entre 0 y 100
 * \param  Request: edad que va a ser validada
 * \return Returns: 1 si esta todo validado, sino devuelve 0
 */
int validarEdad(int edad);
/** \brief Valida que el DNI no este repetido
 * \param  Request: estructura Persona
 * \param  Request: DNI que el usuario ingreso
 * \param  Request: valor maximo de la estructura Persona
 * \return Returns: 0 si el DNI esta repetido, sino devuelve 1
 */
int validarDni(EPersona persona[],int dni,int valor);
/** \brief Ordena los nombres de A-Z
 * \param  Request: estructura Persona
 * \param  Request: el valor maximo de la estructura Persona
 */
void ordenarNombre(EPersona persona[],int valor);
/** \brief Transfiere los valores auxiliares a la estructura Persona
 * \param  Request: estructura persona
 * \param  Request: dni auxiliar
 * \param  Request: edad auxiliar
 * \param  Request: nombre auxiliar
 * \param  Request: indice libre de la estructura
 */
void transferirOriginal(EPersona persona[],int dni,int edad,char nombre[],int libre);
/** \brief Crea un grafico de barras de 3 acumuladores a partir de las edades
 * \param  Request: acumulador de menores a 18 años
 * \param  Request: acumulador de 19 a 35 años
 * \param  Request: acumulador de mayores a 35 años
 */
void graficoBarras(int menores18,int de19a35,int mayor35);
#endif // FUNCIONES_H_INCLUDED
