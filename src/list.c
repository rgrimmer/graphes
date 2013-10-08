#include <stdlib.h>
#include <stdio.h>

#include "list.h"

void AfficherListe(TypVoisin * l){  
    TypVoisin * copie = l;
    
    while(copie != NULL){
        printf("(%d,%d) ", copie->voisin, copie->poidsVoisin);
        copie = copie->voisinSuivant;
    }

    printf("\n");
}

void AjouterElement(TypVoisin ** l, int voisin, int poids){

	TypVoisin *ptl = *l;
	TypVoisin *tmp;

	if(!ptl){
		ptl = (TypVoisin*) malloc(sizeof(TypVoisin));
		ptl->poidsVoisin = poids;
		ptl->voisin = voisin;
		ptl->voisinSuivant = NULL;
		*l = ptl;
		return;
	}

	if( ptl->voisin == voisin ) {
		return;
	}

	if( voisin < ptl->voisin ) {
		tmp = *l;
		*l = (TypVoisin*) malloc(sizeof(TypVoisin));
		(*l)->voisin = voisin;
		(*l)->poidsVoisin = poids;
		(*l)->voisinSuivant = tmp;
		return;
	}

	while(ptl->voisinSuivant && ptl->voisinSuivant->voisin < voisin) {
		ptl = ptl->voisinSuivant;
	}

	if(!ptl->voisinSuivant) {
		ptl->voisinSuivant = (TypVoisin*) malloc(sizeof(TypVoisin));
		ptl = ptl->voisinSuivant;
		ptl->voisin = voisin;
		ptl->poidsVoisin = poids;
		ptl->voisinSuivant = NULL;
		return;
	}

	if( ptl->voisinSuivant->voisin == voisin ) {
		return;
	}

	tmp = ptl->voisinSuivant;
	ptl->voisinSuivant = (TypVoisin*) malloc(sizeof(TypVoisin));
	ptl = ptl->voisinSuivant;
	ptl->voisin = voisin;
	ptl->poidsVoisin = poids;
	ptl->voisinSuivant = tmp;
}

void SupprimerElement(TypVoisin **l, int q) {
	TypVoisin *ptl;
	TypVoisin *tmp;
	ptl = *l;

	if(!ptl){
		return;
	}

	if( ptl->voisin == q ) {
		*l = ptl->voisinSuivant;
		free(ptl);
		return;
	}
        
        while(ptl->voisinSuivant) {
		if( ptl->voisinSuivant->voisin == q ) {
			tmp = ptl->voisinSuivant;
			ptl->voisinSuivant = ptl->voisinSuivant->voisinSuivant;
			free(tmp);
			return;
		}

		ptl = ptl->voisinSuivant;
	}
}
