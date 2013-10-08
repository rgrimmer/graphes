#include <stdlib.h>
#include <stdio.h>

#include "list.h"

void afficherListe(TypVoisin * l){  
    TypVoisin * copie = l;
    
    while(copie != NULL){
        printf("(%d,%d) ", copie->voisin, copie->poidsVoisin);
        copie = copie->voisinSuivant;
    }
    
    printf("\n");
}

void ajouterElement(TypVoisin ** l, int poids, int voisin){

    TypVoisin * element = malloc(sizeof(TypVoisin));
    
    if(!element){
        fprintf(stderr, "erreur d'allocation\n");
        exit(EXIT_FAILURE);
    }
    
    element->poidsVoisin = poids;
    element->voisin = voisin;
    element->voisinSuivant = NULL;

    
    if(NULL == *l){
        *l = element;
    }
    else{
        TypVoisin * copie = *l;
        
        while(NULL != copie->voisinSuivant){
            copie = copie->voisinSuivant;
        }
        
        copie->voisinSuivant = element;
    }
}

void supprimerElement(TypVoisin **l, int q) {
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
