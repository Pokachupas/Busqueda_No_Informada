#include "EstructurasDeDatos.c"

//Tipos de estructuras
struct Nodo;
struct NodoPonderado;
struct Cola;
struct Grafo;
struct GrafoPonderado;
struct din_Array;

//Metodos de arreglos dinamicos
din_Array* crearArregloDinamico();
void init_Array(din_Array *array);
void increase_Array(din_Array *array, int elements);
void add_Elements(din_Array * array, NodoPonderado value);
void show_Array(din_Array array);
void limpiarArray(din_Array *array);
void reiniciarArray(din_Array *array);

//Metodos de Nodo
Nodo* crearNodo(int data);

//Metodos de Nodo Ponderado
 NodoPonderado *crearNodoPonderado(int destino, int peso);
 void liberarNodoPonderado(NodoPonderado *nodo);

//Metodos de Cola
Cola* crearCola();
void insertarElementos(Cola *cola, int n);
int removerElemento(Cola  *cola);
int vacia(Cola *cola);


//Metodos de Grafos
Grafo* crearGrafo(int numNodos);
void agregarArista(Grafo *grafo, int origen, int destino);
void mostrarGrafo(Grafo *grafo);

//Metodos de Grafos Ponderados
GrafoPonderado* crearGrafoPonderado(int numNodos);
void agregarAristaPonderada(GrafoPonderado *gp, int origen, int destino, int peso);
void mostrarGrafoPonderado(GrafoPonderado *gp);
void liberarGrafoPonderado(GrafoPonderado *gp);