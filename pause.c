#include "gamefun.h"

char pause() //fonction pour arrete la jeu
{
    char d;
    printf("Tapez P pour arreter ou une autre touche pour continuer le jeu: \n"); //on attend un caractere et on l'envoi au jeu pour decider si on arrete ou non
    getchar();//pour ne pas prendre l'Entree en compte 
    scanf("%c",&d);

    return d;//retourne de la decision

}
