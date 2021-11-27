#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "joueur.h"
#include "ennemis.h"
#include "fight.h"
#include "menu.h"
#include "map.h"
#include "run.h"
#include "save.h"



void interPE(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple){
	int temp=0;

	temp = ((*ppj)->x + (*ppj)->y) - ((*ppe)->x + (*ppe)->y);

	if(temp == 0){
		menuCombatOrc(ppj, ppe, ppl, pple);
		printf("\nUn ennemi.\n");
	}

}


/*
scanf("%d", &attaque)
switch(attaque){
	case 1:
		choix = foncSemiAl(3)
		while(choix==0) foncSemiAl(3);
		headShot(ppj, ppe, choix)
}
*/



// On va simplement jouer avec les structures pour l'instant...
// Dans le cas où l'on aurait un headshot de la part de l'ennemis ou du joueur
void headShot(Player **ppj, Enemy **ppe, int choix){
	int attaque;

	// On appelle la fonction "fonSemiAl(x)"
	// elle nous permet de définir des dégâts d'attaque,
	// Attaque Critique; Attaque Normale; Et une attaque où si le joueur rate l'adversaire lui
	// inflige des coups... Propre à chacunes des attaques.
	attaque = foncSemiAl(6+1);
	if ( attaque == 6 ){
		(*ppe)->hp -= ((*ppj)->dp)+2;
	}
	if ( attaque >= 2 && attaque <= 5 ){
		(*ppe)->hp -=((*ppj)->dp) ;
	}
	if ( attaque == 1 ){
		(*ppe)->hp -= ((*ppj)->dp)-1;
	}
	else{
		(*ppj)->hp -= ((*ppe)->dp) ;
	}
		printf("-3Hp avec HeadShot pour l'ennemi.\n");

		printf("Subi -3Hp avec HeadShot pour le hero.\n");


}
// Dans le cas où l'on aurait un chestshot de la part de l'ennemis ou du joueur
void chestShot(Player **ppj, Enemy **ppe, int choix){
	int attaque;
	attaque = foncSemiAl(4+1);
	if (attaque==4){
		(*ppe)->hp -= ((*ppj)->dp)+2;
	}
	if (attaque>=2&&attaque<=3){
		(*ppe)->hp -= ((*ppj)->dp);
	}
	if (attaque==1){
		(*ppe)->hp -= ((*ppj)->dp)-1;
	}
	else{
		(*ppj)->hp -= ((*ppe)->dp);
	}
	printf("-3Hp avec ChestShot.\n");
	printf("Subi -3Hp avec ChestShot.\n");

}
// Dnas le cas où l'on aurait un limbshot de la part de l'ennemis ou du joueur
void limbShot(Player **ppj, Enemy **ppe, int choix){
	int attaque;
	attaque = foncSemiAl(3+1);
	if (attaque==3){
		(*ppe)->hp -= ((*ppj)->dp)+2;
	}
	if (attaque==2){
		(*ppe)->hp -= ((*ppj)->dp);
	}
	if (attaque==1){
		(*ppe)->hp -= ((*ppj)->dp)-1;
	}
	else{
		(*ppj)->hp -= ((*ppe)->dp);
	}
		printf("-3Hp avec LimbShot.\n");
		printf("Subi -3Hp avec LimbShot.\n");

}
