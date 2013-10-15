#include<stdio.h>
#include<stdlib.h>

#include "graphe.h"
#include "list.h"

TypGraphe initGraph(int nbMaxSommets){
    TypGraphe g;
    g.nbMaxSommets = nbMaxSommets;
    g.listesAdjacences = malloc(sizeof(TypVoisin**) * nbMaxSommets + 1);
    int i;

    for (i = 1; i <= nbMaxSommets; i++){        
        g.listesAdjacences[i] = NULL;
    }

    return g;	
}

void afficherGraphe(TypGraphe *g){
	int i;
	for(i = 1; i <= g->nbMaxSommets; ++i){
		if(g->listesAdjacences[i] != NULL){
			afficherListe(g->listesAdjacences[i]);
		}
	}
}

int insertionSommet(TypGraphe *g, int numeroSommet){    
    return insertionArete(g,numeroSommet,-1,0,1);
}

int insertionArete(TypGraphe *g, int numeroSommetSource, int numeroSommetCible, int poidsSommet, int oriente){
    // Vérifications :
    // Sommet sources compris dans l'interval 1 -> nbMaxSommets
    if (checkTailleGraphe(g,numeroSommetSource) != 0){
        fprintf(stderr,"Impossible de rajouter une arrete sur un sommet inexistant !\n");
        return 1;
    }
    // Sommet cible dans l'interval 1 -> nnMaxSommets ( et -1 pour la déclaration d'un sommet)
    if (checkTailleGraphe(g,numeroSommetCible) != 0 && numeroSommetCible != -1){
        fprintf(stderr,"Impossible de rajouter une arrete sur un sommet inexistant !\n");
        return 1;
    }
    // Sommet sources initialisé
    if (g->listesAdjacences[numeroSommetSource] == NULL && numeroSommetCible != -1){
        fprintf(stderr,"Impossible d'ajouter une arrete sur un sommet non initialise !\n");
        return 1;
    }
    // Sommet cible initialisé 
    if (g->listesAdjacences[numeroSommetCible] == NULL && numeroSommetCible != -1){
        fprintf(stderr,"Impossible d'ajouter une arrete sur un sommet non initialise !\n");
        return 1;
    }
    // Execution fonction
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

int checkTailleGraphe(TypGraphe *g, int numeroSommet){
    if (numeroSommet > g->nbMaxSommets || numeroSommet < 1){
        return 1;
    }
    return 0;
}


