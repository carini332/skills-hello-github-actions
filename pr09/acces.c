#include <stdio.h>   // Para printf, scanf
#include <string.h>  // Para strcpy, strchr
#include <ctype.h>   // Para toupper
#include <stddef.h>
#include "acces.h"


// Función boundary()
void boundary(char c, int nCaracteres) {
    for (int i = 0; i < nCaracteres; i++) {
        printf("%c", c);
    }
    printf("\n");
}

// Función mark()
void mark(const char *message) {
    printf("%s\n", message);
}

// Función validate()
int validate(const char *prompt) {

  if (take_char(prompt,"YN") == 'N')
    return 0;
  else
    return 1;
    
}

void take_string (const char *mensaje, char *palabra) {
  char cadena [50];
  printf ("%s (1-25 char): ",mensaje);
  scanf (" %s",cadena);
  //strcpy (destino,origen)
  strcpy (palabra,cadena);
  return;
}

int take_int (const char *mensaje, int maximo)
{
  int entero;
  do {
  printf("%s ", mensaje);
  scanf("%d",&entero);
    } while(entero < 0 || entero > maximo);
  return entero;
}

char take_char (const char *mensaje, const char *pattern)
{
  char mayuscula, caracter, cadena[256], extra[256], semaforo;
  do {
    printf("%s (%s): ",mensaje,pattern);
    fgets(cadena,256,stdin);
    semaforo = sscanf(cadena," %c%255s", &caracter, extra);
    mayuscula = toupper(caracter);
    
  } while(strchr(pattern,mayuscula) == NULL || semaforo != 1);
  return mayuscula;
}
