#include "cliente.c"
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
                //Inicializar y copiar datos
                clientes_por_nombre=malloc(sizeof(ListaClientes));
                clientes_por_nombre->cliente=lista_a_recorrer->cliente;
                clientes_por_nombre->ID=lista_a_recorrer->ID;
                clientes_por_nombre->sig=NULL;
                ultimo_agregado=clientes_por_nombre;
            }else
            {
                //nuevo nodo
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
    return clientes_por:nombre;

}
