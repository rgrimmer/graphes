#include<stdio.h>
#include<stdlib.h>

#include "graphe.h"
#include "list.h"

TypGraphe initGraph(int nbMaxSommets){
    TypGraphe g;
    g.nbMaxSommets = nbMaxSommets;
    g.listesAdjacences = malloc(sizeof(TypVoisin**) * nbMaxSommets);
    int i;

    for (i=0; i<nbMaxSommets; i++){        
        g.listesAdjacences[i] = NULL;
    }

    return g;	
}

void afficherGraphe(TypGraphe *g){
	int i;
	for(i = 0; i < g->nbMaxSommets; ++i){
		if(g->listesAdjacences[i] != NULL){
			printf ("%d : ", i);
			afficherListe(g->listesAdjacences[i]);
		}
	}
}

int insertionSommet(TypGraphe *g, int numeroSommet){    
    return insertionArete(g,numeroSommet,-1,0,1);
}

int insertionArete(TypGraphe *g, int numeroSommetSource, int numeroSommetCible, int poidsSommet, int oriente){

    if (g->listesAdjacences[numeroSommetSource] != NULL){
        ajouterElement(&g->listesAdjacences[numeroSommetSource],numeroSommetCible,poidsSommet);
    }else{
        TypVoisin *arete = NULL;
        ajouterElement(&arete,numeroSommetCible,poidsSommet);
        g->listesAdjacences[numeroSommetSource] = arete;
    }

    if(oriente == 0){
        if (g->listesAdjacences[numeroSommetCible] != NULL){
            ajouterElement(&g->listesAdjacences[numeroSommetCible],numeroSommetSource,poidsSommet);
        }else{
            TypVoisin *arete = NULL;
            ajouterElement(&arete,numeroSommetSource,poidsSommet);
            g->listesAdjacences[numeroSommetCible] = arete;
        }
    }
    

    return 0;
}


