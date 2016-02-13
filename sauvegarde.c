#include <stdio.h>
#include <stdlib.h>
#include "gamefun.h"

void sauvegarde(joueur j[],int numjoueur)
{
    char filename[15],filenamedat[20],dat[]=".dat";
    FILE *fp;
    int i;
    printf("Entrer le nom de la Sauvegarde : ");
    scanf("%s",&filename); //prend un nom sans l'extension .dat
    snprintf(filenamedat,sizeof filenamedat,"%s%s",filename,dat); //concatenation du nom avec .dat
    fp=fopen(filenamedat,"wb+");//on ouvre le fichier,si il existe on efface ce qui est dedans
    for (i=0; i<numjoueur; i++)
    {
        fwrite(&j[i],sizeof(j[i]),1,fp); //ecriture des information de chaque joueurs dans un bloc
    }
    fclose(fp);//ferme le fichier
    printf("Jeu Sauvgarde!\n");
}
