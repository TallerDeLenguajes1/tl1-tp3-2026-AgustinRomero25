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

void buscarNombre (char* vector [])
{
    int id;
    printf("\nIngrese el id: ");
    scanf("%d", &id);
    for (int i = 0; i < 5; i++)
    {
        if (i == id)
        {
            printf("El índice seleccionado fue %d\n La persona seleccionada es %s", i, vector[i]);
        }
    }
    if (id < 0 || id > 5)
    {
        printf("no se encontró el valor buscado.\n");
    }
}

int main ()
{
    
    char* nombres [5];
    char buffer [100];
    printf("Ingrese 5 nombres de personas\n");

    for (int i = 0; i < 5 ; i++)
    {
        printf("Ingrese el nombre %d: \n", i + 1);
        fflush(stdin);
        scanf("%s", buffer);
        int longitud = strlen (buffer) + 1;
        nombres [i] = (char*) malloc(longitud * sizeof(char)); 
        strcpy(nombres[i], buffer);
    }

    printf("\n--- Lista de Personas ---\n");
    mostrarPersonas(nombres);
    printf("\n");

    printf("\n--- Búsqueda de Personas ---\n");
    buscarNombre(nombres);

    for (int i = 0; i < 5; i++)
    {
        if (nombres [i] != NULL)
        {
            free(nombres[i]);
        }
    }

    return 0;
}