#include "cliente.c"
#include <string.h>
#include "ListaClientes.h"

/*
int main() {
    ListaCreditos todosLosCreditos;
    ListaClientes todosLosClientes;
    //Main del proyecto.
    printf("Hello, World!\n");
    return 0;
}*/


int main(){
    ListaCreditos todosLosCreditos=NULL;
    ListaClientes todosLosClientes=NULL;
    Cliente *clientes=NULL;
    FILE *registro_de_empleados;
    int opcion;
    do{
        printf("1. Agregar cliente\n");
        printf("2. Imprimir clientes\n");
        printf("3. Buscar cliente por nombre\n");
        printf("4. Buscar cliente por rango de edad\n");
        printf("5. Buscar cliente por ID\n");
        printf("6. Sub menu de clientes");
        printf("7. Cargar archivo\n");
        printf("8. Salir\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                todosLosClientes=insertarNodoCliente(todosLosClientes);
                break;
            case 2:
                imprimirLista(todosLosClientes);
                break;
            case 3:
            {


                char nombre[100];
                printf("Ingrese el nombre\n");
                scanf("%s",nombre);
                ListaClientes clientesByNombre;
                clientesByNombre=BuscarByNombre(todosLosClientes,nombre);
                imprimirLista(clientesByNombre);
                free(clientesByNombre);

            }
                break;
            case 4:
            {
                int edad_minima;
                int edad_maxima;
                printf("Ingrese ela edad minima\n");
                scanf("%d",edad_minima);
                printf("Ingrese ela edad maxima\n");
                scanf("%d",edad_maxima);
                ListaClientes clientesByEdad;
                clientesByEdad=BuscarByRangoDeEdad(todosLosClientes,edad_minima, edad_maxima);
                imprimirLista(clientesByEdad);
                free(clientesByEdad);

            }
                break;

            case 5:    {


                int ID = 0;
                printf("Ingrese el ID\n");
                scanf("%d",ID);
                ListaClientes clientes_ID=NULL;
                clientes_ID = BuscarByID(todosLosClientes,ID);
                imprimirLista(clientes_ID);
                free(clientes_ID);

            }
            break;

            case 6:{
                int ID = 0;
                printf("Ingrese el ID del cliente a modificar\n");
                scanf("%d",ID);
                ListaClientes clientes_ID=NULL;
                clientes_ID = BuscarByID(todosLosClientes,ID);
                Cliente *cliente = clientes_ID->cliente;
                if (cliente!=NULL)
                {
                    menuCliente(cliente);
                    free(clientes_ID);
                }


            }
                break;

            case 7:{
                registro_de_empleados=fopen("registro.csv","w");
                if(registro_de_empleados==NULL){
                    //En caso de Error
                    fprintf(stderr,"Error al abrir el registro\n");
                    exit(1);
                }
                //Copia para no perder clientes
                Cliente *puntero=clientes;
                while (puntero!=NULL)
                {
                    //escritura
                    fprintf(registro_de_empleados,"%s,%s,%d\n",puntero->nombre,puntero->apellido,puntero->id);
                    puntero=puntero->referido;
                }
                fclose(registro_de_empleados);
            }
            break;

            case 8:
                break;
        }

    }
    while(opcion!=8);

    return 0;
}
