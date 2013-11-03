/*
 **********************************************************
 *
 * Programme :  liste.c
 *
 * ecrit par :  GRIMMER Rémy et BELKEBIR Hadrien
 *
 * resume :     fichier de manipulation des listes
 *              
 * date :       //TODO
 *
 ***********************************************************
 */
#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

/*
 * Fonction :    afficherListe
 *
 * Parametres :  TypVoisin * l, liste à afficher(pointeur sur le début de la liste)
 *
 * Retour :      rien
 *
 * Description : affiche la liste passée en paramêtre.
 *
 */
void afficherListe(TypVoisin * l){  

    TypVoisin * copie = l;
    
    while (copie != NULL) {
        printf("(%d,%d)", copie->voisin, copie->poidsVoisin);

		if (copie->voisinSuivant != NULL) {
			printf(", ");
		}

        copie = copie->voisinSuivant;
    }

    printf("\n");
}

/*
 * Fonction :    ajouterElement
 *
 * Parametres :  TypVoisin ** l, liste (pointeur de pointeur sur le début de la liste)
 *				 int voisin
 *				 int poids
 *
 * Retour :      int, renvoi 0 si l'élément est ajouté, -1 sinon
 *
 * Description : ajoute un élément à la fin de la liste passée en paramêtre.
 *
 */
//TODO regarder si l'élément est deja présent + messages
int ajouterElement(TypVoisin ** l, int voisin, int poids){

	TypVoisin *ptl = *l;

	if (!ptl) {
		ptl = (TypVoisin*) malloc(sizeof(TypVoisin));

		if (!ptl) {
			fprintf(stderr, "problème d'allocation mémoire");
			return -1;		
		}
		ptl->poidsVoisin = poids;
		ptl->voisin = voisin;
		ptl->voisinSuivant = NULL;
		*l = ptl;
		return 0;
	}

	while (ptl->voisinSuivant) {
		ptl = ptl->voisinSuivant;
	}

	ptl->voisinSuivant = (TypVoisin*) malloc(sizeof(TypVoisin));

	if (!ptl->voisinSuivant) {
		fprintf(stderr, "problème d'allocation mémoire");
		return -1;
	}

	ptl = ptl->voisinSuivant;
	ptl->voisin = voisin;
	ptl->poidsVoisin = poids;
	ptl->voisinSuivant = NULL;
	return 0;
}

/*
 * Fonction :    rechercherElement
 *
 * Parametres :  TypVoisin ** l, liste (pointeur de pointeur sur le début de la liste)
 *				 int q, valeur à rechercher dans la liste
 *
 * Retour :      int, renvoi 0 si l'élément est trouvé, -1 sinon
 *
 * Description : recherche l'element passé en paramêtre dans la liste passée en paramêtre
 *
 */
int rechercherElement(TypVoisin **l, int q){
	TypVoisin *ptl = *l;

	if (!ptl) {
		return -1;
	}

	if (ptl->voisin == q) {
		return 0;
	}

	while (ptl->voisinSuivant) {
		if (ptl->voisin == q) {
			return 0;
		}
		ptl = ptl->voisinSuivant;
	}

	if (ptl->voisin == q) {
		return 0;
	}

	return -1;
}

/*
 * Fonction :    supprimerElement
 *
 * Parametres :  TypVoisin ** l, liste (pointeur de pointeur sur le début de la liste)
 *				 int q, valeur à rechercher dans la liste
 *
 * Retour :      int, renvoi 0 si l'élément est supprimé, -1 sinon
 *
 * Description : supprime l'element passé en paramêtre dans la liste passée en paramêtre
 *
 */
int supprimerElement(TypVoisin **l, int q) {

	TypVoisin *ptl;
	TypVoisin *tmp;
	ptl = *l;

	if (!ptl) {
		fprintf(stderr, "element inexistant\n ");
		return -1;
	}

	if (ptl->voisin == q) {
		*l = ptl->voisinSuivant;
		free(ptl);
		return 0;
	}
        
    while (ptl->voisinSuivant) {
		if (ptl->voisinSuivant->voisin == q) {
			tmp = ptl->voisinSuivant;
			ptl->voisinSuivant = ptl->voisinSuivant->voisinSuivant;
			free(tmp);
			return 0;
		}
		ptl = ptl->voisinSuivant;
	}

	fprintf(stderr, "element inexistant\n ");
	return -1;
}

/*
 * Fonction :    detruireListe
 *
 * Parametres :  TypVoisin ** l, liste (pointeur de pointeur sur le début de la liste)
 *
 * Retour :      rien
 *
 * Description : détruit la liste (vide la mémoire).
 *
 */
void detruireListe(TypVoisin **l){

	TypVoisin * ptl = *l;
	TypVoisin * tmp;

	if (!ptl) {
		return;
	}

	while (ptl->voisinSuivant) {
		tmp = ptl;
		ptl = ptl->voisinSuivant;
		free(tmp);
	}

	free(ptl);

}
