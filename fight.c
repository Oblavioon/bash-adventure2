#include <stdio.h>
#include <stdlib.h>

#include "joueur.h"
#include "ennemis.h"
#include "fight.h"
#include "menu.h"
#include "map.h"
#include "run.h"
#include "save.h"



void interPE(Player **ppj, Enemy **ppe){
	int temp;

	temp = ((*ppj)->x + (*ppj)->y) - ((*ppe)->x + (*ppe)->y); 

	if(temp==0){
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
	if(choix==1){
		(*ppe)->hp -= 3;
		printf("-3Hp avec HeadShot pour l'ennemi.\n");
	}else{
		(*ppj)->hp -= 3;
		printf("Subi -3Hp avec HeadShot pour le hero.\n");
	}

}
// Dans le cas où l'on aurait un chestshot de la part de l'ennemis ou du joueur
void chestShot(Player **ppj, Enemy **ppe, int choix){
	if(choix==2){
		(*ppe)->hp -= 2;
		printf("-3Hp avec ChestShot.\n");
	}else{
		(*ppj)->hp -= 2;
		printf("Subi -3Hp avec ChestShot.\n");
	}
}
// Dnas le cas où l'on aurait un limbshot de la part de l'ennemis ou du joueur
void limbShot(Player **ppj, Enemy **ppe, int choix){
	if(choix ==3){
		(*ppe)->hp -= 1;
		printf("-3Hp avec LimbShot.\n");
	}else{
		(*ppj)->hp -= 1;
		printf("Subi -3Hp avec LimbShot.\n");
	}
}

