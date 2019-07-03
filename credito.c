# include "credito.h"

Credito *iniciarCredito(Cliente *cliente);
Credito *nuevo_Credito(double total, double cuota, int cuotas, Cliente *pCliente);

Credito *iniciarCredito(Cliente *cliente)
{
    Credito *nuevoCredito=NULL;
    int cantidadDeCuotas;
    double montoTotal;
    double montoDeLaCuota
    printf("Ingrese el monto total:\n");
    scanf("%lf",montoTotal);
    printf("Ingrese el monto por cuota:\n");
    scanf("%lf",montoDeLaCuota);
    printf("Ingrese la cantidad de cuotas:\n");
    scanf("%d",&cantidadDeCuotas);
    nuevoCredito=nuevo_Credito(montoTotal, montoDeLaCuota, cantidadDeCuotas, cliente);
    if (nuevoCredito == NULL){printf("NULO\n");} //Ya no es null
    return nuevoCredito;
}

Credito *nuevo_Credito(double montoTotal, double montoDeLaCuota, int cantidadDeCuotas, Cliente *pCliente) {
    Credito *n_credito;
    n_credito= (Credito*)malloc(sizeof(Credito));
    n_credito->cliente = pCliente;
    n_credito->montoDeLaCuota=montoDeLaCuota;
    n_credito->montoTotal= montoTotal;
    n_credito->cantidadDeCuotas = cantidadDeCuotas;
    n_credito->cantidadDeCuotasRestantes=cantidadDeCuotas;
    pCliente->cantidad_de_creditos++;
    return n_credito;
}


