#ifndef GRAPHE_H
#define	GRAPHE_H

#include "liste.h"

typedef struct{
	int nbMaxSommets;
    TypVoisin ** listesAdjacences;
}TypGraphe;

TypGraphe initGraphe(int nbMaxSommets);
int insertionSommet(TypGraphe* g, int numeroSommet); 
int suppressionSommet(TypGraphe* g, int numeroSommet); 
int insertionArete(TypGraphe* g, int numeroSommetSource, int numeroSommetCible, int poidsSommet, int oriente);
int suppresionArete(TypGraphe* g, int numeroSommetSource, int numeroSommetCible); 
void afficherGraphe(TypGraphe g);
int estSommetValide(TypGraphe g, int numeroSommet);
int estInitialiseSommet(TypGraphe g, int numeroSommet);
void detruireGraphe(TypGraphe *g);

#endif	/* GRAPHE_H */

