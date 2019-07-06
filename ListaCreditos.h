//
// Created by Diez 15-03-19 on 20/06/2019.
//

#ifndef TP_FINAL_AYP3_LISTACREDITOS_H
#define TP_FINAL_AYP3_LISTACREDITOS_H


#include "credito.h"
#include "cliente.h"
typedef struct nodoCredito{
    int ID;
    struct miCredito *credito;
    struct nodoCredito *sig;
} *ListaCreditos;

ListaCreditos getnodoCredito();
ListaCreditos BuscarByCliente();
ListaCreditos BuscarByMonto();
ListaCreditos insertarNodoCredito(ListaCreditos primer_elemento, struct miCliente *cliente);
ListaCreditos BuscarCreditoByNombre(ListaCreditos primer_elemento,char nombre[100]);

#endif //TP_FINAL_AYP3_LISTACREDITOS_H
