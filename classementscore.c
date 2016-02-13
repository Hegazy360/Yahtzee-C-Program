#include <stdio.h>
#include <stdlib.h>
#include "gamefun.h"

void classement_score(joueur j[],int nbjoueur) //pour decider si le score des joueurs sont entre les 10 meilleurs scores
{
    meilleurscore score[20],joueur[5]; //on lit ce qui existe dans le fichier de topscore et on le met dans score[20],on met le nom et score du gagnant dans la variable gagnant
    FILE *fp; //on ouvre le fichier de topscore.dat ou topscoresingle.dat
    FILE *fp2; //on ouvre le fichier de topscore.dat ou topscoresingle.dat
    int i,k,x,count=0,n,m;
    for(m=0;m<nbjoueur;m++) //on transform les nom et total des joueurs au sturcture de type meilleurscore
    {strcpy(joueur[m].nom,j[m].nom); 
    joueur[m].total = j[m].total;} 



    if(nbjoueur > 1) //si c'est un jeu en groupe on ouvre topscore.dat pour le lire
    {
        fp2=fopen("topscore.dat","ab+");
        for (i=0; i<10; i++)
        {
            fread(&score[i],sizeof(score[i]),1,fp2); //on met ce qu'on a lue dans le tableau score de type meilleurscore
            if (feof(fp2)) //si c'est la fin du fichier et il ya moins de 10 score on arrete
            {
                break;
            }
        }
        fclose(fp2); //fermeture du fichier
    }
    else //si un joueur a joue seul,on fait la meme sauf qu'on ouvre le fichier topscoresingle.dat dans ce cas
    {
        fp2=fopen("topscoresingle.dat","ab+");
        for (i=0; i<10; i++)
        {
            fread(&score[i],sizeof(score[i]),1,fp2);
            if (feof(fp2))
            {
                break;
            }
        }
        fclose(fp2); //fermeture du fichier
    }


//l'algorithme pour placer le nouveau score dans le fichier
for(n=0;n<nbjoueur;n++)
{
    for (x=0; x<i; x++) //de 0 jusqu'a ce qu'on a lue dans le fichier topscore.dat ou topscoresingle.dat (maximum 10 joueur)
    {
        if(joueur[n].total < score[x].total) //si le total du gagnant est plus petit,alors on laisse le score qui existe dans la meme ordre sans changer
        {
            continue;
        }
        else //si le total du gagnant est plus grand,alors on va arrete,pour qu'on le place dans cette position
        {
            break;
        }
    }


    for (k=i; k>=x; k--) //on commence par la fin de toute les score lu du fichier,jusqu'a qu'on a arrete dans la boucle for avant
    {
        score[k+1] = score[k]; //on commence par decaler le dernier,pour avoir un place pour le nouveau score
    }

    score[x]=joueur[n]; //on met l'info du joueur gagnant dans la place vide qu'on vient d'obtenir
    i++;

}


    if(nbjoueur>1) //au cas ou c'etait un jeu en groupe
    {
        fp=fopen("topscore.dat","wb+");

        while(count<i && count < 10)  //pour le cas ou il n'y a pas encore 10 joueur dans le ficher (avec un maximum de 10 joueurs)
        {


            fwrite(&score[count],sizeof(score[count]),1,fp); //on va ecrire ce qu'on a dans le nouveau tableau du score trié ,dans le fichier topscore.dat
            count++;



        }
        fclose(fp); //fermeture du fichier
    }

    else
    {
        fp=fopen("topscoresingle.dat","wb+"); //au cas ou c'etait un jeu solo

        while(count<i && count <10)  //pour le cas ou il n'ya pas encore 10 joueurs dans le ficher (avec un maximum de 10 joueurs)
        {


            fwrite(&score[count],sizeof(score[count]),1,fp); //on va ecrire ce qu'on a dans le nouveau tableau du score trié,dans le fichier topscoresingle.dat
            count++;


        }
        fclose(fp); //fermeture du fichier

    }



}
