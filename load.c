#include <stdio.h>
#include <stdlib.h>
#include "gamefun.h"

void load(int *numjoueur,joueur j[])
{
    char filename[15],filenamedat[20],dat[]=".dat";
    FILE *fp;
    int i;
    printf("Entrer le nom du fichier: ");
    scanf("%s",&filename); //nom de fichier sans extension
    snprintf(filenamedat,sizeof filenamedat,"%s%s",filename,dat); //concatenation du nom de fichier avec .dat
    fp=fopen(filenamedat,"rb"); //ouverture du fichier .dat
    if(fp != 0) //si il existe
    {
        for (i=0; i<4; i++)
        {
            fread(&j[i],sizeof(j[i]),1,fp); //lire chaque bloc da la structure des joueurs,un bloc pour chacun,contenant tout les information
            if (feof(fp))
            {
                break;
            }


            *numjoueur=i+1; //modification de la valeur de nombre des joueurs apres chaque ecriture d'un bloc
        }
        printf("Jeu Charger!\n");
    }
    else //si il n'existe pas
    {
        printf("Ce FICHIER n'existe pas!\n");
        call_menu(); //retourne au menu
    }
    fclose(fp); //fermature de fichier
}
