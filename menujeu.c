#include "gamefun.h"

int call_menu_jeu(joueur jou[],int numj) //c'est le menu appellé, si nous sommes entrain de jouer,il y a l'option retourner au jeu en cours et sauvgarder en plus
{
    int n,numjouer,i,x,testInt;
    char d,testChar;
    joueur j[3];
    printf("1-Retourner au jeu en cours\n");
    printf("2-Nouvelle partie\n");
    printf("3-Sauvegarder la partie\n");
    printf("4-Charger une partie en cours\n");
    printf("5-Afficher les meilleurs scores\n");
    testInt=scanf("%d",&n);
    if(n==1)
    {

    }

    else if (n==2)
    {
        nouvelle_partie();
    }
    else if (n == 3)
    {
        sauvegarde(jou,numj);
        printf("Est-ce que tu veux continuer le jeu en cours?\nY pour continer - N pour quitter - M pour retourner au menu\n");
        //on demande au joueur apres qu'on est sauvgarde, s'il veut continuer le jeu,ou quitter,ou retourner au menu
        getchar();
        scanf("%s",&d);
        for (i=0; i<=10; i++)
        {
            if (d=='N' || d=='n') //si il veut quitter
            {
                printf("Au Revoir!\n");
                exit(0);
            }
            else if (d=='Y' || d=='y') //si il veut continuer le jeu en cours
            {
                break;
            }

            else if (d=='M' || d=='m') //si il veut retourner au menu
            {
                call_menu_jeu(jou,numj);
            }
            else printf("Pas identifier,Réessayer!!\n");
        }

    }
    else if (n == 4)
    {
        printf("ATTENTION LE JEU EN COURS VA ETRE EFFACER!!!\nEst-ce que vous etes sure que vous voulez proceder a cela ?\nY pour charger le fichier - N pour retourner au menu\n");
        //on affiche un warning,si le joueur n'a pas sauvgarder le jeu,il va l'effacer apres qu'il est chargé une autre partie
        getchar();
        scanf("%s",&d);

        for (i=0; i<=10; i++)
        {
            if (d=='N' || d=='n') //si il veut retourner au menu
            {
                call_menu_jeu(jou,numj);
            }
            else if (d=='Y' || d=='y') //si il veut charger le fichier
            {
                load(&numjouer,j); // on met &numjoueur parce qu'on veux modifier sa valeur
                x=tour_de(numjouer,j);//pour savoir c'etait le tour de qui,on va chercher le joueur avec le nombre de tour le plus petit

                printf("Nombre de joueur = %d\nC'est le tour du joueur %d : %s \n",numjouer,x,j[x-1].nom);
                start_game(numjouer,j,x);//on commence un jeu avec le nombre de joueur calculer dans load,le tableau de tout les joueurs, etle joueur qui va jouer en premier
            }
            else printf("Pas identifier,Ressayer\n"); //si l'option n'est pas identifier
        }


    }
    else if (n==5)
    {
        affiche_meilleur();//la fonction pour afficher les 10 meilleur score dans la categorie de jeu en groupe et jeu solo
        printf("\nTapez sur Entree pour retourner au menu.\n");//il attend qu'on tape sur Entree pour retourner au menu
        getchar();
        getchar();
        system("clear");
        call_menu_jeu(jou,numj);
    }
    else if (testInt!=1 || n<1 || n>3 )
    {
        printf("Erreur\n Il faut choisir un nombre entre 1 et 5 !\n"); //si l'option n'existe pas, il rappelle le menu_jeu
        while ((testChar = getchar())!= '\n');
        call_menu_jeu(jou,numj);
    }

    return n;

}
