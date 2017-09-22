#include "funciones.h"

void inicializarEstructura(EPersona Persona[],int valor)
{
    for(int i=0; i<valor; i++)
    {
        Persona[i].estado=0;
    }
}

int mostrarTodo(EPersona Persona[],int valor)
{
    int flag=1;
    printf("Nombre\t\t\tEdad\t\t\tDNI\n");
    for(int i=0; i<valor; i++)
    {
        if(Persona[i].estado==1)
        {
            printf("%s\t\t\t%d\t\t\t%d\n",Persona[i].nombre,Persona[i].edad,Persona[i].dni);
            flag=0;
        }

    }
    if(flag)
    {
        system("cls");
        return 0;
    }
    else
    {
        return 1;
    }

}

int obtenerEspacioLibre(EPersona Persona[],int valor)
{
    for(int i=0; i<valor; i++)
    {
        if(Persona[i].estado==0)
        {
            return i;
        }
    }
    return -1;
}

int buscarPorDni(EPersona persona[],int dni,int valor)
{
    for(int i=0; i<valor; i++)
    {
        if(persona[i].estado==1 && persona[i].dni==dni)
        {
            return i;
        }
    }
    return -1;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int validarEdad(int edad)
{
    if(edad>99 || edad<0)
    {
        return 0;
    }
    return 1;
}

int validarDni(EPersona persona[],int dni,int valor)
{
    for(int i=0; i<valor; i++)
    {
        if(persona[i].dni==dni && persona[i].estado==1)
        {
            return 0;
        }
    }
    return 1;

}

void ordenarNombre(EPersona Persona[],int valor)
{
    EPersona auxiliarPersona;
    for(int i=0; i <valor-1; i++)
    {
        if(Persona[i].estado == 0)
        {
            continue;
        }
        for(int j=i+1; j < valor; j++)
        {
            if(Persona[j].estado == 0)
            {
                continue;
            }
            if(strcmp(Persona[i].nombre,Persona[j].nombre) > 0)
            {
                auxiliarPersona = Persona[j];
                Persona[j] = Persona[i];
                Persona[i] = auxiliarPersona;
                //
            }
        }
    }

}

void transferirOriginal(EPersona Persona[],int dni,int edad,char nombre[],int libre)
{
    strlwr(nombre);
    for(int i=0; i<50; i++)
    {
        if(nombre[i]==' ')
        {
            nombre[i+1]=toupper(nombre[i+1]);
        }
    }
    nombre[0]=toupper(nombre[0]);
    Persona[libre].dni=dni;
    Persona[libre].edad=edad;
    strcpy(Persona[libre].nombre,nombre);
    Persona[libre].estado=1;
    printf("Se ha dado de alta satisfactoriamente.\n");
}

void graficoBarras(int menores18,int de19a35,int mayor35)
{
    int mayorTodos;
    int flag=0,flag2=0;

    if(menores18 >= de19a35 && menores18 >= mayor35)
    {
        mayorTodos = menores18;
    }
    else if(de19a35 >= menores18 && de19a35 >= mayor35)
    {
        mayorTodos = de19a35;
    }
    else
    {
        mayorTodos = mayor35;
    }

for(int i=mayorTodos;i>0; i--)
{
    printf("\n%02d|",i);
    if(i<= menores18)
    {
        printf("\t%c",219);
        flag=2;
        flag2=1;
    }
    if(i<=de19a35)
    {
        flag=1;

        if(flag2==0)
        {
            printf("\t\t\t%c",219);
        }
        if(flag2==1)
        {
            printf("\t\t%c",219);
        }
    }
    if(i<= mayor35)
    {
        if(flag==0)
        {
             printf("\t\t\t\t\t");
        }

        if(flag==1)
        {
             printf("\t\t");
        }
        if(flag==2)
        {
            printf("\t\t\t\t");
        }
    }
}
printf("\n--|----------------------------------------------\n|      <18            19-35            >35\n\nCant:   %d               %d               %d",menores18,de19a35,mayor35);
}

