#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "joueur.h"
#include "ennemis.h"
#include "fight.h"
#include "menu.h"
#include "map.h"
#include "run.h"
#include "save.h"

void runGame(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple, int firstparty){

	if(firstparty==0){
		intro();
		menuDemarrage(ppj, ppl);

		initEnemy(ppe, pple);

		if((*ppj)->nom[strlen((*ppj)->nom)-1]== '\n') (*ppj)->nom[strlen((*ppj)->nom)-1] = '\0';
		printf("Vous vous appelez %s, %s de Clergue.\n", (*ppj)->nom, (*ppj)->n_caste);

		firstparty++;
	}
	

	while(1){

      pVerdoyante(ppj);
      interPE(ppj, ppe);
      interactionPerso(ppj, ppl);


      system("clear");
    }

}

void temps(){

}
