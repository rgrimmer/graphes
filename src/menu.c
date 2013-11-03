/*
 **********************************************************
 *
 * Programme :  menu.c
 *
 * ecrit par :  GRIMMER Rémy et BELKEBIR Hadrien
 *
 * resume :     Affichage d'un menu de manipulation des graphes
 *              
 * date :       //TODO
 *
 ***********************************************************
 */
#include <string.h>
#include <stdio.h>
#include "menu.h"
#include "graphe.h"

/*
 * Fonction : afficherMenu
 *
 * Parametres :  FILE *stream : flux de donnée vers lequel afficher le menu
 *
 * Retour :  void
 *
 * Description : Permet l'affichage du menu principal de navigation de
 * l'application.
 *
 */
void afficherMenu(int etat){

	printf("Menu de séléction : \n");

	switch (etat) {
		case E_STATE_NOUVEAU_GRAPHE :
		{
			afficherMenuNouveauGraphe();
		}
		break;

		case E_STATE_GRAPHE :
		{
			afficherMenuGraphe();
		}
		break;
	}
}

void afficherMenuNouveauGraphe(){

	printf( "1 - creation\n"
            "2 - lecture\n"
            "0 - quitter \n");
}

void afficherMenuGraphe() {

	printf( "1 - creation\n"
            "2 - lecture\n"
            "3 - insertionSommet\n"
            "4 - insertionArete\n"
            "5 - suppressionSommet\n"
	    	"6 - suppressionArete\n"	
            "7 - affichage\n"
            "8 - sauvegarde\n"
            "0 - quitter \n");
}

void choixMenu(int choix, int* etat, TypGraphe* g){
	
	if (!choixValide(choix, *etat)) {
		fprintf(stderr, "choix non valide\n");
		return;
	}
	
	switch(*etat){
		
		case E_STATE_NOUVEAU_GRAPHE :
		{
			choixMenuNouveauGraphe(choix, etat, g);
			*etat = E_STATE_GRAPHE;
			//TODO supprimer état et l'ajouter dans les autres fonctions
		}
		break;

		case E_STATE_GRAPHE :
		{
			choixMenuGraphe(choix, etat, g);
		}
		break;

	}
}

void choixMenuNouveauGraphe(int choix, int* etat, TypGraphe* g){
	switch (choix) {
		case 0 : menuQuitter(etat, g); break;
		case 1 : menuCreation(g); break;
		case 2 : menuLecture(); break;
	}
}

void choixMenuGraphe(int choix, int* etat, TypGraphe* g){
	switch (choix) {
		case 0 : menuQuitter(etat, g); break;
		case 1 : menuCreation(g); break;
		case 2 : menuLecture(); break;
		case 3 : menuInsertionSommet(g); break;
		case 4 : menuInsertionArete(g); break;
		case 5 : menuSuppressionSommet(g); break;
		case 6 : menuSuppressionArete(g); break;
		case 7 : menuAffichage(*g); break;
		case 8 : menuSauvegarde(); break;
	}
}

int choixValide(int choix, int etat){

	if (choix < 0) {
		return 0;
	}

	switch (etat) {
		case E_STATE_NOUVEAU_GRAPHE :  return(choix <= 2); 
		case E_STATE_GRAPHE : 		   return(choix <= 8);
		default : return 0;
	}
}

void menuCreation(TypGraphe* g){
	int taille;
	printf("nombre max de sommets : \n");
	scanf("%d%*[^\n]", &taille); 
	*g = initGraphe(taille);
}

void menuLecture(){ 
	printf("TODO \n");
}

void menuInsertionSommet(TypGraphe* g){
	int sommet;
	printf("numero du sommet : \n");
	scanf("%d%*[^\n]", &sommet); 
	insertionSommet(g,sommet);
}

void menuInsertionArete(TypGraphe* g){
	int sommetSource, sommetCible, poids;
	char oriente;
	printf("sommet source : \n");
	scanf("%d%*[^\n]", &sommetSource);
	printf("sommet cible : \n");
	scanf("%d%*[^\n]", &sommetCible);
	printf("poids : \n");
	scanf("%d%*[^\n]", &poids);
	printf("orienté ? (o/n) \n");
	scanf("%c%*[^\n]", &oriente);

	//TODO tester les valeurs
	//TODO oriente
	insertionArete(g,sommetSource,sommetCible,poids,0);
}

void menuSuppressionSommet(TypGraphe *g){ 
	int sommet;
	printf("sommet à supprimer : \n");
	scanf("%d%*[^\n]", &sommet);
	suppressionSommet(g, sommet);
}

void menuSuppressionArete(TypGraphe* g){ 
	int sommetSource, sommetCible;
	printf("sommet source : \n");
	scanf("%d%*[^\n]", &sommetSource);
	printf("sommet cible : \n");
	scanf("%d%*[^\n]", &sommetCible);
	suppresionArete(g, sommetSource, sommetCible);
}

void menuAffichage(TypGraphe g){
	afficherGraphe(g);
}

void menuSauvegarde(){
	printf("TODO \n");
}

void menuQuitter(int* etat, TypGraphe* g){
    printf("Au revoir. \n");

	detruireGraphe(g);

	*etat = E_STATE_QUITTER;
}


