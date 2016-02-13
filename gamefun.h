#ifndef GAMEFUN_H   /* Include guard */
#define GAMEFUN_H  /* c'est l'ensemble de nos prototypes de fonctions et nos deux structures que l'on va inclure dans toute nos fonctions que l'on utilisera pour implémenter notre jeu !*/



// cette structure nous permettra pour revenir dans le jeux, car on va sauvergarder tout ce qui est utile pour continuer le jeu laisser en cours de partie


typedef struct{
    char nom[20];
    int score[15];
    int score_flag[15];            
    int tour;
    int total;
    int objectif;
} joueur;


          // cette structure nous permet de copier pour un joueur donnée son nom et son total, pour l'ecrire dans le fichier où l'on va stocker les meilleures scores !



typedef struct
{
  char nom[20];
  int total;
} meilleurscore;

void decision(int combinaison[],joueur j[]);
int *lancer(int flag[]);
void start_game(int nbjoueur,joueur jou[],int tourde);
void nouvelle_partie();
void sauvegarde(joueur j[],int numjoueur);
void load(int *numjoueur,joueur j[]);
int call_menu();
void affiche_meilleur();
void classement_score(joueur j[],int nbjoueur);
int affiche_score(int nbjoueur,joueur j[]);
int tour_de(int nbjoueur,joueur j[]);
int gameovercheck(joueur jou[],int numjoueur);
int call_menu_jeu(joueur jou[],int numj);
char pause();
void affiche_table(joueur j[]);

#endif




/*Les modules débute toujours par un couple de primitive de pré-compilation

#ifndef GAMEFUN_H (ifndef = if not def)
#define GAMEFUN_H

où GAMEFUN_H est un identifiant choisi arbitrairement mais qui doit être unique
et on met à la fin du fichier gamefun.h

#endif (fin du if du début !)

Cela permet au compilateur de s’assurer que le contenu de gamefun.h ne sera inclus qu’une seule
et unique fois lors de la compilation.
*/
