#include "gamefun.h"

int gameovercheck(joueur jou[],int numjoueur) //Pour voir si la jeu est finir,prend la table des joueurs et la numero des joueurs
{
    int i;
    for (i=0; i<numjoueur; i++)
    {
        if(jou[i].tour==14) //Le tour est initialiser a un et il ya 13 cases dans la tableau des resultat,alors quand le 13 tour est fini pour tout les joueurs,le jeu est fini
        {
            continue;
        }
        else return 0; //return 0 si le jeu n'est pas fini (un des joueurs n'a pas encore jouer 13 fois)
    }
    return 1; //return 1 si le jeu est fini (quand tout les joueurs on jouer 13 fois)
}
