#include <stdio.h>   // Para printf, scanf
#include <string.h>  // Para strcpy, strchr
#include <ctype.h>   // Para toupper
#include <stddef.h>

void boundary(char c, int nCaracteres);
void mark(const char *message);
int validate(const char *prompt);
void take_string (const char *mensaje, char *palabra); 
int take_int (const char *mensaje, int maximo);
char take_char (const char *mensaje, const char *pattern);
