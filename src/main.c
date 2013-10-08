#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "list.h"
#include "menu.h"

int main() {
    printf("Bienvenue \n");
    char commande[64];
    int quitter = 0;
    int codeRetour = 0;
    
    TypVoisin * l = NULL;

    ajouterElement(&l,2,6);
    ajouterElement(&l,6,2);
    ajouterElement(&l,9,9);
    ajouterElement(&l,3,2);

    afficherListe(l);
    /*SupprimerElement(&l,3);
    AfficherListe(l);*/
   
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

