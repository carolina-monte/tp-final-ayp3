# include "cliente.h"
#include <string.h>

//Declaro nuevo cliente, revisar ID
Cliente *nuevo_cliente(char nombre[100], char apellido[100], int id, int edad, char direccion[100])
{
    Cliente *n_cliente;
    n_cliente= (Cliente*)malloc(sizeof(Cliente));
    strcpy(n_cliente->nombre, nombre);
    strcpy(n_cliente->apellido, apellido);
    strcpy(n_cliente->direccion, direccion);
    n_cliente->id=id;
    n_cliente->edad = edad;
    n_cliente->referido = NULL;
    n_cliente->cantidad_de_creditos=0;
    return n_cliente;
}

Cliente *iniciarCliente(){
    Cliente *nuevoCliente=NULL;
    int edad;
    char nombre[100];
    char apellido[100];
    int id;
    char direccion[100];
    printf("Ingrese el nombre:\n");
    scanf("%s",nombre);
    printf("Ingrese el apellido:\n");
    scanf("%s",apellido);
    printf("Ingrese la id:\n");
    scanf("%d",&id);
    printf("Ingrese la edad:\n");
    scanf("%d",&edad);
    printf("Ingrese la direccion:\n");
    scanf("%s",direccion);
    nuevoCliente=nuevo_cliente(nombre,apellido,id,edad,direccion);
    if (nuevoCliente == NULL){printf("NULO\n");} //Ya no es null
    return nuevoCliente;
}
void menuCliente(Cliente *cliente){
    int opcion;
    Credito creditoAOperar;
    do{
        printf("1. Agregar cliente recomendado\n");
        printf("2. Dar de alta Credito del cliente\n");
        printf("3. Listar Creditos\n");
        printf("4. Pagar cuota\n");
        printf("5. Cancelar Total del Credito\n");
        printf("6. Salir\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:{
                cliente->referido=iniciarCliente();
            }
                break;
            case 2:{
                cliente->misCreditos =insertarNodoCredito(cliente->misCreditos , cliente);
            }
            case 3:{
                Credito crd = cliente->misCreditos->credito;
                while(crd!=NULL)
                {
                    printf("nombre= %s\n, "
                           "saldo= %lf \n, "
                           "cantidad de cuotas = %d \n,"
                           "monto de las cuotas %lf \n"
                           "cantidad de cuotas restantes= %d \n",
                            crd->nombre,
                            crd->montoTotal,
                            crd->cantidadDeCuotas,
                            crd->montoDeLaCuota,
                            crd->cantidadDeCuotasRestantes);
                    crd=cliente->misCreditos->sig->credito;
                }
            }
            case 4:{
                char nombre[100];
                printf("Ingrese el nombre\n");
                scanf("%s",nombre);
                creditoAOperar = BuscarCreditoByNombre(cliente->misCreditos, nombre)->credito;
                if(creditoAOperar!=NULL)
                {
                    creditoAOperar->cantidadDeCuotasRestantes--;
                }
                else
                {
                    printf("No se encontro un credito de nombre %s.\n",nombre);
                }

            }
            case 5:{
                char nombre[100];
                printf("Ingrese el nombre\n");
                scanf("%s",nombre);
                creditoAOperar = BuscarCreditoByNombre(cliente->misCreditos, nombre)->credito;
                creditoAOperar->cantidadDeCuotasRestantes=0;
            }
            case 6:
                break;
        }
    } while(opcion!=6);
}


