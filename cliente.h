//
// Created by Emiliano on 2/6/2019.
//
#include <stdio.h>
#include <stdlib.h>
#ifndef TP_FINAL_AYP3_CLIENTE_H
#define TP_FINAL_AYP3_CLIENTE_H
typedef struct miCliente{
int id;
char nombre[100];
char apellido[100];
int edad;
char direccion[100];
struct miCliente *referido;
//agergar lista de prestamos al struct
} Cliente;

//Declaro nuevo cliente, revisar ID
Cliente *nuevo_cliente(int id, char nombre[100], char apellido[100], int edad, char direccion[100]);
//Valores por pantalla del nuevo cliente
Cliente *iniciar_cliente();

//Insercion recursiva
void insertar_en_lista(Cliente *n_cliente);

Cliente *busqueda_por_id(Cliente *cliente, int id);

#endif //TP_FINAL_AYP3_CLIENTE_H
