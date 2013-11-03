#ifndef MENU_H
#define	MENU_H

#include "graphe.h"

	enum EState{
		E_STATE_QUITTER,
		E_STATE_NOUVEAU_GRAPHE,
		E_STATE_GRAPHE
	};

	void 	choixMenu(int choix, int* etat, TypGraphe* g);
	void 	choixMenuNouveauGraphe(int choix, int* etat, TypGraphe* g);
	void 	choixMenuGraphe(int choix, int* etat, TypGraphe* g);
	void 	afficherMenu(int etat);
	void 	afficherMenuNouveauGraphe();
	void 	afficherMenuGraphe();
	int 	choixValide(int choix, int etat);

	void	menuCreation(TypGraphe* g);
	void	menuLecture();
	void	menuInsertionSommet(TypGraphe* g);
	void 	menuInsertionArete(TypGraphe* g);
	void	menuSuppressionSommet(TypGraphe* g);
	void	menuSuppressionArete(TypGraphe* g);
	void	menuAffichage();
	void	menuSauvegarde();
	void	menuQuitter(int* etat, TypGraphe* g);

#endif	/* MENU_H */

