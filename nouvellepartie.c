#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gamefun.h"

void nouvelle_partie()
{
    int nombre_joueur,i,k,nj,testInt,ns,objectif;
    joueur j[3];
    char testChar;


    for (nj=0; nj<=3; nj++) //initialisation des case tour,total,objectif,cases des score et score_flag
    {
        for (ns=0; ns<=15; ns++)
        {
            j[nj].score[ns] = 0;
            j[nj].score_flag[ns] = 0;
        }

        j[nj].tour = 1;
        j[nj].total = 0;
        j[nj].objectif = 0;

    }

    for(k=0; k>=0; k++)
    {
        printf("Entrer le nombre de joueur : "); //prend l'information des joueurs
        testInt=scanf("%d",&nombre_joueur);

        if (testInt!=1 || nombre_joueur<1 || nombre_joueur>4 ) //verification d'entree
        {
            printf("Erreur! Le chiffre doit etre compris entre 1 et 4 !\nRéessayer!!\n");
            while ((testChar = getchar())!= '\n');
        }

        else if(nombre_joueur>=1 && nombre_joueur<=4) 
        {
            break;
        }


    }
    if (nombre_joueur > 1 && nombre_joueur <= 4) //si le nombre et plus grand que 1 et <= a 4,alors on joue en groupe
    {
        for (i=0; i<nombre_joueur; i++)
        {
            printf("Entrer le nom du joueur %d: ",i+1); //prendre le nom de chaque joueurs
            scanf("%s",&j[i].nom);
        }
        system("clear");
        start_game(nombre_joueur,j,1); //on commence le jeu avec le nombre de joueur,la structure des joueurs,et le premiere joueurs qui va commencer
    }

    else if (nombre_joueur == 1) //si le nombre de joueurs est un,on entre dans le mode solo
    {
        printf("Entrer le nom du joueur : "); //nom de joueurs
        scanf("%s",&j[0].nom);


        for(i=0; i<3; i++)
        {
            printf("Entrer votre objectif : "); //son objectif
            testInt=scanf("%d",&objectif);
            if (objectif>=0)
            {
                j[0].objectif=objectif;
                break;
            }
            else if (testInt!=1 || objectif < 0) //verification d'entree
            {
                printf("L'Objectif doit etre plus grand ou egal à 0\nRéessayer !(il vous reste %d essais)\n",3-(i+1));
		while ((testChar = getchar())!= '\n');
            }
            if (3-(i+1)==0) //si le joueurs a essayer 3 fois sans succes
            {
                exit(0);
            }
        }

        start_game(nombre_joueur,j,1); //on commence le jeu

        system("clear");
    }


}
