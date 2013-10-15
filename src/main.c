#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "list.h"
#include "graphe.h"
#include "menu.h"



int main() {
    printf("Bienvenue \n");
    char commande[64];
    int quitter = 0;
    int codeRetour = 0;
    
    TypGraphe g;
    g = initGraph(5);
    
	insertionArete(&g, 0, 3, 2, -1);
	insertionArete(&g, 0, 5, 2, -1);
	insertionArete(&g, 1, 2, 2, -1);
	insertionArete(&g, 2, 4, 2, -1);
	insertionArete(&g, 3, 4, 2, -1);

	afficherGraphe(&g);
   
    while (quitter != 1) {
        if (codeRetour) {
            printf("La fonction %s est invalide !\n", commande);
        }
        printf("\n");
        afficherMenu(stdout);
        scanf("%s", commande);
        codeRetour = choixMenu(commande, &quitter);
    }


/*
TODO : tout libérer
*/

    return (EXIT_SUCCESS);
}

