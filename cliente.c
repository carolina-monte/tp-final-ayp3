# include "cliente.h"
#include <string.h>
//Declaro nuevo cliente, revisar ID
Cliente *nuevo_cliente(int id, char nombre[100], char apellido[100], int edad, char direccion[100])
{
    Cliente *n_cliente;
    n_cliente= (Cliente*)malloc(sizeof(Cliente));
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
    Cliente *nuevoCliente=NULL;
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
    printf("Ingrese la direccion:\n");
    scanf("%s",direccion);
    nuevoCliente=nuevo_cliente(id,nombre,apellido,edad,direccion);
    if (nuevoCliente == NULL){printf("NULO\n");} //Ya no es null
    return nuevoCliente;
}
//Insercion recursiva
Cliente *insertar_en_lista(Cliente *n_cliente)
{
    if (n_cliente==NULL)
    {
        return iniciar_cliente();
    }
    else
    {
        n_cliente->referido=insertar_en_lista(n_cliente->referido);
    }
    return n_cliente;
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

Cliente *busqueda_por_nombre(Cliente *clientes, char nombre[100])
{
    //Devuelve lista de clientes con el mismo nombre
    Cliente *cliente_por_nombre=NULL;//Header nueva lista
    Cliente *fin;//recorre clientes_por_nombre
    Cliente *puntero=clientes;
    //Verificar al inicio

    while(NULL != puntero){

        //Elemento sin referencia a siguiente
        if(puntero->nombre==nombre){
            if(cliente_por_nombre==NULL)
            {
                cliente_por_nombre=(Cliente*)malloc(sizeof(Cliente));
                strcpy(cliente_por_nombre->nombre,puntero->nombre);
                strcpy(cliente_por_nombre->apellido,puntero->apellido);
                cliente_por_nombre->id=puntero->id;
                cliente_por_nombre->edad=puntero->edad;
                strcpy(cliente_por_nombre->direccion,puntero->direccion);
                cliente_por_nombre->referido=NULL;
                fin=cliente_por_nombre;

            }
            else
            {
                //Inicializo nuevo nodo
                fin->referido=(Cliente*)malloc(sizeof(Cliente));
                //Avanzo
                fin=fin->referido;
                //Copia los datos
                strcpy(fin->nombre,puntero->nombre);
                strcpy(fin->apellido,puntero->apellido);
                fin->id=puntero->id;
                fin->edad=puntero->edad;
                strcpy(fin->direccion,puntero->direccion);
                fin->referido=NULL; //Preparo para el siguiente nodo
            }
        }

        puntero=puntero->referido;

    }
    return cliente_por_nombre;

}

Cliente *busqueda_por_apellido(Cliente *clientes, char apellido[100])
{
    return clientes;
}
Cliente *busqueda_por_nombreYapellido(Cliente clientes[10], char nombre[100], char apellido[100])
{
    return clientes;
}

void imprimirClientes(Cliente *clientes)
{
    if(clientes==NULL)
    {
        printf("No hay clientes registrados\n");

    }
    else{

        do{
            printf("Nombre: %s\nApellido: %s\n",clientes->nombre,clientes->apellido);
            clientes=clientes->referido;
        }
        while(clientes!=NULL);
    }
}




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
                if(clientes==NULL){
                    printf("Sigue siendo NULL\n");//Sigue siendo nulo!!!!
                }else{
                    printf("Apellido nuevo cliente: %2\n",clientes->referido->apellido);
                }
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
//int main(){
//return 0;
//}

