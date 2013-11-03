#ifndef LIST_H
#define LIST_H

typedef struct TypVoisin{
	int voisin;
        int poidsVoisin;
	struct TypVoisin* voisinSuivant;
}TypVoisin;

int  ajouterElement(TypVoisin** l, int voisin, int poids);
int  rechercherElement(TypVoisin **l, int q);
int  supprimerElement(TypVoisin** l, int voisin);
void afficherListe(TypVoisin* l);
void detruireListe(TypVoisin **l);

#endif
