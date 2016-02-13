#include "gamefun.h"

void affiche_table(joueur j[]) //fonction pour afficher la table,avec les score dedans,pour simplifier la prise de décison
{
    printf("\n");
    if(j->score_flag[0] == 0) //si la case du tableau n'est pas rempli, il n'affiche pas de resultat
        printf("1-Somme des Un\n");
    else //si la case du tableau est rempli, affiche le score obtenue dans les tours précédent
        printf("1-Somme des Un\t\t%d\n",j->score[0]);
    if(j->score_flag[1] == 0)
        printf("2-Somme des Deux\n");
    else
        printf("2-Somme des Deux\t%d\n",j->score[1]);
    if(j->score_flag[2] == 0)
        printf("3-Somme des Trois\n");
    else
        printf("3-Somme des Trois\t%d\n",j->score[2]);
    if(j->score_flag[3] == 0)
        printf("4-Somme des Quatre\n");
    else
        printf("4-Somme des Quatre\t%d\n",j->score[3]);
    if(j->score_flag[4] == 0)
        printf("5-Somme des Cinq\n");
    else
        printf("5-Somme des Cinq\t%d\n",j->score[4]);
    if(j->score_flag[5] == 0)
        printf("6-Somme des Six\n");
    else
        printf("6-Somme des Six\t\t%d\n",j->score[5]);
    if(j->score_flag[6] == 0)
        printf("7-Brelan\n");
    else
        printf("7-Brelan\t\t%d\n",j->score[6]);
    if(j->score_flag[7] == 0)
        printf("8-Carre\n");
    else
        printf("8-Carre\t\t\t%d\n",j->score[7]);
    if(j->score_flag[8] == 0)
        printf("9-Full\n");
    else
        printf("9-Full\t\t\t%d\n",j->score[8]);
    if(j->score_flag[9] == 0)
        printf("10-Petite Suite\n");
    else
        printf("10-Petite Suite\t\t%d\n",j->score[9]);
    if(j->score_flag[10] == 0)
        printf("11-Grande Suite\n");
    else
        printf("11-Grande Suite\t\t%d\n",j->score[10]);
    if(j->score_flag[11] == 0)
        printf("12-Yam's\n");
    else
        printf("12-Yam's\t\t%d\n",j->score[11]);
    if(j->score_flag[12] == 0)
        printf("13-Chance\n\n");
    else
        printf("13-Chance\t\t%d\n\n",j->score[12]);

}
