#include <stdio.h>   // Para printf, scanf
#include <string.h>  // Para strcpy, strchr
#include <ctype.h>   // Para toupper
#include <stddef.h> 
#include "acces.h"
#include "database.h"

int main() {
    //Semaforo de salida
    int exit;
    int n_signos = 50;

    //Declaración de struct
    struct Reader readers[100];
    struct Book books[100];
    int numReaders, numBooks;

    // Carátula inicial
    boundary('-', n_signos);
    mark("LIBRARY");
    boundary('-', n_signos);

    p_init(readers, &numReaders, books, &numBooks);

    do {
        // Menú de opciones
        printf("\nN) New reader\n");
        printf("A) Add book\n");
        printf("V) Submit vote\n");
        printf("C) Clean reader\n");
	printf("S) Show\n");
        printf("X) Exit\n\n");

	char mensajePrincipal[] = "Enter option";
	char patronPrincp[] = "NAVCSX";
	
        // Manejo de opciones
        switch (take_char(mensajePrincipal,patronPrincp)) {
        case 'N':
	  p_new(readers, numReaders);
            break;
        case 'A':
            p_add();
            break;
        case 'V':
            p_vote();
            break;
        case 'C':
            p_clean();
            break;
	case 'S':
	  p_show(readers, numReaders, books, numBooks);
	  break;
        case 'X':
            exit = validate("Estas seguro?");
            break;
        default:
            printf("Invalid option\n");
        }
    } while (exit != 1);

    p_fin(readers, &numReaders, books, &numBooks);

    return 0;
}
