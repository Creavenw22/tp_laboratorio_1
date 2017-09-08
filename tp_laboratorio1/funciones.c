 float IngresarNumero(char var)
{
    float num;
    printf("Ingrese un numero entero para %c\n",var);
    scanf("%f",&num);
    return num;
}
void Sumar(float X,float Y)
{
    float resul=X+Y;
    printf("La suma es: %.2f \n", resul);
}
void Restar(float X,float Y)
{
    float resul = X-Y;
    printf("La resta es: %.2f \n",resul);
}

void Division(float X,float Y)
{

    if(Y==0)
    {

        printf("No se puede dividir por cero\n");
    }
    else
    {
      float resul = X/Y;
      printf("La division es: %.2f \n",resul);
    }


}
void Multiplicacion(float X,float Y)
{
    float resul =X*Y;
    printf("La multiplicacion es: %.2f \n", resul);
}
void Factorial(float X)
{
    int AuxX=(int)X;
    int factorial=1;
    if(X<0)
    {

    printf("No se puede sacar factorial de un numero negativo y no se puede poner un decimal.");

    }
    else if(X!=AuxX)
    {
        printf("No se puede hacer el factorial de un numero decimal");
    }
    else
    {
    for (int i=1; i<=(int)X; i++)
        {
            factorial = factorial * i;
        }
         printf("El factorial de X es: %d \n",factorial);
    }


}
void MostrarTodo(float X,float Y)
{
    Sumar(X,Y);
    Restar(X,Y);
    Division(X,Y);
    Multiplicacion(X,Y);
    Factorial(X);
}

