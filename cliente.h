//
// Created by Emiliano on 2/6/2019.
//
#ifndef TP_FINAL_AYP3_CLIENTE_H
#define TP_FINAL_AYP3_CLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include "ListaCreditos.h"


typedef struct miCliente{
char nombre[100];
char apellido[100];
int edad;
char direccion[100];
struct miCliente *referido;
struct nodoCredito *misCreditos;
} Cliente;

//Declaro nuevo cliente, revisar ID
Cliente *nuevo_cliente(char nombre[100], char apellido[100], int edad, char direccion[100]);
//Valores por pantalla del nuevo cliente
Cliente *iniciar_cliente();

//Insercion recursiva
/*Cliente *insertar_en_lista(Cliente *n_cliente);
//Busquedas
Cliente *busqueda_por_id(Cliente *cliente, int id);
Cliente *busqueda_por_nombre(Cliente clientes[10], char nombre[100]);
Cliente *busqueda_por_apellido(Cliente clientes[10], char apellido[100]);
Cliente *busqueda_por_nombreYapellido(Cliente clientes[10], char nombre[100], char apellido[100]);
*/
#endif //TP_FINAL_AYP3_CLIENTE_H
