#include <stdio.h>   // Para printf, scanf
#include <string.h>  // Para strcpy, strchr
#include <ctype.h>   // Para toupper
#include <stddef.h>
#include "database.h"
#include "acces.h"

// Funciones de acciones
void p_new() {
  char nombre[50];
  printf("New\n");
  take_string("Name",nombre);
  printf("Reader: %s\n",nombre);
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

int p_show (struct Reader *tab_r, int numero) {
  printf("Show\nReaders:\n");
  int i;
  for(i=0; i < numero; i++){
    printf("%s;%d",(tab_r + i)->name,(tab_r + i)->code);
    printf("\n");
  }
  return 0;
}

//def función de p_init
int p_init (struct Reader *tab_r, int *numero) { 
    int code; 
 
    *numero = 0; 
    code = take_int ("Code", 200);   
    while (code > 0) { 
        tab_r[*numero].code = code; 
        take_string ("Name", tab_r[*numero].name); 
        (*numero)++ ; 
        code = take_int ("Code", 200);   
    } 
    return 0; 
}
