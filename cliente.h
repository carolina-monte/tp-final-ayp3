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

//Declaro nuevo cliente, revisar ID
Cliente nuevo_cliente(int id, char nombre[100],
char apellido[100], int edad, char direccion[100])
{
    Cliente n_cliente;
    n_cliente= (Cliente) malloc(sizeof(n_cliente));
    n_cliente.id=id;
    n_cliente.nombre=nombre;
    n_cliente.apellido=apellido;
    n_cliente.edad=edad;
    n_cliente.direccion=direccion;
}
#endif //TP_FINAL_AYP3_CLIENTE_H
