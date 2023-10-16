#include "Busqueda_No_Informada.h"
#include <stdio.h>

int main() {
    int numVertices = 4;
    GrafoPonderado *gp = crearGrafoPonderado(numVertices);
    agregarAristaPonderada(gp, 0, 1, 3);
    agregarAristaPonderada(gp, 0, 2, 2);
    agregarAristaPonderada(gp, 1, 3, 4);
    agregarAristaPonderada(gp, 2, 3, 7);

    int inicio = 0;
    int fin = 3;

    if (busquedaAchuraCostoUniforme(gp, inicio, fin)) {
        printf("Se encontro un camino desde %d a %d.\n", inicio, fin);
    }
    liberarGrafoPonderado(gp);
    return 0;
}
