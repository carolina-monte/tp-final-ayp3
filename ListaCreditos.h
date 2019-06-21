//
// Created by Diez 15-03-19 on 20/06/2019.
//

//#ifndef TP_FINAL_AYP3_LISTACREDITOS_H
//#define TP_FINAL_AYP3_LISTACREDITOS_H


#include "credito.h"

typedef struct nodoCredito{
    int ID;
    Credito *credito;
    struct nodo *sig;
} *ListaCreditos;

ListaCreditos getnodoCredito();
ListaCreditos BuscarByCliente();
ListaCreditos BuscarByMonto();

//#endif //TP_FINAL_AYP3_LISTACREDITOS_H
