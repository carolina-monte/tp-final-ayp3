# include "cliente.h"
#include <string.h>
//Declaro nuevo cliente, revisar ID
Cliente *nuevo_cliente(char nombre[100], char apellido[100], int id, int edad, char direccion[100])
{
    Cliente *n_cliente;
    n_cliente= (Cliente*)malloc(sizeof(Cliente));
    strcpy(n_cliente->nombre, nombre);
    strcpy(n_cliente->apellido, apellido);
    strcpy(n_cliente->direccion, direccion);
    n_cliente->id=id;
    n_cliente->edad = edad;
    n_cliente->referido = NULL;
    n_cliente->cantidad_de_creditos=0;
    return n_cliente;
}

Cliente *iniciar_cliente()
{
    Cliente *nuevoCliente=NULL;
    int edad;
    char nombre[100];
    char apellido[100];
    int id;
    char direccion[100];
    printf("Ingrese el nombre:\n");
    scanf("%s",nombre);
    printf("Ingrese el apellido:\n");
    scanf("%s",apellido);
    printf("Ingrese la id:\n");
    scanf("%d",&id);
    printf("Ingrese la edad:\n");
    scanf("%d",&edad);
    printf("Ingrese la direccion:\n");
    scanf("%s",direccion);
    nuevoCliente=nuevo_cliente(nombre,apellido,id,edad,direccion);
    if (nuevoCliente == NULL){printf("NULO\n");} //Ya no es null
    return nuevoCliente;
}

double getMontoTotalAPagar(Cliente cliente_sel){
    //Caso si cliente es nulo;
    if(cliente_sel)
    {
        return 0.00;
    }

    //En caso de que la lista de creditos sea nula
    if(cliente_sel->misCreditos==NULL){
        printf("No tiene deuda, puede darse de baja\n");
        return 0.00;
    }else{
    double resultado=0.00;
    //Codigo
    ListaCreditos header=cliente_sel->misCreditos;

    //Mientras no sea nulo, sumar resultado
    while(header!=NULL)
    {
        resultado=resultado+header->credito->montoTotal;

        //Siguiente
        header=header->sig;
    }

    return resultado;
    }

}

void imprimirClientes(Cliente *clientes)
{
    if(clientes==NULL)
    {
        printf("No hay clientes registrados\n");

    }
    else{

        do{
            printf("\nNombre: %s\nApellido: %s\n",clientes->nombre,clientes->apellido);
            clientes=clientes->referido;
        }
        while(clientes!=NULL);
    }
}

void agregar_nuevo_credito(Cliente cliente){

}

void agregar_referido(Cliente agregar, Cliente referido)
{
    //Metodo a testear
    agregar->referido=referido;
}


/*
int main1(){
    Cliente *clientes=NULL;
    int opcion;
    do{
        printf("1. Agregar cliente\n");
        printf("2. Imprimir clientes\n");
        printf("3. Buscar por nombre\n");
        printf("4. Salir\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                insertar_en_lista(clientes);
                break;
            case 2:
                imprimirClientes(clientes);
                break;
            case 3:
                {


                char nombre[100];
                printf("Ingrese el nombre\n");
                scanf("%s",nombre);
                Cliente *clientes_nombre=busqueda_por_nombre(clientes,nombre);
                imprimirClientes(clientes_nombre);

                }
                break;
            case 4:
                break;
            }

    }
    while(opcion!=4);

return 0;
}
*/
int main(){
return 0;
}

