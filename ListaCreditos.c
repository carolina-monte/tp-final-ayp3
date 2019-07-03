//
// Created by Emiliano on 3/7/2019.
#include "ListaCreditos.h"
#include "credito.c"
ListaCreditos insertarNodoCredito(ListaCreditos primer_elemento, Cliente *cliente)
{
    if (cliente->cantidad_de_creditos>03){
        printf("Error al insertar rango de edad, coloque correctamente la edad minima y maxima\n");
        return NULL;
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
        primer_elemento->sig=insertarNodoCredito(primer_elemento->sig);
    }
    return primer_elemento;
}
}
