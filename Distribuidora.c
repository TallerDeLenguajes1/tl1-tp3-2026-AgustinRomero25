#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos [] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
 // “CantidadProductosAPedir”
} typedef Cliente;

float PrecioTotal (Producto producto)
{
    return producto.Cantidad * producto.PrecioUnitario;
}

void cargarDatos (Cliente *lista, int cantClientes) 
{
    char buffer [100];
    for (int i = 0; i < cantClientes; i++)
    {
        printf("Ingrese el Nombre del cliente numero %d: ", i + 1);
        fflush(stdin);
        gets(buffer);

        lista[i].ClienteID = i;
        lista[i].NombreCliente = (char *) malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(lista[i].NombreCliente, buffer);
        lista[i].CantidadProductosAPedir = rand() % 5 + 1;
        lista[i].Productos = (Producto *) malloc(lista[i].CantidadProductosAPedir * sizeof(Producto));

        for(int j = 0; j < lista[i].CantidadProductosAPedir; j++)
        {
            lista[i].Productos[j].ProductoID = j;
            lista[i].Productos[j].Cantidad = rand() % 10 + 1;
            lista[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
            lista[i].Productos[j].PrecioUnitario = 10 + (float) (rand() % 91);
        }
    }
}

void mostrarDatos (Cliente *lista, int cantClientes)
{
    printf("\n------------------------ Datos Clientes -----------------------\n");
    for (int i = 0; i < cantClientes; i++)
    {
        float precioTotal = 0;
        printf("ID de Cliente: %d\n",lista[i].ClienteID);
        printf("Nombre: %s\n",lista[i].NombreCliente);
        printf("Cantidad de Productos a Pedir: %d\n",lista[i].CantidadProductosAPedir);

        for (int j = 0; j < lista[i].CantidadProductosAPedir; j++)
        {
            printf("\n------------------------ Producto %d ------------------------\n", j + 1);
            printf("ID del producto: %d\n",lista[i].Productos[j].ProductoID);
            printf("Cantidad de productos: %d\n",lista[i].Productos[j].Cantidad);
            printf("Tipo: %s\n",lista[i].Productos[j].TipoProducto);
            printf("Precio Unitario: %.2f\n",lista[i].Productos[j].PrecioUnitario);
            precioTotal += PrecioTotal(lista[i].Productos[j]);
        }

        printf("\n--------------------------------------------------------------\n");
        printf("\nTotal a pagar: $%.2f ARS\n", precioTotal);
        printf("\n--------------------------------------------------------------\n");
        printf("\n--------------------------------------------------------------\n");
    }
}

int main ()
{
    srand(time(NULL));
    int cantClientes;

    printf("\n------------------------------ DISTRIBUIDORA : MODULO PREVENTISTAS -----------------------------\n");
    printf("Ingrese la cantidad de clientes (máx 5): ");
    scanf("%d", &cantClientes);
    if (cantClientes <= 0 || cantClientes > 5)
    {
        printf("\nIngrese una cantidad de clientes Válida.\n"); 
        return 1;
    } else
    {
        Cliente *clientes = (Cliente*) malloc (cantClientes * sizeof(Cliente));
        printf("La cantidad de clientes registrados es %d.\n",cantClientes);
        cargarDatos(clientes, cantClientes);
        mostrarDatos(clientes, cantClientes);

        for (int i = 0; i < cantClientes; i++)
        {
            free(clientes[i].Productos);
            free(clientes[i].NombreCliente);
        }
        free(clientes);
    }

    return 0;
}