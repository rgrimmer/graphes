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

    
    //insertionSommet(&g,1);
    insertionSommet(&g,2);
    insertionSommet(&g,3);
    insertionSommet(&g,4);
    insertionSommet(&g,5);

    insertionArete(&g,1,2,5,0);
    insertionArete(&g,1,3,2,1);
    insertionArete(&g,9,1,2,0);
    insertionArete(&g,1,0,9,0);
    insertionSommet(&g,8);
    //insertionArete(&g,5,3,2,0);
    

   
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

