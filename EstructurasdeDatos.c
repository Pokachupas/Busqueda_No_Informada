#include <stdlib.h>
#include <stdio.h>

////////Nodos///////////
typedef struct{
    int dato;
    struct Nodo *next;
}Nodo;

Nodo* crearNodo(int data){                     //Esta funcion crea un nuevo nodo y le asigna el valor data
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));  //Se reserva un espacio de memoria del tamaño de
    nodo->dato = data;
    nodo->next = NULL;
    return nodo;
}
////////Nodo Ponderado/////////
typedef struct{
    int peso;
    int destino;
    struct NodoPonderado* next;
}NodoPonderado;

NodoPonderado* crearNodoPonderado(int destino, int peso){
    NodoPonderado *np = (NodoPonderado *)malloc(sizeof(NodoPonderado));
    np->destino = destino;
    np->peso = peso;
    np->next = NULL;
    if(np != NULL){
        return np;
    }else {
        printf("Error en asignacion de memoria NODOPONDERADO.\n");
        return NULL;
    }
}

void liberarNodoPonderado(NodoPonderado *nodo){
    if(nodo->next){
        free(nodo->next);
    }
    if(nodo != NULL){
        free(nodo);
    }
}

////////////Colas/////////////
typedef struct{
    Nodo *firstElement;
    Nodo *lastElement;
}Cola;

Cola* crearCola(){
    Cola *cola = (Cola *)malloc(sizeof(Cola));
    cola->firstElement = cola->lastElement = NULL;
    if(cola == NULL){
        printf("Error en asignacion de memoria COLA.\n");
    }else{
        return cola;
    }
}

void insertarElementos(Cola *cola, int element){
    Nodo *n = crearNodo(element);
    if(n == NULL){
        printf("Error en asignacion de memoria NODOCOLA.\n");
    }else{
        if(cola->firstElement == NULL){
            cola->firstElement = cola->lastElement  = n;
        }else{
            cola->lastElement->next = n;
            cola->lastElement = n;
        }
    }
}

int removerElemento(Cola *cola){
    if(vacia(cola) == 1){
        return -1;
    }else{
        int value = cola->firstElement->dato; 
        Nodo *deletingNode = cola->firstElement;
        cola->firstElement = deletingNode->next;
        free(deletingNode);
        return value;
    } 
}

int vacia(Cola *cola){
    if(cola->firstElement == NULL){
        return 1;
    }else{
        return 0;
    }
}

void liberarCola(Cola *cola) {
    if (cola != NULL) {
        Nodo *actual = cola->firstElement;
        while (actual != NULL) {
            Nodo *temp = actual;
            actual = actual->next;
            free(temp);
        }
        free(cola);
    }
}

///////////Grafos//////////////
typedef struct{
    int numVertices;
    Nodo **listaAdyacencia;
}Grafo;

Grafo* crearGrafo(int numNodos){
    int i;
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    grafo->numVertices = numNodos;
    grafo->listaAdyacencia = (Nodo **)calloc(grafo->numVertices,sizeof(Nodo));
    for(i = 0; i < grafo->numVertices; i++){
        grafo->listaAdyacencia[i] = NULL;
    }
    return grafo;
}
void agregarArista(Grafo *grafo, int origen, int destino){
    //Se crea el primer nodo y se asigna la arista del destino al origen
    Nodo *nodo = crearNodo(destino);
    nodo->next = grafo->listaAdyacencia[origen];
    grafo->listaAdyacencia[origen] = nodo;
    //Se crea el segundo nodo y se asigna la arista
    nodo = crearNodo(origen);
    nodo->next = grafo->listaAdyacencia[destino];
    grafo->listaAdyacencia[destino] = nodo;
}  

void mostrarGrafo(Grafo* grafo){
    for (int v = 0; v < grafo->numVertices; v++) {
        Nodo* temp = grafo->listaAdyacencia[v];
        printf("Lista de adyacencia del vertice %d:\n", v);
        while (temp){
            printf(" -> %d", temp->dato);
            temp = temp->next;
        }
        printf("\n");
    }
}

////////Grafo Ponderado//////////
typedef struct{
    int numVertices;
    NodoPonderado **listaAdyacenciaP;
}GrafoPonderado;

GrafoPonderado *crearGrafoPonderado(int numNodos){
    GrafoPonderado *gp = (GrafoPonderado *)malloc(sizeof(GrafoPonderado));
    if(gp == NULL){
        printf("Error en asignacion de memoria GRAFOPONDERADO.\n");
    }else{
        gp->numVertices = numNodos;
        gp->listaAdyacenciaP = (NodoPonderado **)calloc(gp->numVertices,sizeof(NodoPonderado));
        for(int i = 0; i < gp->numVertices; i++){
            gp->listaAdyacenciaP[i] = NULL;
        }
        return gp;
    }
}

void agregarAristaPonderada(GrafoPonderado *gp, int origen, int destino, int peso){
    NodoPonderado *np = crearNodoPonderado(destino,peso);
    if(np == NULL){
        printf("Error en asignacion de memoria ARISTAPONDERADA.\n");
    }else{
        np->next = gp->listaAdyacenciaP[origen];
        gp->listaAdyacenciaP[origen] = np;
        
        np = crearNodoPonderado(origen,peso);
        np->next = gp->listaAdyacenciaP[destino];
        gp->listaAdyacenciaP[destino] = np;
    }
}

void mostrarGrafoPonderado(GrafoPonderado *gp){
    for(int i = 0; i < gp->numVertices; i++){
        printf("La lista de adyacencia y peso del elemento %i es: \n",i);
        NodoPonderado *temp = gp->listaAdyacenciaP[i];
        while(temp){
            printf("->(%i)->%i",temp->peso,temp->destino);
            temp = temp->next;
        }
        printf("\n");
    }
}

void liberarGrafoPonderado(GrafoPonderado *gp){
    for(int i = 0; i < gp->numVertices; i++){
        liberarNodoPonderado(gp->listaAdyacenciaP[i]);
    }
    free(gp->listaAdyacenciaP);
    free(gp);
}
////////Arreglo dinámico///////
typedef struct{
    NodoPonderado *elements;
    int size;
    int cap;
}din_Array;

din_Array* crearArregloDinamico(){
    din_Array *dn = (din_Array *) malloc(sizeof(din_Array ));
    if(dn != NULL){
        return dn;
    }else{
        printf("Error");
        return NULL;
    }
}
void init_Array(din_Array *array){
    array->size = 0;
    array->elements = calloc(1, sizeof(array->elements));
    if(array->elements == NULL){
        printf("Error en asignacion de memoria INICIANDO ARRAY");
    }
    array->cap = 1;
}
 void increase_Array(din_Array *array, int elements){
    array->elements = realloc(array->elements, (elements + array->cap) * sizeof(array->elements));
    if(array->elements != NULL){
        array->cap += elements;
    }else{
        printf("Error en asignacion de memoria INCREMENTAR ARREGLO.\n");
    }
 }
void add_Elements(din_Array * array, NodoPonderado value){
    increase_Array(array,1);
    if(array->size < array->cap){
        array->elements[array->size] = value;
        array->size++; 
    }else{
        printf("Error, expanda el arreglo.");
    }
}

void show_Array(din_Array array){
    int i = 0;
    printf("Mostrando arreglo: ");
    for(i = 0; i < array.size; i++){
        printf("%d ",array.elements[i].destino);
    }
    printf("\n");
}

void limpiarArray(din_Array *array) {
    for (int i = 0; i < array->size; i++) {
        NodoPonderado *current = &(array->elements[i]);
        while (current != NULL) {
            NodoPonderado *temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(array->elements); // Liberar el arreglo en sí.
    array->size = 0; // Restablecer el tamaño y la capacidad.
    array->cap = 0;
    array->elements = NULL;
}
void reiniciarArray(din_Array *array) {
    limpiarArray(array); // Liberar la memoria actual.
    init_Array(array); // Inicializar el arreglo nuevamente.
}