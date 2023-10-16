#include "EstructurasDeDatos.h"

void quickSort(din_Array *array, int inicio, int fin){
    if(array == NULL){
        printf("Arreglo vacio.\n");
    }else{
        int izquierda = inicio;
        int derecha = fin;
        NodoPonderado pivote = array->elements[(izquierda + derecha)/2];
        do{
            while(array->elements[izquierda].peso < pivote.peso && izquierda < fin){
                izquierda++;
            }
            while(array->elements[derecha].peso > pivote.peso && derecha > inicio){
                derecha--;
            }
            if(izquierda <= derecha){
                NodoPonderado temp = array->elements[izquierda];
                array->elements[izquierda] = array->elements[derecha];
                array->elements[derecha] = temp; 
                izquierda++;
                derecha--;
            }
        }while(izquierda <= derecha);
        if(inicio <= derecha){
            quickSort(array,inicio,derecha);
        }
        if(fin >= izquierda){
            quickSort(array,izquierda,fin);
        }
    }
}