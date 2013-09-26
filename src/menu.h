/*
 * File:   menu.h
 * Author: Hadryx
 *
 * Created on 26 septembre 2013, 13:32
 */

#ifndef MENU_H
#define	MENU_H

#ifdef	__cplusplus
extern "C" {
#endif

    int choixMenu(char *cmd, int *quitter);
    void afficherMenu(FILE *stream);

#ifdef	__cplusplus
}
#endif

#endif	/* MENU_H */

