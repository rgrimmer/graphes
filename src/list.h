#ifndef LIST_H
#define LIST_H

typedef struct{
	int voisin;
        int poidsVoisin;
	struct TypVoisin * voisinSuivant;
}TypVoisin;

void AjouterElement(TypVoisin ** l, int poids, int voisin);
//void SupprimerElement(TypVoisin **l, int voisin);
void AfficherListe(TypVoisin * l);

#endif
