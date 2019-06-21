# include "cliente.h"
#include <string.h>
//Declaro nuevo cliente, revisar ID
Cliente *nuevo_cliente(int id, char nombre[100], char apellido[100], int edad, char direccion[100])
{
    Cliente *n_cliente;
    n_cliente= malloc(sizeof(n_cliente));
    n_cliente->id = id;
    strcpy(n_cliente->nombre, nombre);
    strcpy(n_cliente->apellido, apellido);
    strcpy(n_cliente->direccion, direccion);
    n_cliente->edad = edad;
    n_cliente->referido = NULL;
    return n_cliente;
}

Cliente *iniciar_cliente()
{
    Cliente *nuevoCliente;
    int id;
    int edad;
    char nombre[100];
    char apellido[100];
    char direccion[100];
    printf("Ingrese el nombre:\n");
    scanf("%s",nombre);
    printf("Ingrese el apellido:\n");
    scanf("%s",apellido);
    printf("Ingrese el id de cliente:\n");
    scanf("%d",&id);
    printf("Ingrese la edad:\n");
    scanf("%d",&edad);
    printf("Ingrese la direcci�n:\n");
    scanf("%s",direccion);
    nuevoCliente=nuevo_cliente(id,nombre,apellido,edad,direccion);
    return nuevoCliente;
}
//Insercion recursiva
void insertar_en_lista(Cliente *n_cliente)
{
    if (n_cliente==NULL)
    {
        n_cliente=iniciar_cliente();
    }
    else
    {
        insertar_en_lista(n_cliente->referido);
    }
}

Cliente *busqueda_por_id(Cliente *cliente, int id)
{
    if (cliente->id==id)
    {
        //Encontrado
        return cliente;
    }
    else if(cliente->referido==NULL)
    {
        //No encontrado, por lo tanto devuelve cliente nulo
        return cliente->referido;
    }
    else
    {
        //Busco recursivamente
        return busqueda_por_id(cliente->referido, id);
    }
}



int main(){
return 0;
}

