#include "cliente.c"
#include "ListaClientes.h"

ListaClientes insertarNodoCliente(ListaClientes primer_elemento)
{
    if(primer_elemento==NULL)
    {
        primer_elemento=malloc(sizeof(ListaClientes));
        primer_elemento->cliente=iniciar_cliente();
        primer_elemento->sig=NULL;
    }
    else
    {
        primer_elemento->sig=insertarNodoCliente(primer_elemento->sig);
    }
    return primer_elemento;
}

void imprimirLista(ListaClientes lista){
    ListaClientes lista_a_recorrer=lista
    //Recorror la lista
    while(lista_a_recorrer!=NULL){
        printf("Cliente nombre:%s %s Edad:%d Id:%d",lista_a_recorrer->cliente->nombre,
        lista_a_recorrer->cliente->apellido,lista_a_recorrer->cliente->edad,lista_a_recorrer->cliente->id);
    }
    lista_a_recorrer=lista_a_recorrer->sig;
}

//Devuelve una lista de clientes con el mismo nombre que se pasa por parametro
ListaClientes BuscarByNombre(ListaClientes primer_elemento,char nombre[100]){

    //Lista a devolver
    ListaClientes clientes_por_nombre=NULL;
    //Variable temporal para agregar a la nueva lista
    ListaClientes ultimo_agregado;
    //Variable para recorrer y no alterar la lista original
    ListaClientes lista_a_recorrer=primer_elemento;

    //Recorror la lista
    while(lista_a_recorrer!=NULL){

        if(strcmp(lista_a_recorrer->cliente->nombre,nombre))
        {
            //En caso de que sea el primer elemento a agregar
            if(clientes_por_nombre=NULL==0)
            {
                //Inicializar y copiar datos, en caso de error cambiar por sizeof(struct nodoCliente)
                clientes_por_nombre=malloc(sizeof(ListaClientes));
                clientes_por_nombre->cliente=lista_a_recorrer->cliente;
                clientes_por_nombre->ID=lista_a_recorrer->ID;
                clientes_por_nombre->sig=NULL;
                ultimo_agregado=clientes_por_nombre;
            }else
            {
                //nuevo nodo, en caso de error cambiar por sizeof(struct nodoCliente)
                ultimo_agregado->sig=malloc((sizeof(ListaClientes)));
                //avanzo
                ultimo_agregado=ultimo_agregado->sig;
                //copio los datos
                ultimo_agregado->cliente=lista_a_recorrer->cliente;
                ultimo_agregado->ID=lista_a_recorrer->ID;
                ultimo_agregado->sig=NULL;
            }
        }
        lista_a_recorrer=lista_a_recorrer->sig;
    }
    return clientes_por_nombre;

}
ListaClientes BuscarByRangoDeEdad(ListaClientes clientes, int edad_minima, int edad_maxima)
{
    ListaClientes senialador=clientes;
    ListaClientes lista_resultado=NULL;
    //Esta variable señala siempre el final de la lista para llamarla a la hora de insertar un nuevo elemento
    ListaClientes ultimo_agregado;

    //Cortar en caso nulo
    if(señalador==NULL)
    {
        return clientes;
    }
    if (edad_minima>edad_maxima){
        printf("Error al insertar rango de edad, coloque correctamente la edad minima y maxima\n");
    }
    //Recorrer
    while (senialador!=NULL){
            //En caso de que este dentro del rango de edad
            if(senialador->cliente->edad>=edad_minima &&senialador->cliente->edad<=edad_maxima)
            {
                //Caso primer agregado a la lista resultado
                if(lista_resultado==NULL){
                    lista_resultado=malloc(sizeof(ListaClientes));
                    lista_resultado->cliente=senialador->cliente;
                    lista_resultado->sig=NULL;
                    ultimo_agregado=lista_resultado;
                }
                else
                {
                    ultimo_agregado->sig=malloc((sizeof(ListaClientes)));
                    //avanzo
                    ultimo_agregado=ultimo_agregado->sig;
                    //copio los datos
                    ultimo_agregado->cliente=lista_a_recorrer->cliente;
                    ultimo_agregado->ID=lista_a_recorrer->ID;
                    ultimo_agregado->sig=NULL;
                }
            }
            senialador=senialador->siguiente;

    }
}

int main(void){
    return 0;
}
