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
        printf("3. Buscar cliente por nombre\n");
        printf("4. Buscar cliente por apellido\n");
        printf("5. Buscar cliente por ID\n");
        printf("6. Cargar archivo\n");
        printf("7. Salir\n");
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
            case 4:
            {


                char apellido[100];
                printf("Ingrese el apellido\n");
                scanf("%s",apellido);
                Cliente *clientes_apellido=NULL;
                clientes_apellido=busqueda_por_apellido(clientes,apellido);
                imprimirClientes(clientes_apellido);

            }
                break;

            case 5:    {


                int ID = 0;
                printf("Ingrese el ID\n");
                scanf("%d",ID);
                Cliente *clientes_ID=NULL;
                clientes_ID=busqueda_por_id(clientes,ID);
                imprimirClientes(clientes_ID);

            }
            break;

            case 6:{
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

            case 7:
                break;
        }

    }
    while(opcion!=7);

    return 0;
}
