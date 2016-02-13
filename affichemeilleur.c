#include <stdio.h>
#include <stdlib.h>
#include "gamefun.h"

void affiche_meilleur() //affiche les 10 meilleur score dans la categorie de Jeu en Groupe et Jeu Solo
{
    meilleurscore score[10],score_single[10]; //on va remplir le tableau de score de type meilleurscore,avec les scores qu'on a dans le ficher de topscore.dat et topscoresingle.dat
    FILE *fp; //fichier de topscore.dat
    FILE *fp2;  //fichier de topscoresingle.dat
    int i;
    fp=fopen("topscore.dat","rb");

    if (fp != 0) //si le fichier existe,alors au moins un jeu a ete jouer dans cette categorie
    {
        printf("Jeu En Groupe : \n");
        for (i=0; fread(&score[i],sizeof(score[i]),1,fp)==1; i++) //si la taille de 1 bloc et egale a la taille d'une case de type meilleurscore,alors on le lit
        {
            printf("%d- Joueur : %s\tScore : %d\n",i+1,score[i].nom,score[i].total); //afficher le nom et score des joueuer
        }
        fclose(fp); //fermeture du fichier
    }

    fp2=fopen("topscoresingle.dat","rb");
    if (fp2 != 0) //si le fichier existe,alors au moins un jeu a ete jouer dans cette categorie
    {
        printf("-----------------------------------------------------------\n");
        printf("Jeu Solo : \n");
        for (i=0; fread(&score_single[i],sizeof(score_single[i]),1,fp2)==1; i++) //si la taille de 1 bloc et egale à taille d'une case de type meilleurscore,alors on le lit
        {
            printf("%d- Joueur : %s\tScore : %d\n",i+1,score_single[i].nom,score_single[i].total); //afficher le nom et le score des joueurs
        }
        fclose(fp2); //fermeture du fichier
    }


}
