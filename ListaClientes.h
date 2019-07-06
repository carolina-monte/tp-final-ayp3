//
// Created by Diez 15-03-19 on 20/06/2019.
//

#ifndef TP_FINAL_AYP3_LISTACLIENTES_H
#define TP_FINAL_AYP3_LISTACLIENTES_H

#include "cliente.h"
typedef struct nodoCliente{
    Cliente *cliente;
    struct nodoCliente *sig;
} *ListaClientes;

ListaClientes insertarNodoCliente();
ListaClientes BuscarByNombre();
ListaClientes BuscarByApellido();
ListaClientes BuscarByNombreYApellido();
ListaClientes BuscarByRangoDeEdad();
ListaClientes BuscarById(ListaClientes clientes, int id);
ListaClientes DarNuevoCredito();
void imprimirLista(ListaClientes lista);
void pagar_monto();
ListaClientes DarDeBaja();


#endif //TP_FINAL_AYP3_LISTACLIENTES_H
