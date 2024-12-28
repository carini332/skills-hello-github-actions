#include <stdio.h>   // Para printf, scanf
#include <string.h>  // Para strcpy, strchr
#include <ctype.h>   // Para toupper
#include <stddef.h>
#include "database.h"
#include "acces.h"

// Funciones de acciones
void p_new(struct Reader *tab_r, int *n_r) {
  char nombre[50];
  printf("New\n");
  take_string("Name",nombre);
  
   if (*n_r > 0) {
        tab_r[*n_r].code = tab_r[*n_r - 1].code + 1;
    } else {
        tab_r[*n_r].code = 1; // Si es el primer lector, asignar código 1
    }

   strcpy(tab_r[*n_r].name, nombre);
 
  printf("Reader %s;%d",tab_r[*n_r].name, tab_r[*n_r].code);
  (*n_r)++;
  
}

void p_add() {
    printf("Add\n");
}

void p_vote() {
    printf("Vote\n");
    printf("%d",take_int("Book",20));
}

void p_clean() {
    printf("Clean\n");
}

int p_show (struct Reader *tab_r, int n_r, struct Book *tab_b, int n_b) {
  printf("Show\n\n\nReaders:\n");
  int i, d;
  for(i=0; i < n_r; i++){
    printf("%s;%d",(tab_r + i)->name,(tab_r + i)->code);
    printf("\n");
  }
  for(d=0; d < n_b; d++){
    printf("%d;%s;%s;%d;%d",(tab_b + d)->signature, (tab_b + d)->author, (tab_b + d)->title, (tab_b + d)->votes, (tab_b + d)->points);
      printf("\n");
      }
  return 0;
}

//def función de p_init
int p_init (struct Reader *tab_r, int *n_r, struct Book *tab_b, int *n_b) {
  
  char cadena[256];
    //Abrimos los ficheros
    FILE *lectores, *libros;
    lectores = fopen("readers.txt", "r");
    libros = fopen("books.txt", "r");

    *n_r = 0;
    *n_b = 0;
    //Caso de que no existan o esten vacíos los docs
    if (lectores == NULL) {
      *n_r = 0;
      return 0;
    }
    if (libros == NULL) {
      *n_b = 0;
	return 0;
    }
    
    //lectura de los docs
    while (fgets(cadena,256,lectores)) {
      sscanf(cadena,"%s %d",tab_r[*n_r].name, &tab_r[*n_r].code);
      (*n_r)++; 
    }
    while (fgets(cadena,256,lectores)) {
      sscanf(cadena,"%d %s %s %d %d", &tab_b[*n_b].signature, tab_b[*n_b].author, tab_b[*n_b].title, &tab_b[*n_b].votes, &tab_b[*n_b].points);
      (*n_b)++;
    }

    fclose(lectores);
    fclose(libros);
      
    return 0; 
}
void p_fin(struct Reader *tab_r, int *n_r, struct Book *tab_b,  int *n_b) {

  //Abrimos los ficheros
  FILE *lectores, *libros;
  lectores = fopen("readers.txt", "w");
  libros = fopen("books.txt", "w");

  int cp_l, cp_b;

  //copiamos los lectores en readers.txt
  for(cp_l = 0; cp_l < *n_r; cp_l++) 
    fprintf(lectores,"%s %d\n",tab_r[cp_l].name, tab_r[cp_l].code);
  
  //copiamos los libros en books.txt
  for(cp_b = 0; cp_b < *n_b; cp_b++)
    fprintf(libros,"%d %s %s %d %d", tab_b[*n_b].signature, tab_b[*n_b].author, tab_b[*n_b].title, tab_b[*n_b].votes, tab_b[*n_b].points);

  fclose(lectores);
  fclose(libros);
}
