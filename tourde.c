#include "gamefun.h"

int tour_de(int nbjoueur,joueur j[]) //pour calculer c'etait le tour de qui apres qu'on est chargé une partie sauvegardé
{
    int tourjoueur,i;
    tourjoueur=0; // initialisation, premier tour pour le premier joueur
    for (i=1; i<nbjoueur; i++)
    {
        if(j[i].tour < j[i-1].tour) //on cherche le plus petit tour
        {
            tourjoueur = i;
        }
        else
        {
            continue;
        }

    }

    return tourjoueur+1;
}
