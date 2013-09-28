/*
 * File:   main.c
 * Author: Hadryx
 *
 * Created on 26 septembre 2013, 13:34
 */
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

    /*l = AjouterElement2(l,1,2);
    l = AjouterElement2(l,2,3);
    l = AjouterElement2(l,3,4);*/
    
    AjouterElement(&l,1,2);
    AjouterElement(&l,2,3);
    AjouterElement(&l,3,4);
    AfficherListe(l);
    //SupprimerElement(&l,3);
    AfficherListe(l);
    
    while (quitter != 1) {
        if (codeRetour) {
            printf("La fonction %s est invalide !\n", commande);
        }
        printf("\n");
        afficherMenu(stdout);
        scanf("%s", commande);
        codeRetour = choixMenu(commande, &quitter);
    }
    return (EXIT_SUCCESS);
}

