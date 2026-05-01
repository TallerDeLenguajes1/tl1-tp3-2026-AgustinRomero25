#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarPersonas (char* vector [])
{
    for (int i = 0; i < 5; i++)
    {
        printf ("La persona %d es : %s\n", i + 1, vector [i]); 
    }
}

int buscarNombre (char* vector [], char clave [])
{
    for (int i = 0; i < 5; i++)
    {
        if (strstr(vector[i], clave) != NULL)
        {
            return i;
        }
    }
    return -1;
}

int main ()
{
    char* nombres [5];
    char buffer [100];
    char clave [20] = "santos perez";
    printf("Ingrese 5 nombres de personas\n");

    for (int i = 0; i < 5 ; i++)
    {
        printf("Ingrese el nombre %d: \n", i + 1);
        fflush(stdin);
        gets (buffer);
        int longitud = strlen (buffer) + 1;
        nombres [i] = (char*) malloc(longitud * sizeof(char)); 
        strcpy(nombres[i], buffer);
    }

    printf("\n--- Lista de Personas ---\n");
    mostrarPersonas(nombres);
    printf("\n");

    int resultado = buscarNombre(nombres, clave);

    if(resultado == -1)
    {
        printf("Clave incorrecta.\n");
    } else
    {
        printf("Exito. Clave correcta en el puesto %d.\n", resultado + 1);
    }

    for (int i = 0; i < 5; i++)
    {
        if (nombres [i] != NULL)
        {
            free(nombres[i]);
        }
    }

    return 0;
}