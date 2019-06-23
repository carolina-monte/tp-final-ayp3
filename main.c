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
    FILE *registro_de_empleados;
    int opcion;
    do{
        printf("1. Agregar cliente\n");
        printf("2. Imprimir clientes\n");
        printf("3. Buscar por nombre\n");
        printf("4. Cargar archivo\n");
        printf("5. Salir\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                clientes=insertar_en_lista(clientes);
                break;
            case 2:
                imprimirClientes(clientes);
                break;
            case 3:
            {


                char nombre[100];
                printf("Ingrese el nombre\n");
                scanf("%s",nombre);
                Cliente *clientes_nombre=NULL;
                clientes_nombre=busqueda_por_nombre(clientes,nombre);
                imprimirClientes(clientes_nombre);

            }
                break;
            case 4:{
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

            case 5:
                break;
        }

    }
    while(opcion!=5);

    return 0;
}
