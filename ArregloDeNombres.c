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

    mostrarPersonas(nombres);
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        if (nombres [i] != NULL)
        {
            free(nombres[i]);
        }
    }

    return 0;
}