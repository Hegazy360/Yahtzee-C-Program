#include "gamefun.h"

int affiche_score(int nbjoueur,joueur j[]) //fonction affiche score, c'est elle qui decide qui a gagner et dans le cas d'un seul joueur,s'il a depasser son objectif de départ
{
    //la fonction prend la nombre de joueur,et le tableau de tout les joueurs
    int i,meilleur_score=0,gagnant,flag=0;

    if(nbjoueur>1) //dans le cas ou on joue en groupe
    {
        for(i=0; i<nbjoueur; i++)
        {
            printf("Score final de %s = %d\n",j[i].nom,j[i].total);
            if(j[i].total > meilleur_score)
            {
                meilleur_score = j[i].total; //on calcule le meilleur score et on le met dans meilleur_score
                gagnant = i; //i c'est l'indice du joueur qui a gagner dans le tableau de tout les joueurs
                flag=0;
            }
            else if(j[i].total == meilleur_score) //au cas ou il ya 2 joueurs avec la meme score
            {
              printf("%s et %s on la meme score!\n",j[i].nom,j[gagnant].nom);
              flag=1;
            }

        }
        if (flag==0)
        {printf("%s A GAGNE!!!\n",j[gagnant].nom);} //on affiche le nom du joueur qui a gagné
        classement_score(j,nbjoueur); //fonction pour decider si le score des joueurs sont parmis les 10  meilleurs scores
     }
    else //dans le cas ou c'est un seul joueur qui a joué
    {
        printf("Score final de %s = %d\n",j[0].nom,j[0].total); //on affiche le score final 
        if(j[0].total >= j[0].objectif) //pour voir s'il a depasseé son objectif
        {
            printf("Vous Avez Gagne!\n");
            classement_score(&j[0],nbjoueur); //on voit si son score est dans les 10 meilleur
        }
        else //si il n'a pas passer son objectif
        {
            printf("Vous avez perdu!\n");
            classement_score(&j[0],nbjoueur);

        }

    }
    printf("\n");

}
