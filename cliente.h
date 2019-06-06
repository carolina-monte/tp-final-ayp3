//
// Created by Emiliano on 2/6/2019.
//

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
#endif //TP_FINAL_AYP3_CLIENTE_H
