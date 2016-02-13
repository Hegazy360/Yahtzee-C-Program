#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gamefun.h"

void start_game(int nbjoueur,joueur jou[],int tourde)

{
    int i,tour,j,k,testInt,flag[10],nbfixe,place_de_des,lance,x,*combinaison,finale,gameover;
    char arrete,testChar;
    srand((unsigned)time(NULL));
    while(gameover!=1) //pour voir si le jeu est fini
    {
        for (x=tourde; x<=nbjoueur; x++) //voir c'est le tour de qui à jouer(premier si c'est une nouvelle partie, mais sa peut être une autre personne qui débute, si c'est un jeu que l'on a chargé)
        {
            printf("Tour numero %d de %s\n",jou[x-1].tour,jou[x-1].nom);
            for (j= 0; j<5; j++) //initialisation des flag de dé
            {
                flag[j]=0;
            }
            affiche_table(&jou[x-1]); //affiche la table de resultat
            for (lance=1; lance<=3; lance++) //lancement 3 fois
            {

                combinaison=lancer(flag); //on met dans combinaison l'address du tableau qui est retourner de la fonction lancer

                if (lance==3) //si on a fait 3 lancer,on fixe tout les dés qui reste
                {
                    for (i=0; i<nbfixe; i++)
                    {
                        flag[i]=1;
                    }
                    break;
                }
                else //si c'est moins que 3 lancer
                {

                    for(k=0; k>=0; k++)
                    {
                        printf("Combien de dés voulez-vous fixer ? (Entre 0 et 5) : ");
                        testInt=scanf("%d",&nbfixe);
                        if (testInt!=1 || nbfixe<0 || nbfixe>5 ) //verification des données
                        {
                            printf("Erreur, Le nombre doit être compris entre 0 et 5!\nRéessayer\n");
                            while ((testChar = getchar())!= '\n');
                        }

                        else if(nbfixe>=0 && nbfixe<=5) //si on a obtenue un bon nombre on sort de la boucle
                        {
                            break;
                        }

                    }

                    if (nbfixe == 5 || (flag[0]==1 && flag[1]==1 && flag[2]==1 && flag[3]==1 && flag[4]==1)) //si tout les des sont fixe,c'est pas utile de faire un autre lancer
                    {
                        for (i=0; i<nbfixe; i++)
                        {
                            flag[i]=1;
                        }
                        break;

                    }
                    else if (nbfixe == 0) //si il n'y a pas de des fixe,on continue de lancer
                    {
                        continue;
                    }
                    else
                    {

                        printf("Choisi les %d dés que tu veux fixer :\n",nbfixe);
                        for (i=0; i<nbfixe; i++) 
                        {
                            for (k=0; k>=0; k++)
                            {
                                printf("Des %d: ",i+1);
                                testInt=scanf("%d",&place_de_des);
                                if (testInt!=1 || place_de_des<1 || place_de_des>5 ) //verification du nombre
                                {
                                    printf("Erreur ! Le nombre doit etre compris entre 1 et 5 !\nRéessayer!!\n");
                                    while ((testChar = getchar())!= '\n'); //pour ne pas prendre des caracteres inutile
                                }
                                else if(place_de_des >= 1 && place_de_des<=5)
                                {
                                    break;
                                }

                            }


                            if (flag[place_de_des-1]==1) //si le des sont deja fixe,sa ne va pas changer
                            {
                                printf("Des numero %d est deja fixe\n",place_de_des);
                            }
                            else flag[place_de_des-1]=1; //si ce n'est pas fixé,on le fixe
                        }

                        if ((flag[0]==1 && flag[1]==1 && flag[2]==1 && flag[3]==1 && flag[4]==1)) //on verifie si tout les des sont fixé,on va a la fonction decision
                        {
                            break;
                        }

                    }

                }
            }
            printf("\n");
            system("clear");
            printf("Combinaison final : \n"); //affiche le resultat final
            for (finale=0; finale<5; finale++)
            {
                printf("%d\t",combinaison[finale]);
            }
            printf("\n");

            decision(combinaison,&jou[x-1]); //aller a la fonction de decision
            printf("TOTAL = %d\n",jou[x-1].total); //affiche le total de joueurs 
            gameover=gameovercheck(jou,nbjoueur); //voir si le jeu est terminer

            arrete=pause();//demande si il veut arreter
            if (arrete=='p' || arrete=='P')
            {
                call_menu_jeu(jou,nbjoueur); //appelle le menu 
            }
            else
            {
                continue; //aller au tour suivant
            }
        }
    }

    affiche_score(nbjoueur,jou); //apres que le jeu est fini,on affiche qui a gagner,et on etudie si on va placer les score dans le fichier de 10 meilleurs scores
    call_menu(); //on appelle le menu
}
