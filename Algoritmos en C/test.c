#include "Busqueda No Informada/Busqueda_No_Informada.h"
#include <stdio.h>

int main() {
    int numVertices = 8;
    Grafo *grafo = crearGrafo(numVertices);
    // agregarAristaPonderada(gp, 0, 1, 3);
    // agregarAristaPonderada(gp, 0, 2, 2);
    // agregarAristaPonderada(gp, 1, 3, 4);
    // agregarAristaPonderada(gp, 2, 3, 7);
    agregarArista(grafo,0,1);
    agregarArista(grafo,0,2);
    agregarArista(grafo,0,3);
    agregarArista(grafo,1,4);
    agregarArista(grafo,1,5);
    agregarArista(grafo,5,6);






    
    int inicio = 0;
    int fin = 3;
    mostrarGrafo(grafo);
    // if (busquedaAnchuraCostoUniforme(gp, inicio, fin)) {
    //     printf("Se encontro un camino desde %d a %d.\n", inicio, fin);
    // }
    busquedaProfundidad(grafo,inicio);
    liberarGrafo(grafo);
    return 0;
}
