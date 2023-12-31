#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) { 
    int maximo=0;
    for (int i=0 ;i<size;i++){
        if (arr[i]>maximo){
            maximo=arr[i];
        }
    }
    return maximo;
    
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
  int start=0;
  int end=size-1;
  while (start<end){
    int temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;
    start++;
    end--;
      
  }
  
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize){ 
  int j=0;
  int*nuevoarr=(int*)malloc(size*sizeof(int));
  for(int i=0;i<size;i++){
    if (arr[i]%2==0){
      nuevoarr[j]=arr[i];
      j++;
    }
  }
  *newSize=j;
  return nuevoarr; 
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,int result[]) {int i=0;
  int j=0;
  int k=0;
  while (i<size1 && j<size2){
    if(arr1[i]<arr2[j]){
      result[k++]=arr1[i++];
    }
    else{
      result[k++]=arr2[j++];
    }
  }
  while (i<size1){
    result[k++]=arr1[i++];
  }
  while(j<size2){
    result[k++]=arr2[j++];
  }
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,n
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) {
  int ascending = 1;  
  int descending = 1; 
  
  for (int i = 1; i < size; i++) {
    if (arr[i] < arr[i - 1]) {
      ascending = 0; 
    }
    if (arr[i] > arr[i - 1]) {
      descending = 0; 
    }
  }
  
  if (ascending && descending) {
    return -1; 
  } else if (ascending) {
    return 1; 
  } else if (descending) {
    return -1; 
  } else {
    return 0; 
  }
}


/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor, int anioNacimiento, int anioPublicacion) {
  strcpy(libro->titulo,titulo);
  strcpy(libro->autor.nombre,nombreAutor);
  libro->anioPublicacion=anioPublicacion;
  libro->autor.anioNacimiento=anioNacimiento;
  
  
  }

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) {
  Nodo *primero=NULL;
  Nodo *ultimo=NULL;
  for (int i=0 ;i<size;i++){
    Nodo*newnode=(Nodo*)malloc(sizeof(Nodo));
    newnode->numero=arr[i];
    newnode->siguiente=NULL;

    if (primero==NULL){
      primero=newnode;
      ultimo = newnode;
    }
    else{
      ultimo->siguiente= newnode;
      ultimo= newnode;
    }
    
  }
  return primero;
}
