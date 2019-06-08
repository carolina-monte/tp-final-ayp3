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
    n_cliente.referido=NULL;
    return n_cliente;
}
//Valores por pantalla del nuevo cliente
Cliente iniciar_cliente()
{
    Cliente nuevoCliente;
    int id;
    int edad;
    char nombre[100];
    char apellido[100];
    char direccion[100];
    printf("Ingrese el nombre:\n");
    scanf("%s",nombre);
    printf("Ingrese el apellido:\n");
    scanf("%s",apellido);
    printf("Ingrese el id de cliente:\n");
    scanf("%d",&id);
    printf("Ingrese la edad:\n");
    scanf("%d",&edad);
    printf("Ingrese la dirección:\n");
    scanf("%s",direccion);
    nuevoCliente=nuevo_cliente(id,nombre,apellido,edad,direccion);
    return nuevoCliente;
}
#endif //TP_FINAL_AYP3_CLIENTE_H
