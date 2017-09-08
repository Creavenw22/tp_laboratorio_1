#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Pide un numero,lo devuelve y pide la letra en la que se va a utilizar la funcion.
 * \param Pide la letra en la que se va a utilizar.
 * \return El numero ingresado por el scanf.
 */
float IngresarNumero(char);
/** \brief Suma los dos valores ingresados por parametro y muestra el resultado por pantalla.
 * \param  Pide un valor flotante que se deposita en X
 * \param  Pide un valor flotante que se deposita en Y
 */
void Sumar(float,float);

/** \brief Resta los dos valores ingresados por parametro y muestra el resultado por pantalla.
 * \param  Pide un valor flotante que se deposita en X.
 * \param  Pide un valor flotante que se deposita en Y.
 */
void Restar(float,float);

/** \brief Divide los dos valores ingresados por parametro, valida si el segundo valor es 0 y muestra el resultado por pantalla.
 * \param  Pide un valor flotante que se deposita en X.
 * \param  Pide un valor flotante que se deposita en Y.
 */

void Division(float,float);

/** \brief Multiplica los dos valores ingresados por parametro y muestra el resultado por pantalla.
 * \param  Pide un valor flotante que se deposita en X.
 * \param  Pide un valor flotante que se deposita en Y.
 */

void Multiplicacion(float,float);

/** \brief Hace el factorial del dato X y lo muestra por pantalla.
 * \param  Pide un valor flotante que se deposita en X.
 */

void Factorial(float);

/** \brief Muestra todas las operaciones por pantalla.
 * \param  Pide un valor flotante que se deposita en X.
 * \param  Pide un valor flotante que se deposita en Y.
 */
void MostrarTodo(float,float);

#endif // FUNCIONES_H_INCLUDED
