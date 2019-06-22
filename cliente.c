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

Cliente *busqueda_por_nombre(Cliente *clientes, char nombre[100])
{
    //Devuelve lista de clientes con el mismo nombre
    Cliente *cliente_por_nombre=NULL;
    Cliente *p;
    Cliente *puntero=clientes;
    //Verificar al inicio

    while(puntero){
        if (puntero->nombre==nombre)
        {
            //Elemento sin referencia a siguiente

            if(cliente_por_nombre==NULL)
            {
                p=malloc(sizeof(Cliente));
                strcpy(p->nombre,puntero->nombre);
                strcpy(p->apellido,puntero->apellido);
                strcpy(p->direccion,puntero->direccion);
                p->edad=puntero->edad;
                p->id==puntero->id;
                p->misCreditos=puntero->misCreditos;
                cliente_por_nombre=p;
                p->referido=NULL;
                p->referido=malloc(sizeof(Cliente));
            }
            else
            {

                p->referido=puntero;
            }

            p=p->referido;
            puntero=puntero->referido;

        }
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
    Cliente *c_puntero=clientes;
    if(clientes==NULL)
    {
        printf("No hay clientes registrados\n");

    }
    else{
        while(c_puntero!=NULL)
        {
            printf("Nombre: %s\n Apellido: %s ",clientes->nombre,clientes->apellido);
            c_puntero=c_puntero->referido;
        }
    }
}




int main(){
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

