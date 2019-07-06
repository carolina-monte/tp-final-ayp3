//
// Created by Emiliano on 3/7/2019.
#include "ListaCreditos.h"
#include "credito.h"
#include <string.h>

ListaCreditos insertarNodoCredito(ListaCreditos primer_elemento, Cliente *cliente)
{
    if (cliente->cantidad_de_creditos>03){
        printf("Error al insertar rango de edad, coloque correctamente la edad minima y maxima\n");
        return primer_elemento;
    }
    else{
    if(primer_elemento==NULL)
    {
        primer_elemento=malloc(sizeof(ListaCreditos));
        primer_elemento->credito=iniciarCredito(cliente);
        primer_elemento->sig=NULL;
    }
    else
    {
        primer_elemento->sig=insertarNodoCredito(primer_elemento->sig, cliente);
    }
    return primer_elemento;
}
}

ListaCreditos BuscarCreditoByNombre(ListaCreditos primer_elemento,char nombre[100]){

    //Lista a devolver
    ListaCreditos Creditos_por_nombre=NULL;
    //Variable temporal para agregar a la nueva lista
    ListaCreditos ultimo_agregado;
    //Variable para recorrer y no alterar la lista original
    ListaCreditos lista_a_recorrer=primer_elemento;

    //Recorror la lista
    while(lista_a_recorrer!=NULL){

        if(strcmp(lista_a_recorrer->credito->nombre,nombre))
        {
            //En caso de que sea el primer elemento a agregar
            if(Creditos_por_nombre==NULL)
            {
                //Inicializar y copiar datos, en caso de error cambiar por sizeof(struct nodoCreditos)
                Creditos_por_nombre=malloc(sizeof(ListaCreditos));
                Creditos_por_nombre->credito=lista_a_recorrer->credito;
                Creditos_por_nombre->sig=NULL;
                ultimo_agregado=Creditos_por_nombre;
            }else
            {
                //nuevo nodo, en caso de error cambiar por sizeof(struct nodoCreditos)
                ultimo_agregado->sig=malloc((sizeof(ListaCreditos)));
                //avanzo
                ultimo_agregado=ultimo_agregado->sig;
                //copio los datos
                ultimo_agregado->credito=lista_a_recorrer->credito;
                ultimo_agregado->sig=NULL;
            }
        }
        lista_a_recorrer=lista_a_recorrer->sig;
    }
    return Creditos_por_nombre;
}

