#include "cliente.c"
#include <string.h>

/*
int main() {
    ListaCreditos todosLosCreditos;
    ListaClientes todosLosClientes;
    //Main del proyecto.
    printf("Hello, World!\n");
    return 0;
}*/


int main(){
    Cliente *clientes=NULL;
    int opcion;
    do{
        printf("1. Agregar cliente\n");
        printf("2. Imprimir clientes\n");
        printf("3. Buscar por nombre\n");
        printf("4. Salir\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                clientes=insertar_en_lista(clientes);
                if(clientes->referido==NULL){
                    printf("Hurra por NULL\n");//Sigue siendo nulo!!!!
                }else{
                    printf("Apellido nuevo cliente: %s\n",clientes->referido->apellido);
                }
                break;
            case 2:
                imprimirClientes(clientes);
                break;
            case 3:
            {


                char nombre[100];
                printf("Ingrese el nombre\n");
                scanf("%s",nombre);
                Cliente *clientes_nombre=busqueda_por_nombre(clientes,nombre);
                imprimirClientes(clientes_nombre);

            }
                break;
            case 4:
                break;
        }

    }
    while(opcion!=4);

    return 0;
}
