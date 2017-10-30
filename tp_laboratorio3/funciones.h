typedef struct
{
    char titulo[50];
    char genero[50];
    char duracion[6];
    char descripcion[500];
    float puntaje;
    char linkImagen[200];
    int state;

}eMovie;

/** \brief Function: mostrar el menu por pantalla y capturar la opcion seleccionada.
*   \return Returns: opcion elegida por el usuario.
*
*/
int menu (void);

/** \brief Function: realizar el alta de una pelicula nueva.
*   \param Request: (en eMovie*) el auxiliar de pelicula, en el cual se ingresan los datos.
*
*/
void altaPelicula(eMovie*);

/** \brief Function: realizar la baja de una pelicula.
*   \param Request: (en eMovie*) el auxiliar de pelicula, en el cual se ingresan los datos a dar de baja.
*
*/
void bajaPelicula(eMovie*);

/** \brief Function: modificar una pelicula.
*   \param Request: (en eMovie*)  el auxiliar de pelicula, en el cual se ingresan los datos de la pelicula a modificar.
*
*/
void modPelicula(eMovie*);

/** \brief Function: generar la pagina .html para ver las peliculas cargadas.
*   \param Request: (en eMovie*) el auxiliar de pelicula, en el cual se ingresan los datos de la pelicula a mostrar.
*
*/
void generaWeb(eMovie*);
