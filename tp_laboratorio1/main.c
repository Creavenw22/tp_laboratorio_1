#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int flag1=0;
    int flag2=0;
    float numX;
    float numY;
    char confirm='s';
    int opcion=0;


    while(confirm=='s')
    {
        if(flag1==0)
        {
        printf("1- Ingresar primer operando X \n");
        }
        else
        {
        printf("1- Ingresar primer operando X (X=%.2f)\n",numX);
        }
        if(flag2==0)
        {
            printf("2- Ingresar segundo operando Y \n");
        }
        else
        {
            printf("2- Ingresar segundo operando Y (Y=%.2f)\n",numY);
        }
        printf("3- Calcular la suma (X+Y)\n");
        printf("4- Calcular la resta (X-Y)\n");
        printf("5- Calcular la division (X/Y)\n");
        printf("6- Calcular la multiplicacion (X*Y)\n");
        printf("7- Calcular el factorial (X!)\n");
        printf("8- Calcular todas las operaciones.\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            //INGRESAR X
            case 1:
                numX=IngresarNumero('X');
                flag1=1;
                break;
            //INGRESAR Y
            case 2:
                numY=IngresarNumero('Y');
                flag2=1;
                break;
            //SUMA ENTRE X e Y
            case 3:
                if(flag1==0 || flag2==0)
                {
                    printf("No se puede realizar una operacion ya que no hay valores cargados.");
                }
                else
                {
                   Sumar(numX,numY);
                }
                break;
            //RESTA ENTRE X e Y
            case 4:
                if(flag1==0 || flag2==0)
                {
                    printf("No se puede realizar una operacion ya que no hay valores cargados.");
                }
                else
                {
                Restar(numX,numY);
                }
                break;
            //DIVISION ENTRE X e Y
            case 5:
                if(flag1==0 || flag2==0)
                {
                    printf("No se puede realizar una operacion ya que no hay valores cargados.");
                }
                else
                {
                Division(numX,numY);
                }
                break;
            //MULTIPLICACION ENTRE X e Y
            case 6:
                if(flag1==0 || flag2==0)
                {
                    printf("No se puede realizar una operacion ya que no hay valores cargados.");
                }
                else
                {
                Multiplicacion(numX,numY);
                }
                break;
            //FACTORIAL DE X
            case 7:
                if(flag1==0)
                {
                    printf("No se puede realizar una operacion ya que no hay valores cargados.");
                }
                else
                {
                Factorial(numX);
                }
                break;
            //MOSTRAR TODO
            case 8:
                if(flag1==0 || flag2==0)
                {
                    printf("No se puede realizar una operacion ya que no hay valores cargados.");
                }
                else
                {
                MostrarTodo(numX,numY);
                }
                break;
            //NO CONTINUAR
            case 9:
                confirm = 'n';
                break;
            default:
                printf("Error, Reingrese una opcion correcta (1-9)");
                break;
        }
        getch();
        system("cls");
    }
 return 0;
}



