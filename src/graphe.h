#ifndef GRAPHE_H
#define	GRAPHE_H

#include "list.h"

typedef struct{
	int nbMaxSommets;
        TypVoisin ** listesAdjacences;
}TypGraphe;

TypGraphe initGraph(int nbMaxSommets);
int insertionSommet(TypGraphe* g, int numeroSommet); 
int insertionArete(TypGraphe* g,int numeroSommetSource, int numeroSommetCible, int poidsSommet, int oriente); 
void afficherGraphe(TypGraphe *g);
int checkTailleGraphe(TypGraphe *g, int numeroSommet);

#endif	/* GRAPHE_H */

