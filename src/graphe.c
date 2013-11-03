/*
 **********************************************************
 *
 * Programme :  graphe.c
 *
 * ecrit par :  GRIMMER Rémy et BELKEBIR Hadrien
 *
 * resume :     fichier de manipulation des graphes
 *              
 * date :       //TODO
 *
 ***********************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include "liste.h"

/*
 * Fonction :    initGraphe
 *
 * Parametres :  int nbMaxSommets, nombre de sommets du graphe
 *
 * Retour :      TypGraphe, le graphe créé
 *
 * Description : Créér un graphe de taille nbMaxSommets (passé en paramêtre)
 *
 */
TypGraphe initGraphe(int nbMaxSommets){
    TypGraphe g;
    g.nbMaxSommets = nbMaxSommets;
    g.listesAdjacences = malloc(sizeof(TypVoisin) * nbMaxSommets + 1);
    int i;

    for (i = 0; i <= nbMaxSommets; i++) {        
        g.listesAdjacences[i] = NULL;
    }
	
	printf("graphe de taille %d créé\n", nbMaxSommets);

    return g;	
}

/*
 * Fonction :    afficherGraphe
 *
 * Parametres :  TypGraphe g, le graphe à afficher.
 *
 * Retour :      rien
 *
 * Description : affiche le graphe passé en paramêtre.
 *
 */
void afficherGraphe(TypGraphe g){
	int i;

	for(i = 1; i <= g.nbMaxSommets; ++i){
		if(g.listesAdjacences[i] != NULL){
			printf ("%d : ", i);
			afficherListe(g.listesAdjacences[i]);
		}
	}
}

/*
 * Fonction :    insertionSommet
 *
 * Parametres :  TypGraphe *g, le graphe à manipuler(pointeur).
 *
 * Retour :      int, renvoi 0 si l'insertion a réussi, -1 sinon
 *
 * Description : insert un sommet au graphe passé en paramêtre (équivaut à ajouté un élément -1 au sommet).
 *
 */
int insertionSommet(TypGraphe *g, int numeroSommet){

	if (!estSommetValide(*g, numeroSommet)) {
		fprintf(stderr, "insertion echouée : le sommet %d n'est pas un sommet valide \n", numeroSommet);
		return -1;
	}

	if (g->listesAdjacences[numeroSommet] != NULL) {
		fprintf(stderr, "Le sommet existe déjà !\n");
		return -1;
	}

	if (ajouterElement(&g->listesAdjacences[numeroSommet],-1,0) != 0) {
		return -1;
	}

	return 0;
}

/*
 * Fonction :    suppressionSommet
 *
 * Parametres :  TypGraphe *g, le graphe à manipuler (pointeur).
 *
 * Retour :      int, renvoi 0 si la suppression a réussi, -1 sinon
 *
 * Description : supprime un sommet au graphe passé en paramêtre
 *				 (équivaut à supprimer la liste attaché à ce sommet
 *				 et à supprimer toutes les dépendances à ce sommet)
 *
 */
int suppressionSommet(TypGraphe *g, int numeroSommet){

	int i, trouve;

	if (!estSommetValide(*g, numeroSommet)) {
		fprintf(stderr, "suppression impossible : sommet invalide. \n");
		return -1;
	}

	if (!estInitialiseSommet(*g, numeroSommet)) {
		fprintf(stderr, "Impossible de supprimer une arète sur un sommet non initialisé !\n");
		return -1;
	}

	for (i = 1; i < g->nbMaxSommets; ++i) {
		if (i == numeroSommet) {
			detruireListe(&g->listesAdjacences[i]);
			g->listesAdjacences[i] = NULL;
		}
		else {
			do{
				trouve = rechercherElement(&g->listesAdjacences[i], numeroSommet);
				if (trouve == 0) {
					if (supprimerElement(&g->listesAdjacences[i], numeroSommet) != 0) {
						return -1;
					}			
				}
			} while(trouve == 0);
		}
	}

	return 0;
}

/*
 * Fonction :    insertionArete
 *
 * Parametres :  TypGraphe *g, le graphe à manipuler (pointeur).
 * 				 int numeroSommetSource, numéro du sommet source (auquel on ajoute un sommet)
 *				 int numeroSommetCible, numéro du sommet cible (le sommet ajouté)
 *				 int poidsSommet, le poids du sommet
 *				 int orienté, 0 si l'arete est oriénté, une autre valeur sinon
 *
 * Retour :      int, renvoi 0 si l'insertion à réussi, -1 sinon
 *
 * Description : insert une arête
 *
 */
//TODO sommetSource = sommetCible => ?
int insertionArete(TypGraphe *g, int numeroSommetSource, int numeroSommetCible, int poidsSommet, int oriente){

	if (!estSommetValide(*g, numeroSommetSource) || !estSommetValide(*g, numeroSommetCible)) {
		fprintf(stderr, "insertion impossible : sommet(s) invalide(s). \n");
		return -1;
	}

	if (!estInitialiseSommet(*g, numeroSommetSource) || !estInitialiseSommet(*g, numeroSommetCible)) {
		fprintf(stderr, "Impossible d'ajouter une arête sur un sommet non initialisé !\n");
		return -1;
	}

	supprimerElement(&g->listesAdjacences[numeroSommetSource], -1);
	ajouterElement(&g->listesAdjacences[numeroSommetSource], numeroSommetCible, poidsSommet);
	ajouterElement(&g->listesAdjacences[numeroSommetSource], -1, 0);

	if (oriente == 0) {
		supprimerElement(&g->listesAdjacences[numeroSommetCible], -1);
		ajouterElement(&g->listesAdjacences[numeroSommetCible], numeroSommetSource, poidsSommet);
		ajouterElement(&g->listesAdjacences[numeroSommetCible], -1, 0);
	}

	return 0;
}

/*
 * Fonction :    suppresionArete
 *
 * Parametres :  TypGraphe *g, le graphe à manipuler (pointeur).
 * 				 int numeroSommetSource, numéro du sommet source (auquel on supprime un sommet)
 *				 int numeroSommetCible, numéro du sommet cible (le sommet à supprimé)
 *
 * Retour :      int, renvoi 0 si l'insertion à réussi, -1 sinon
 *
 * Description : supprime une arête
 *
 */
int suppresionArete(TypGraphe* g, int numeroSommetSource, int numeroSommetCible){

	if (!estSommetValide(*g, numeroSommetSource) || !estSommetValide(*g, numeroSommetCible)) {
		fprintf(stderr, "supression impossible : sommet(s) invalide(s). \n");
		return -1;
	}

	if (!estInitialiseSommet(*g, numeroSommetSource) || !estInitialiseSommet(*g, numeroSommetCible)) {
		fprintf(stderr, "Impossible de supprimer une arête sur un sommet non initialisé !\n");
		return -1;
	}

	supprimerElement(&g->listesAdjacences[numeroSommetSource], numeroSommetCible);

	return 0;
}

/*
 * Fonction :    estInitialiseSommet
 *
 * Parametres :  TypGraphe g, le graphe à tester.
 *
 * Retour :      int, renvoi 0 si le sommet est initialisé, une autre valeur sinon
 *
 * Description : test si un sommet est initialisé
 *
 */
int estInitialiseSommet(TypGraphe g, int numeroSommet){
	return(NULL != g.listesAdjacences[numeroSommet]);
}

/*
 * Fonction :    estSommetValide
 *
 * Parametres :  TypGraphe g, le graphe à tester.
 *				 int numeroSommet, le sommet à tester
 *
 * Retour :      int, renvoi 0 si le sommet est valide, une autre valeur sinon
 *
 * Description : test si un sommet est valide 
 *				 (sommet compris entre 1 et le nombre max de sommets du graphe.
 *
 */
int estSommetValide(TypGraphe g, int numeroSommet){
	return(numeroSommet > 0 && numeroSommet <= g.nbMaxSommets);
}

/*
 * Fonction :    detruireGraphe
 *
 * Parametres :  TypGraphe *g, le graphe à détruire (pointeur).
 *
 * Retour :      rien
 *
 * Description : détruit le graphe passé en paramêtre (vide la mémoire)
 *
 */
void detruireGraphe(TypGraphe *g){
	int i;

	for (i = 0; i <= g->nbMaxSommets; ++i) {
		if (NULL != g->listesAdjacences[i]) {
			detruireListe(&g->listesAdjacences[i]);
		}
	}

	free(g->listesAdjacences);
}


