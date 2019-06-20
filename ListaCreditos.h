//
// Created by Diez 15-03-19 on 20/06/2019.
//

#ifndef TP_FINAL_AYP3_LISTACREDITOS_H
#define TP_FINAL_AYP3_LISTACREDITOS_H


#include "credito.h"

typedef struct nodo{
    Credito *credito;
    struct nodo *sig;
} *ListaCreditos;

ListaCreditos getnodo();
ListaCreditos BuscarByNombre();
ListaCreditos BuscarByApellido();
ListaCreditos BuscarByNombreYApellido();

#endif //TP_FINAL_AYP3_LISTACREDITOS_H