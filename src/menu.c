/*
 * File:   menu.c
 * Author: Hadryx
 *
 * Created on 26 septembre 2013, 13:34
 */
#include<string.h>
#include<stdio.h>

/*
 * Fonction : choixMenu
 *
 * Parametres :  char *cmd : ligne de commande entré par l'utilisateur
 *               int *quitter : pointeur sur un entier pour indiquer la poursuite
 *                             ou non du programme
 *
 * Retour : int, valeur de vérification pour assurer qu'un paramètre valide à été
 *              saisi
 *
 * Description : Permet d'appeler les fonctions demander par l'utilisateur
 *
 */
int choixMenu(char *cmd, int *quitter) {
    // TODO à voir pour ajouter une vérification de la casse de cmd
    if (strcmp(cmd, "creation") == 0 || strcmp(cmd,"1") == 0) {
        fprintf(stderr, "Fonction création non implémentée\n");
        return 0;
    }
    if (strcmp(cmd, "lecture") == 0 || strcmp(cmd,"2") == 0) {
        fprintf(stderr, "Fonction lecture non implémentée\n");
        return 0;
    }
    if (strcmp(cmd, "insertionSommet") == 0 || strcmp(cmd,"3") == 0) {
        fprintf(stderr, "Fonction insertion sommet non implémentée\n");
        return 0;
    }
    if (strcmp(cmd, "insertionArete") == 0 || strcmp(cmd,"4") == 0) {
        fprintf(stderr, "Fonction insertion arete non implémentée\n");
        return 0;
    }
    if (strcmp(cmd, "suppressionSommet") == 0 || strcmp(cmd,"5") == 0) {
        fprintf(stderr, "Fonction suppression sommet non implémentée\n");
        return 0;
    }
    if (strcmp(cmd, "suppressionArete") == 0 || strcmp(cmd,"6") == 0) {
        fprintf(stderr, "Fonction suppression arete non implémentée\n");
        return 0;
    }
    if (strcmp(cmd, "affichage") == 0 || strcmp(cmd,"7") == 0) {
        fprintf(stderr, "Fonction affichage non implémentée\n");
        return 0;
    }
    if (strcmp(cmd, "sauvegarde") == 0 || strcmp(cmd,"8") == 0) {
        fprintf(stderr, "Fonction sauvegarde non implémentée\n");
        return 0;
    }
    if (strcmp(cmd, "quitter") == 0 || strcmp(cmd,"0") == 0) {
        *quitter = 1;
        return 0;
    }
    return 1;

}

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
void afficherMenu(FILE *stream) {
    fprintf(stream, "Menu de séléction :\n"
            "1 - creation\n"
            "2 - lecture\n"
            "3 - insertionSommet\n"
            "4 - insertionArete\n"
            "5 - suppressionSommet\n"
	    "6 - suppressionArete\n"	
            "7 - affichage\n"
            "8 - sauvegarde\n"
            "0 - quitter \n");
}
