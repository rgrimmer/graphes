#ifndef LIST_H
#define LIST_H

typedef struct TypVoisin{
	int voisin;
        int poidsVoisin;
	struct TypVoisin* voisinSuivant;
}TypVoisin;

void ajouterElement(TypVoisin** l, int voisin, int poids);
void supprimerElement(TypVoisin** l, int voisin);
void afficherListe(TypVoisin* l);

#endif
