#ifndef GRAPHE_H
#define	GRAPHE_H

#include "list.h"

typedef struct{
	int nbMaxSommets;
        TypVoisin ** listesAdjacences;
}TypGraphe;

void initGraph(TypGraphe* g, int nbSommets);
int insertionSommet(TypGraphe* g, int numeroSommet); 
int insertionArete(TypGraphe* g,int numeroSommetSource, int numeroSommetCible, int poidsSommet, int oriente); 

#endif	/* GRAPHE_H */

