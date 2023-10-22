#include <string.h>
#include "../Estructuras de Datos/EstructurasDeDatos.h"

///////////////////////////////////////////////////////////////
// Busqueda de anchura
char *busquedaAnchura(Grafo *grafo, int inicio, int fin)
{ // Este algoritmo de anchura está implementado solo para grafos no dirigidos
    int visited[grafo->numVertices];
    int i, j = 0, place;
    Nodo *nodoActual = NULL;
    for (i = 0; i < grafo->numVertices; i++)
    {
        visited[i] = 0;
    }
    Cola *cola = crearCola();
    insertarElementos(cola, inicio);
    int foundPlace = 0;
    place = 0;
    i = 0;
    Nodo *adyacente = NULL;
    while (!vacia(cola))
    {
        place = removerElemento(cola);
        Nodo *adyacente = grafo->listaAdyacencia[place];
        while (adyacente)
        {
            if (adyacente->dato != fin)
            {
                insertarElementos(cola, adyacente->dato);
                adyacente = adyacente->next;
            }
            else
            {
                foundPlace = 1;
                break;
            }
        }
        if (foundPlace == 1)
        {
            visited[j] = place;
            int size = sizeof(visited) / sizeof(int);
            char *camino = calloc(size, 3 * sizeof(char));
            char aux[4];
            i = 0;
            // while(visited[i + 1] != 0){
            for (i = 0; i < size; i++)
            {
                if (i > 0 && visited[i] == 0)
                {
                    sprintf(aux, "%i", fin);
                    strcat(camino, aux);
                    break;
                }
                sprintf(aux, "%i->", visited[i]);
                if (i == 0)
                {
                    strcpy(camino, aux);
                }
                else
                {
                    strcat(camino, aux);
                }
            }
            return camino;
        }
        else
        {
            visited[j++] = place;
        }
    }
    free(cola);
}
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
// Busqueda de anchura de costo uniforme

int busquedaAnchuraCostoUniforme(GrafoPonderado *grafo, int inicio, int fin) {
    // Crear un arreglo para marcar los nodos visitados
    int *visited = (int *)calloc(grafo->numVertices, sizeof(int));
    if (visited == NULL) {
        printf("Error en asignación de memoria para visited.\n");
        return 0;
    }

    // Crear una cola para realizar la búsqueda
    Cola *cola = crearCola();
    insertarElementos(cola, inicio);

    // Crear arreglos para el seguimiento del camino
    int *padre = (int *)calloc(grafo->numVertices, sizeof(int));
    int *pesoCamino = (int *)calloc(grafo->numVertices, sizeof(int));
    if (padre == NULL || pesoCamino == NULL) {
        printf("Error en asignación de memoria para padre y pesoCamino.\n");
        free(visited);
        liberarCola(cola);
        return 0;
    }

    // Búsqueda UCS (Uniform Cost Search)
    while (!vacia(cola)) {
        int nodoActual = removerElemento(cola);
        visited[nodoActual] = 1;

        NodoPonderado *adyacente = grafo->listaAdyacenciaP[nodoActual];
        while (adyacente != NULL) {
            if (!visited[adyacente->destino]) {
                // Agregar el nodo adyacente a la cola
                insertarElementos(cola, adyacente->destino);
                // Registrar el nodo padre y el peso del camino
                padre[adyacente->destino] = nodoActual;
                pesoCamino[adyacente->destino] = adyacente->peso;
            }
            adyacente = adyacente->next;
        }
    }

    // Si el nodo de destino no se visitó, no se encontró un camino
    if (!visited[fin]) {
        free(visited);
        free(padre);
        free(pesoCamino);
        liberarCola(cola);
        printf("No se encontró un camino desde %d a %d.\n", inicio, fin);
        return 0;  // No se encontró un camino
    }

    // Imprimir el camino en el orden correcto
    int nodo = fin;
    int camino[grafo->numVertices];
    int paso = 0;

    while (nodo != inicio) {
        // Almacenar los nodos del camino
        camino[paso] = nodo;
        nodo = padre[nodo];
        paso++;
    }

    // Imprimir el camino desde el nodo de inicio hasta el de destino
    printf("Camino desde %d a %d: %d", inicio, fin, inicio);

    for (int i = paso - 1; i >= 0; i--) {
        // Imprimir el peso y el nodo del camino
        printf("->(%d)->%d", pesoCamino[camino[i]], camino[i]);
    }

    printf("\n");

    // Liberar la memoria y retornar que se encontró un camino
    free(visited);
    free(padre);
    free(pesoCamino);
    liberarCola(cola);

    return 1;  // Se encontró un camino

}
//////////////////////////////////////////////////////////////////
//Busqueda de Profundidad

// void busquedaProfundidad(Grafo *grafo, int inicio) {
//     int *visited = (int *)calloc(grafo->numVertices, sizeof(int));
//     int *camino = (int *)malloc(grafo->numVertices * sizeof(int));
//     Pila *pila = crearPila();
//     insertarElementoPila(pila, inicio);

//     while (!pilaVacia(pila)) {
//         int nodoActual = sacarElemento(pila);

//         if (!visited[nodoActual]) {
//             visited[nodoActual] = 1;
//             Nodo *adyacente = grafo->listaAdyacencia[nodoActual];
//             camino[0] = nodoActual;
//             int depth = 1;

//             while (adyacente) {
//                 int adyacenteNodo = adyacente->dato;

//                 if (!visited[adyacenteNodo]) {
//                     camino[depth] = adyacenteNodo;
//                     depth++;
//                     insertarElementoPila(pila, adyacenteNodo);

//                     // Imprimir el camino encontrado
//                     printf("Camino: ");
//                     for (int i = 0; i < depth; i++) {
//                         printf("%d", camino[i]);
//                         if (i < depth - 1) {
//                             printf("->");
//                         }
//                     }
//                     printf("\n");
//                 }

//                 adyacente = adyacente->next;
//             }
//         }
//     }

//     free(visited);
//     free(camino);
//     liberarPila(pila);
// }
void busquedaProfundidad(Grafo *grafo, int inicio){
    char **caminos = (char **)calloc(grafo->numVertices, sizeof(int *));
    int i;
    int countLevels = 0;
    int visited[grafo->numVertices];
    int size[grafo->numVertices];
    for(int i = 0; i < grafo->numVertices; i++){
        size[i] = 0;
        visited[i] = 0;
    }
    int **niveles = (int  **)calloc(grafo->numVertices, sizeof(int*));
    Nodo *adyacente = (Nodo *)malloc(sizeof(Nodo));
    Pila *pila = crearPila();
    if(niveles == NULL || adyacente == NULL || pila == NULL){
        printf("Error en la asignación de memoria.");
        exit(EXIT_FAILURE);
    }
    insertarElementoPila(pila, inicio);
    while(!pilaVacia(pila)){
        i = 0;
        int nodoActual = sacarElemento(pila);
        adyacente = grafo->listaAdyacencia[nodoActual];
        niveles[countLevels] = (int *)malloc(sizeof(int));
        visited[nodoActual] = 1;
        while(adyacente){
            int temp = adyacente->dato;
            if(!visited[temp]){
                if(niveles[countLevels][i] != NULL){
                    niveles[countLevels][i] = temp;
                    size[countLevels] += 1;
                }else{
                    niveles[countLevels] = realloc(niveles[countLevels], (size + 1));
                    if(niveles[countLevels] == NULL){
                        printf("Error en la asignacion de memoria");
                        free(niveles[countLevels]);
                        exit(EXIT_FAILURE);
                    }else{
                        niveles[countLevels][size[countLevels]] = temp;
                        size[countLevels]++;
                    }
                } //Hasta aqui, en teoría, se tienen los niveles ya mapeados, solo falta regresar hacia los nodos no visitados
                insertarElementoPila(pila,temp);
            }   
            adyacente = adyacente->next;
            i++;
        }     //Los cuales serían del segundo hasta el n nodo de cada nivel 
        countLevels++;
    }////////////////////////////
    //for(int j =  0; )
    //caminos[countLevels - 1]
    //Aqui debes tratar de imprimir el primer camino obtenido, te falta guardarlo
    for(int j = 0; j < grafo->numVertices; j++){
        free(niveles[j]);
    }
    free(niveles);
    liberarPila(pila);
    printf("El camino es: ");
    for(int i = 0; i < grafo->numVertices; i++){
        if(visited[i]){
            printf("%i->",i);
        }
    }
}
//Nivel no visitado Nivel no visitado Nivel no visitado Nivel no visitado Nivel no visitado