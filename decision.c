#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gamefun.h"




void decision(int combinaison[],joueur j[])
{
    int n,i,x,a=0,ressayer,flag_des[5]= {0},full=0,petit_suite=0,grand_suite=0,testInt;
    char testChar;
    for (ressayer=0; ressayer<=15; ressayer++) //Une boucle avec le nombre d'essais maximum
    {
        affiche_table(j); //affiche la table avec les resultat obtenu 
        printf("Quelle est votre decision?\n"); 
        testInt=scanf("%d",&n);//attend la decision du joueur
        printf("\n");
        if (n==1) //total dé un
        {

            if (j->score[0] == 0 && j->score_flag[0] == 0) //si la case est = 0 et il n'a pas etait utilise avant par le joueurs
            {
                for(i=0; i<5; i++) 
                {
                    if (combinaison[i]==1) //si un dé est = 1 on l'ajoute à la somme
                        a+=1;
                }

                j->score[0] = a; //on change le nouveeau score
                j->score_flag[0] = 1; //on change le flag pour ne pas reutiliser cette case
                j->tour++; //on incremente le tour
                j->total+=j->score[0]; //on incremente le total
                system("clear");
                printf("Somme des Un : %d Points\n",j->score[0]); //on affiche le resultat de cette case avant d'aller au tour suivant
                break;
            }
            else //si la case est deja rempli
            {
                system("clear");
                printf("Vous avez deja utiliser cette regle\n");
            }
        }
        else if (n==2) //total des 2
        {
            if (j->score[1] == 0 && j->score_flag[1] == 0)
            {
                for(i=0; i<5; i++)
                {
                    if (combinaison[i]==2)
                        a+=2;
                }
                j->score[1] = a;
                j->score_flag[1] = 1;
                j->tour++;
                j->total+=j->score[1];
                system("clear");
                printf("Somme des Deux : %d Points\n",j->score[1]);
                break;
            }
            else
            {
                system("clear");
                printf("Vous avez deja utiliser cette regle\n");
            }
        }

        else if (n==3) //total des 3
        {
            if (j->score[2] == 0 && j->score_flag[2] == 0)
            {
                for(i=0; i<5; i++)
                {
                    if (combinaison[i]==3)
                        a+=3;
                }
                j->score[2] = a;
                j->score_flag[2] = 1;
                j->tour++;
                j->total+=j->score[2];
                system("clear");
                printf("Somme des Trois : %d Points\n",j->score[2]);
                break;
            }
            else
            {
                system("clear");
                printf("Vous avez deja utiliser cette regle\n");
            }
        }
        else if (n==4) //total des 4
        {
            if (j->score[3] == 0 && j->score_flag[3] == 0)
            {
                for(i=0; i<5; i++)
                {
                    if (combinaison[i]==4)
                        a+=4;
                }
                j->score[3] = a;
                j->score_flag[3] = 1;
                j->tour++;
                j->total+=j->score[3];
                system("clear");
                printf("Somme des Quatre : %d Points\n",j->score[3]);
                break;
            }
            else
            {
                system("clear");
                printf("Vous avez deja utiliser cette regle\n");
            }
        }
        else if (n==5) //total des 5
        {
            if (j->score[4] == 0 && j->score_flag[4] == 0)
            {
                for(i=0; i<5; i++)
                {
                    if (combinaison[i]==5)
                        a+=5;
                }
                j->score[4] = a;
                j->score_flag[4] = 1;
                j->tour++;
                j->total+=j->score[4];
                system("clear");
                printf("Somme des Cinq : %d Points\n",j->score[4]);
                break;
            }
            else
            {
                system("clear");
                printf("Vous avez deja utiliser cette regle\n");
            }
        }
        else if (n==6) //total des 6
        {
            if (j->score[5] == 0 && j->score_flag[5] == 0)
            {
                for(i=0; i<5; i++)
                {
                    if (combinaison[i]==6)
                        a+=6;
                }
                j->score[5] = a;
                j->score_flag[5] = 1;
                j->tour++;
                j->total+=j->score[5];
                system("clear");
                printf("Somme des Six : %d Points\n",j->score[5]);
                break;
            }
            else
            {
                system("clear");
                printf("Vous avez deja utiliser cette regle\n");
            }
        }
        else if (n==7) //Brelan
        {
            if (j->score[6] == 0 && j->score_flag[6] == 0)
            {
                for (i=0; i<5; i++) //le dé est comparé avec tout les autre
                {
                    a=1;//nombre d'occurence
                    for (x=i+1; x<5; x++) 
                    {
                        if (combinaison[i]==combinaison[x]) //si il y a un des qui est egale au premier on augmente le nombre d'occurence
                        {
                            a++; //on incremente lenombre d'occurence
                        }
                    }
                    if (a>=3) //si il y a trois occurence,on sort
                        break;
                }
                if (a>=3) //si il y a trois occurence,c'est un brelan
                {
                    j->score[6] = 10;
                    j->score_flag[6] = 1;
                    j->tour++;
                    j->total+=j->score[6];
                    system("clear");
                    printf("C'est un Brelan : %d Points\n",j->score[6]);
                    break;
                }
                else //sinon ce n'est pas un brelan
                {
                    j->score[6] = 0;
                    j->score_flag[6] = 1;
                    j->tour++;
                    j->total+=j->score[6];
                    system("clear");
                    printf("Ce n'est pas un Brelan : %d Points\n",j->score[6]);
                    break;
                }
            }
            else
            {
                system("clear");
                printf("Vous avez deja utiliser cette regle\n");
            }
        }
        else if (n==8) //Carre
        {
            if (j->score[7] == 0 && j->score_flag[7] == 0) 
            {
                for (i=0; i<5; i++) //la meme que brelan
                {
                    a=1;
                    for (x=i+1; x<5; x++)
                    {
                        if (combinaison[i]==combinaison[x])
                        {
                            a++;
                        }
                    }
                    if (a>=4) //si il ya 4 occurence
                        break;
                }
                if (a>=4)
                {
                    j->score[7] = 40;
                    j->score_flag[7] = 1;
                    j->tour++;
                    j->total+=j->score[7];
                    system("clear");
                    printf("C'est un Carre : %d Points\n",j->score[7]);
                    break;
                }
                else
                {
                    j->score[7] = 0;
                    j->score_flag[7] = 1;
                    j->tour++;
                    j->total+=j->score[7];
                    system("clear");
                    printf("Ce n'est pas un Carre : %d Points\n",j->score[7]);
                    break;
                }
            }
            else
            {
                system("clear");
                printf("Vous avez deja utiliser cette regle\n");
            }
        }
        else if (n==9) //Full
        {


            if (j->score[8] == 0 && j->score_flag[8] == 0)
            {
                for (i=0; i<5; i++)
                {
                    flag_des[combinaison[i]-1]++;
                }

                if (flag_des[0] == 3 || flag_des[1] == 3 || flag_des[2] == 3 || flag_des[3] == 3 || flag_des[4] == 3 || flag_des[5] == 3) //on voit si il ya 3 occurence d'un chiffre,si oui,on vois si il ya 2 occurence d'un autre chiffre
                {
                    if (flag_des[0] == 2 || flag_des[1] == 2 || flag_des[2] == 2 || flag_des[3] == 2 || flag_des[4] == 2 || flag_des[5] == 2)
                    {
                        full=1; //si oui c'est un full
                    }
                    else full=0; //sinon ce n'est pas un full
                }

                if (full==1)
                {
                    j->score[8] = 30;
                    j->score_flag[8] = 1;
                    j->tour++;
                    j->total+=j->score[8];
                    system("clear");
                    printf("C'est un Full : %d Points\n",j->score[8]);
                    break;
                }
                else
                {
                    j->score[8] = 0;
                    j->score_flag[8] = 1;
                    j->tour++;
                    j->total+=j->score[8];
                    system("clear");
                    printf("Ce n'est pas un Full : %d Points\n",j->score[8]);
                    break;
                }

            }
            else
            {
                system("clear");
                printf("Vous avez deja utiliser cette regle\n");

            }
        }
        else if (n==10) //Petite suite
        {
            if (j->score[9] == 0 && j->score_flag[9] == 0)
            {
                for (i=0; i<5; i++)
                {
                    flag_des[combinaison[i]-1]++;
                }
                if (flag_des[0] == 1 && flag_des[1] == 1 && flag_des[2] == 1 && flag_des[3] == 1 && flag_des[4] == 1) //on voit si il ya 1 occurence pour 1,2,3,4,5
                {
                    petit_suite=1; //si oui c'est un petit suite
                }
                if (petit_suite==1)
                {
                    j->score[9] = 20;
                    j->score_flag[9] = 1;
                    j->tour++;
                    j->total+=j->score[9];
                    system("clear");
                    printf("Petite Suite : %d\n",j->score[9]);
                    break;
                }
                else
                {
                    j->score[9] = 0;
                    j->score_flag[9] = 1;
                    j->tour++;
                    j->total+=j->score[9];
                    system("clear");
                    printf("Ce n'est pas un Petite Suite : %d\n",j->score[9]);
                    break;
                }
            }
            else
            {
                system("clear");
                printf("Vous avez deja utiliser cette regle\n");

            }
        }
        else if (n==11) //Grande suite
        {
            if (j->score[10] == 0 && j->score_flag[10] == 0)
            {
                for (i=0; i<5; i++)
                {
                    flag_des[combinaison[i]-1]++;
                }
                if (flag_des[1] == 1 && flag_des[2] == 1 && flag_des[3] == 1 && flag_des[4] == 1 && flag_des[5]==1) //on voit si il ya 1 occurence pour 2,3,4,5,6
                {
                    grand_suite=1;
                }
                if (grand_suite==1)
                {
                    j->score[10] = 20;
                    j->score_flag[10] = 1;
                    j->tour++;
                    j->total+=j->score[10];
                    system("clear");
                    printf("Grande Suite : %d Points\n",j->score[10]);
                    break;
                }
                else
                {
                    j->score[10] = 0;
                    j->score_flag[10] = 1;
                    j->tour++;
                    j->total+=j->score[10];
                    system("clear");
                    printf("Ce n'est pas un Grande Suite : %d Points\n",j->score[10]);
                    break;
                }
            }
            else
            {
                system("clear");
                printf("Vous avez deja utiliser cette regle\n");
            }
        }
        else if (n==12) //Yam
        {
            if (j->score[11] == 0 && j->score_flag[11] == 0)
            {
                for (i=0; i<5; i++)
                {
                    a=1;
                    for (x=i+1; x<5; x++)
                    {
                        if (combinaison[i]==combinaison[x])
                        {
                            a++;
                        }
                    }
                    if (a>=5) //on voit si le nombre d'occurence pour un chiffre est de 5

                        break;
                }
                if (a>=5)
                {
                    j->score[11] = 50;
                    j->score_flag[11] = 1;
                    j->tour++;
                    j->total+=j->score[11];
                    system("clear");
                    printf("YAM! : %d Points\n",j->score[11]);
                    break;
                }
                else
                {
                    j->score[11] = 0;
                    j->score_flag[11] = 1;
                    j->tour++;
                    j->total+=j->score[11];
                    system("clear");
                    printf("Ce n'est pas un Yam : %d Points\n",j->score[11]);
                    break;
                }
            }
            else
            {
                system("clear");
                printf("Vous avez deja utiliser cette regle\n");
            }
        }
        else if (n==13) //Chance
        {
            if (j->score[12] == 0 && j->score_flag[12] == 0)
            {
                j->score[12] = combinaison[0]+combinaison[1]+combinaison[2]+combinaison[3]+combinaison[4]; //on fait la somme de tout les des
                j->score_flag[12] = 1;
                j->tour++;
                j->total+=j->score[12];
                system("clear");
                printf("Chance : %d Points\n",j->score[12]);
                break;
            }
            else
            {
                system("clear");
                printf("Vous avez deja utiliser cette regle\n");
            }
        }
        else if (testInt!=1 || n<1 || n>13 ) //verification d'entree pour eviter les boucles infinies
        {   system("clear");
            printf("Erreur, Le nombre doit être compris entre 1 et 13!\nRéessayer\n");
            while ((testChar = getchar())!= '\n');
        }
    }

    if((j->score[0] + j->score[1] + j->score[2] + j->score[3] + j->score[4] + j->score[5]) >=63 && j->score_flag[13] == 0) //pour calculer le bonus,si la somme des 6 premieres ligne(sommme de 1, jusqu'a 6) est supérieur ou égale à 63
    {
        j->score_flag[13]=1; //pour ne pas calculer le bonus un deuxieme fois,on mais un flag
        printf("Vous avez obtenu un bonus de 35 points!\n");
        j->total+=35;

    }

   if(ressayer==16) //dans le cas ou le joueurs a essayer 15 fois et n'a pas reussi a faire un decision,sa compter comme un tour
	{
	j->tour++;
	}


}
