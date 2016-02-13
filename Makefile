CC= gcc
OPTIONS = -Wall
yam : decision.o lance.o menu.o nouvellepartie.o sauvegarde.o load.o startgame.o affichemeilleur.o classementscore.o affichescore.o tourde.o gameovercheck.o menujeu.o pause.o affichetable.o main.o
	$(CC) $(OPTIONS) decision.o lance.o menu.o nouvellepartie.o sauvegarde.o load.o startgame.o affichemeilleur.o classementscore.o affichescore.o tourde.o gameovercheck.o menujeu.o main.o affichetable.o pause.o -o yam
main.o : main.c gamefun.h
	$(CC) $(OPTIONS) -c main.c
decision.o : decision.c gamefun.h
	$(CC) $(OPTIONS) -c decision.c
lance.o : lance.c gamefun.h
	$(CC) $(OPTIONS) -c lance.c
menu.o : menu.c gamefun.h
	$(CC) $(OPTIONS) -c menu.c
nouvellepartie.o : nouvellepartie.c gamefun.h
	$(CC) $(OPTIONS) -c nouvellepartie.c
sauvegarde.o : sauvegarde.c gamefun.h
	$(CC) $(OPTIONS) -c sauvegarde.c
load.o : load.c gamefun.h
	$(CC) $(OPTIONS) -c load.c
startgame.o : startgame.c gamefun.h
	$(CC) $(OPTIONS) -c startgame.c
affichemeilleur.o : affichemeilleur.c gamefun.h
	$(CC) $(OPTIONS) -c affichemeilleur.c
classementscore.o : classementscore.c gamefun.h
	$(CC) $(OPTIONS) -c classementscore.c
affichescore.o : affichescore.c gamefun.h
	$(CC) $(OPTIONS) -c affichescore.c
tourde.o : tourde.c gamefun.h
	$(CC) $(OPTIONS) -c tourde.c
gameovercheck.o : gameovercheck.c gamefun.h
	$(CC) $(OPTIONS) -c gameovercheck.c
menujeu.o : menujeu.c gamefun.h
	$(CC) $(OPTIONS) -c menujeu.c
pause.o : pause.c gamefun.h
	$(CC) $(OPTIONS) -c pause.c
affichetable.o : affichetable.c gamefun.h
	$(CC) $(OPTIONS) -c affichetable.c

clean :
	rm -f *.o yam
