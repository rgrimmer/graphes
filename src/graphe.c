#include<stdio.h>
#include<stdlib.h>

#include "graphe.h"
#include "list.h"

void initGraph(TypGraphe *g, int nbSommets){
	g->nbMaxSommets = nbSommets;
    int i = 0;
    for (i = 0; i<nbSommets; i++){
        g->listesAdjacences[i] = NULL;
    }
	
}
int insertionSommet(TypGraphe *g, int numeroSommet){    
    return insertionArete(g,numeroSommet,-1,0,1);
}

int insertionArete(TypGraphe *g,int numeroSommetSource, int numeroSommetCible, int poidsSommet, int oriente){

    if (g->listesAdjacences[numeroSommetSource] != NULL){
        ajouterElement(&g->listesAdjacences[numeroSommetSource],poidsSommet,numeroSommetCible);
    }else{
        TypVoisin *arete = NULL;
        ajouterElement(&arete,poidsSommet,numeroSommetCible);
        g->listesAdjacences[numeroSommetSource] = arete;
    }

    if(oriente == 0){
        if (g->listesAdjacences[numeroSommetCible] != NULL){
            ajouterElement(&g->listesAdjacences[numeroSommetCible],poidsSommet,numeroSommetSource);
        }else{
            TypVoisin *arete = NULL;
            ajouterElement(&arete,poidsSommet,numeroSommetSource);
            g->listesAdjacences[numeroSommetCible] = arete;
        }
    }
    

    return 0;
}


