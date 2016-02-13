#include "gamefun.h"

int call_menu() //le menu du debut de jeu,different du menu appeller au millieu du jeu
{
    int n,numjouer,x,testInt;
    char testChar;
    joueur j[3]; //table de 4 joueur maximum de type joueur defini dans la structure dans le fichier gamefun.h
    printf("1-Nouvelle partie\n");
    printf("2-Charger une partie en cours\n");
    printf("3-Afficher les meilleurs scores\n");
    testInt=scanf("%d",&n); //attend un nombre entre 1 et 3
    if (n==1)
    {
        nouvelle_partie(); //aller a la fonction " nouvelle partie" qui prend les information des joueurs
    }


    else if (n == 2)
    {
        load(&numjouer,j); // on met &numjoueur parce que on veux modifier sa valeur, sa depend combien de joueur sont dans le fichier "load"
        x=tour_de(numjouer,j); //un fonction pour savoir c'etait le tour a qui la derniere fois dans le jeu sauvgarde
        printf("Numero du joueur : %d\n",numjouer);
        start_game(numjouer,j,x); //on commence un jeu avec le nombre de joueur recuperer et la stucture des joueurs
    }
    else if (n==3)
    {
        affiche_meilleur(); //aller a la fonction qui affiche les 10 meilleurs scores
        printf("\nTapez sur Entree pour retourner au menu.\n");
        getchar();//il attend un caractere pour retourner au menu
        getchar();
        system("clear");
        call_menu();
    }


    else if (testInt!=1 || n<1 || n>3 )
    {
        printf("Erreur\n Il faut choisir un nombre entre 1 et 3 !\n");
        while ((testChar = getchar())!= '\n');
        call_menu();
    }




    return n;

}
