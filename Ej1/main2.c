/* Materia: Algoritmos y Estructura de Datos II - 2020 FAMAF
    <<<<< EJERCICIO ENTREGABLE 1 >>>>>

Alumna:  
    - Vispo, Valentina Solange

Link de descarga: https://wiki.cs.famaf.unc.edu.ar/lib/exe/fetch.php?media=algo2:main:ejercicio_entregable_1.zip

Teórico:
https://wiki.cs.famaf.unc.edu.ar/lib/exe/fetch.php?media=algo2:main:2020.03.recurrenciasdyv.y.jerarquia.pdf
https://www.youtube.com/watch?v=rQxUUjNBhd8
https://youtu.be/n5D1KExw30Y

Videos explicativos:
<Búsqueda binaria>
https://youtu.be/HyZVdkkCf2Q
*/

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Se pide la implementación de 2 funciones cuyo esqueleto se encuentra en el archivo main.c
1) Escribe un algoritmo que encuentre la cima de un arreglo dado (asumiendo que
efectivamente tiene una cima) utilizando una búsqueda secuencial, desde el comienzo
del arreglo hacia el final.
2) Escribe un algoritmo que resuelva el mismo problema del inciso anterior utilizando la
idea de búsqueda binaria.

Vídeos profe: https://drive.google.com/file/d/1-E08AEbmw6gPAno2jN1w9J2ndIJvLQi2/view
*/

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100000u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Save an array given in a file in disk.\n"
           "\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

  // Funcion agregada por mi, comprueba si la matriz tiene cima 
bool esCima (int a[], int length){ // Inicio funcion esCima
  int i,n;
  n=(length-1);
  i=0;
  while (i<n && a[i]<a[i+1]){
    i++;
  }
  while(i<n && a[i]>a[i+1]){
    i++;
  }
  if (i==n){
    printf("\n\n >>> Tiene cima <<<\n");
    return true;
  }
  else{
    printf("\n\n >>> No tiene cima <<<\n");
    return false;
  }
} // Fin funcion esCima

// Ej 1: Funtion that finds the peak on the array, if it does not exist, return -1
int array_peak_sequential(int a[], unsigned int length) { // Inicio funcion array_peak_sequential
  unsigned int i = 0;
  if(esCima(a, length) && length>0){
    while(i<length && a[i]<a[i+1]){
      ++i;
    }
  }
  else{
    return -1;
  }
  return i;
  //please change whatever you need here to make it work.
  //return 0;
} // Fin funcion array_peak_sequential

// Ej 2: Funtion that finds the peak on the array, if it does not exist, return -1
/*int array_peak_binary(int a[], unsigned int length) {
  //please change whatever you need here to make it work.
  return 0;
}*/

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }
    result = argv[1];
    return (result);
}

int main(int argc, char *argv[]) {
  /* Arreglo con cima: [1] [2] n=1
  [1 2 3] [3 2 1] n=3
  [5 4 3 2 1], [1 2 3 4 5], [1 2 5 2 1] n=5
  [1 2 3 4 3 2 1] n=7 */
  // Asumo que existe cima directamente
  printf(" ********* Inicio programa *********\n");
  char *filepath = NULL;

  /* parse the filepath given in command line arguments */
  filepath = parse_filepath(argc, argv);

  /* create an array of MAX_SIZE elements */
  int array[MAX_SIZE];

  /* parse the file to fill the array and obtain the actual length */
  unsigned int length = array_from_file(array, MAX_SIZE, filepath);

  /* show the ordered array in the screen */
  array_dump(array, length);

  int this_is_the_peak = array_peak_sequential(array, length);
  printf("The peak is: %d", this_is_the_peak);

  //TODO: Uncomment this to do part b
  //array_peak_binary(array, length);

  printf("\n\n ********* Fin programa *********\n");
  return (1);
}
/*
 Para correrlo al programa
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -o lab_extra *.o main.c

Para ejecutarlo
./lab_extra ../input/example-unsorted.in

//////////////////

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c ./input/unsorted-100.in *.o main.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -c ./lab_extra ./input/archivo.in *.o main.c
*/

/*
Chicos por si le sirve a alguien entendi los errores al compilar el trabajo que tenemos que entregar:
Primero los dos codigos para compilar escribanlo ustedes, no lo copien estan mal copiados, debe haber un espacio de mas o lago asi
Despues para ejecutar el programa no tienen que usar "./lab_extra ../input/unsorted-100.in" porque esta pidiendo que vuela 
atras y busque la carpeta input pero la carpeta input esta en el mismo lugar donde estan trabajando entonces 
tienen que usar: "./lab_extra input/unsorted-100.in" y va a compilar perfecto
*/

/*
if(a[i] > cima){
    cima = a[i];
}
else{
    return -1;
}
*/
/*
unsigned int array_peak_sequential(int a[], unsigned int length){
    if(has_cima(a, length) && length > 0){
      unsigned int i = 0;
      while(i < length && a[i] < a[i+1]){
        ++i;
      }
    }
    else{
      return -1;
    }
    return i;
}
*/
/*
Los siguientes arreglos tienen cima?

 

    1)   [1] 

 
Sí, en la primera posición: todos los elementos anteriores (0 elementos) están en orden creciente, 
y todos los siguientes (0 elementos) en orden decreciente.

    2)   [1,1,2,3,2,1] o con cualquier numero repetido que no sea la " cima"(en este caso 3)


No, porque los elementos del principio no están en orden creciente estricto (estricto significa 
que no hay repetidos).
 

    3)   [1,2,3,4,5] (o en orden descendente)


Sí
*/
/*
Aclaro, cuando digo "usar búsqueda binaria" quiero decir usar la idea de la búsqueda binaria. 
No hay que usar las funciones binary_search y binary_search_rec tal cual están, si no que hay 
que definir funciones cima y cima_rec usando las mismas ideas que esas funciones.
*/
/*
Hola, mirando el enunciado nos dice:

"cima de a es un valor k en el intervalo 1, . . . , n tal que a[1..k] está ordenado 
crecientemente y a[k..n] está ordenado decrecientemente"

Veamos entonces que si ese valor k es 1, la cima está en el primer elemento, y si k es n, 
está en el último.
*/