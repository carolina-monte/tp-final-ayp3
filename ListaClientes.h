//
// Created by Diez 15-03-19 on 20/06/2019.
//

#ifndef TP_FINAL_AYP3_LISTACLIENTES_H
#define TP_FINAL_AYP3_LISTACLIENTES_H

#include "cliente.h"
typedef struct nodo{
    Cliente *cliente;
    struct nodo *sig;
} *ListaClientes;

ListaClientes getnodo();
ListaClientes BuscarByNombre();
ListaClientes BuscarByApellido();
ListaClientes BuscarByNombreYApellido();


#endif //TP_FINAL_AYP3_LISTACLIENTES_H
