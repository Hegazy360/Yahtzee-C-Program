#include <stdio.h>
#include <stdlib.h>
#include "gamefun.h"


int *lancer(int flag[]) //on fait le pointeur de la fonction, parce qu'on va renvoyer une table de resultat pas une seule valeur
{
    int j,tab[1000];



    for (j=0; j<5; j++)
    {
        if (flag[j]==0) //si le flag de cette case de des est 0 alors ce n'est pas fixe, alors on a la permission de le changer!
        {
            tab[j]=rand()%(1-7) +1;
            printf("%d\t",tab[j]);
        }
        else printf("%d\t",tab[j]); //si le flag de cette case de des est 1 alors on n'a pas la permission de la changer,on l'affiche comme il l'est


    }

    printf("\n");

    return tab; //on retourne le nouveau tableau du resultat

}
