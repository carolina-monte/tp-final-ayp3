# include "credito.h"
#include "string.h"

Credito *nuevo_Credito(double total, double cuota, int cuotas, Cliente *pCliente,char nombre[100]);

Credito *iniciarCredito(Cliente *cliente)
{
    Credito *nuevoCredito=NULL;
    int cantidadDeCuotas;
    double montoTotal;
    double montoDeLaCuota;
    char nombre[100];
    printf("Ingrese el monto total:\n");
    scanf("%lf",montoTotal);
    printf("ingrese nombre del credito\n");
    scanf("%s", nombre);
    printf("Ingrese el monto por cuota:\n");
    scanf("%lf",montoDeLaCuota);
    printf("Ingrese la cantidad de cuotas:\n");
    scanf("%d",&cantidadDeCuotas);
    nuevoCredito=nuevo_Credito(montoTotal, montoDeLaCuota, cantidadDeCuotas, cliente, nombre);
    if (nuevoCredito == NULL){printf("NULO\n");} //Ya no es null
    return nuevoCredito;
}

Credito *nuevo_Credito(double montoTotal, double montoDeLaCuota, int cantidadDeCuotas, Cliente *pCliente, char nombre[100]) {
    Credito n_credito;
    n_credito= (Credito*)malloc(sizeof(Credito));
    n_credito->cliente = pCliente;
    n_credito->montoDeLaCuota=montoDeLaCuota;
    n_credito->montoTotal= montoTotal;
    n_credito->cantidadDeCuotas = cantidadDeCuotas;
    n_credito->cantidadDeCuotasRestantes=cantidadDeCuotas;

    strcpy(n_credito->nombre, nombre);
    pCliente->cantidad_de_creditos++;
    return n_credito;
}


