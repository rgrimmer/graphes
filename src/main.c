/*
 **********************************************************
 *
 * Programme :  main.c
 *
 * ecrit par :  GRIMMER Rémy et BELKEBIR Hadrien
 *
 * resume :     fichier principal
 *              
 * date :       //TODO
 *
 ***********************************************************
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "liste.h"
#include "graphe.h"
#include "menu.h"


int main() {

    int choix;
	int etat = E_STATE_NOUVEAU_GRAPHE;

    TypGraphe graphe;

	do {
		printf("\n\n");
		afficherMenu(etat);
		scanf("%d%*[^\n]", &choix);
		choixMenu(choix, &etat, &graphe);
	} while (etat != E_STATE_QUITTER);

    return (EXIT_SUCCESS);
}


