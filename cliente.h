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
Credito misCreditos[10]; //Luego transformar en una lista y un eror que solo permita 10 prestasmos y adaptar el proyecto a lista//  
//agergar lista de prestamos al struct
} Cliente;

//Declaro nuevo cliente, revisar ID
Cliente *nuevo_cliente(int id, char nombre[100], char apellido[100], int edad, char direccion[100]);
//Valores por pantalla del nuevo cliente
Cliente *iniciar_cliente();

//Insercion recursiva
void insertar_en_lista(Cliente *n_cliente);

Cliente *busqueda_por_id(Cliente *cliente, int id);
Cliente busqueda_por_nombre(Cliente clientes[10], char nombre[100]);
Cliente busqueda_por_apellido(Cliente clientes[10], char apellido[100]);
Cliente busqueda_por_nombreYapellido(Cliente clientes[10], char nombre[100], char apellido[100]);

#endif //TP_FINAL_AYP3_CLIENTE_H
