#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#include "joueur.h"
#include "ennemis.h"
#include "fight.h"
#include "menu.h"
#include "map.h"
#include "run.h"
#include "save.h"


void intro(){
  system("clear");
  printf(" ▄▄▄▄▄▄▄ ▄▄▄     ▄▄▄▄▄▄▄ ▄▄▄▄▄▄   ▄▄▄▄▄▄▄ ▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄▄▄▄\n");
  printf("█       █   █   █       █   ▄  █ █       █      █       █       █   ▄  █ \n");
  printf("█   ▄▄▄▄█   █   █    ▄▄▄█  █ █ █ █   ▄▄▄▄█  ▄   █▄     ▄█   ▄   █  █ █ █ \n");
  printf("█  █  ▄▄█   █   █   █▄▄▄█   █▄▄█▄█  █  ▄▄█ █▄█  █ █   █ █  █ █  █   █▄▄█▄ \n");
  printf("█  █ █  █   █▄▄▄█    ▄▄▄█    ▄▄  █  █ █  █      █ █   █ █  █▄█  █    ▄▄  █\n");
  printf("█  █▄▄█ █       █   █▄▄▄█   █  █ █  █▄▄█ █  ▄   █ █   █ █       █   █  █ █\n");
  printf("█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄█  █▄█▄▄▄▄▄▄▄█▄█ █▄▄█ █▄▄▄█ █▄▄▄▄▄▄▄█▄▄▄█  █▄█\n");
}


void menuDemarrage(Player **ppj, ListePlayer **ppl){

  int choix;
  // system("clear");
  //do{
  //le tableau affiché dans le terminal
  printf("\n*************************************************\n");
  printf("|\t\tMenu de démarrage :\t\t|\n");
  printf("*************************************************\n|");
  printf("\t\t\t\t\t\t" );
  printf("|\n|\t1.Nouvelle partie \t\t\t|\n");
  printf("|\t\t\t\t\t\t|\n" );
  printf("|\t2.Charger partie enregistrée  \t\t|\n");
  printf("|\t\t\t\t\t\t|\n" );
  printf("|\t3.Supprimer une partie enregistrée  \t|\n");
  printf("|\t\t\t\t\t\t|\n" );
  printf("|\t4.Quitter \t\t\t\t|\n");
  printf("|\t\t\t\t\t\t|\n" );
  printf("|\tEntrez votre choix : \t\t\t|\n");
  printf("|\t\t\t\t\t\t|\n" );
  printf("*************************************************\n" );
  scanf("%d", &choix);
    switch (choix) // appel des différentes fonctions/procédures
    {              // en fonction du choix fait par l'utilisateur
      case 1:
        purgeSTDIN();
        initPlayer(ppj, ppl);
        initCaste(ppj);

        break;

      case 2:
        //chargerSauvegarde()
        //printf("Reprendre partie");
        break;
      case 3:
        printf("Reprendre supp");
        break;
      case 4:
        printf(" \n");
        exit(0); // Sortie du programme choisie par l'utilisateur
        break;
      default:
        printf("Entrée incorrecte.\n");
        printf("S'il vous plait entrez une valeur correcte.\n");
    //}
  }
  system("clear");
}

void purgeSTDIN(){
  char ch;

  while((ch=getchar())!= '\n' && ch!=EOF);
}

void menu_jeu(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple){
  // ListePlayer *pl = NULL;
  //pl = pl->prem_el;
  int choix;
  system("clear");
  do{
    //le tableau affiché dans le terminal
    printf("\n*************************************************\n");
    printf("|\t\tMenu du jeu :\t\t\t|\n");
    printf("*************************************************\n|");
    printf("\t\t\t\t\t\t" );
    printf("|\n|\t1.Sauvegarder la partie \t\t|\n");
    printf("|\t\t\t\t\t\t|\n" );
    printf("|\t2.Reprendre partie \t\t\t|\n");
    printf("|\t\t\t\t\t\t|\n" );
    printf("|\t3.Quitter le jeu  \t\t\t|\n");
    printf("|\t\t\t\t\t\t|\n" );
    printf("|\tEntrez votre choix : \t\t\t|\n");
    printf("|\t\t\t\t\t\t|\n" );
    printf("*************************************************\n" );
    scanf("%d", &choix);
    switch (choix) // appel des différentes fonctions/procédures
    {              // en fonction du choix fait par l'utilisateur
      case 1:
        ecrireSauvegarde(ppl);

        break;

      case 2:
        runGame(ppj, ppe, ppl, pple, 1);
        break;
      case 3:
        exit(0);
        break;
      case 4:
        printf(" \n");
        exit(0); // Sortie du programme choisie par l'utilisateur
        break;
      default:
        printf("Entrée incorrecte.\n");
        printf("S'il vous plait entrez une valeur correcte.\n");
    }
    system("clear");
  }
  while(1);
}


void menuAttack(Player **ppj, Enemy **ppe){

  int choix;

  printf("\t1. HeadShot,\n\t 2. ChestShot\n\t 3. LimbShot\n");
  printf("Choisissez votre option : ");
  scanf("%d", &choix);

  while(choix<1 || choix>3){
    printf("Choisissez votre option : ");
    scanf("%d", &choix);
    printf("\n");
  }
  switch(choix){
    // Partie pour le joueur
    case 1 :
      headShot(ppj, ppe, choix);
      break;

    case 2 :
      chestShot(ppj, ppe, choix);
      break;

    case 3 :
      limbShot(ppj, ppe, choix);
      break;

    // Partie pour les mobs
      // On utilisera certianement un srand
      // avec son rand que l'on importera via une commande certainement
      // par adresse en utilisant un pointeur.. Faut voir :)
    case 4 :
      headShot(ppj, ppe, choix);
      break;

    case 5 :
      chestShot(ppj, ppe, choix);
      break;

    case 6 :
      limbShot(ppj, ppe, choix);
      break;
  }
}
void menuCombatOrc(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple){
    int choix;
    system("clear");
    do{
    //le tableau affiché dans le terminal
    printf("\t\t   ▄▄█▀▀██                 \n");
    printf("\t\t ▄█▀      ██  ▄▄▄ ▄▄    ▄▄▄▄    \n");
    printf("\t\t ██        ██  ██▀ ▀▀ ▄█   ▀▀  \n");
    printf("\t\t ▀█▄      ██   ██     ██       \n");
    printf("\t\t   ▀▀█▄▄▄█▀   ▄██▄     ▀█▄▄▄▀ ");
    printf("\n\t*************************************************\n");
    printf("\t|\t\tMenu de combat  :\t\t|\n");
    printf("\t*************************************************\n\t|");
    printf("\t\t\t\t\t\t" );
    printf("|\n\t|\t\tQue faire ? \t\t\t|\n");
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t|\t\t1.HeadShot  \t\t\t|\n");
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t|\t\t2.ChestShot  \t\t\t|\n");
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t|\t\t3.LimbShot \t\t\t|\n");
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t|\t\t4.Fuir lamentablement ...\t|\n");
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t|\t\tEntrez votre choix : \t\t|\n");
    printf("\t|\t\t\t\t\t\t|\n" );
    printf("\t*************************************************\n" );
    scanf("%d", &choix);
      switch (choix) // appel des différentes fonctions/procédures
      {              // en fonction du choix fait par l'utilisateur
        case 1:
          headShot(ppj, ppe, 3);
          break;
        case 2:
          //chestShot(&ppj, &ppe, 2);
          break;
        case 3:
          //limbShot(&ppj, &ppe, 1);
          break;
        case 4:
          ((*ppj)->x += 1);
          ((*ppj)->y +=1);
          runGame(ppj, ppe, ppl, pple, 1);
          break;
        default:
          printf("Entrée incorrecte.\n");
          printf("S'il vous plait entrez une valeur correcte.\n");
      }
      system("clear");
    }
    while(1);
}
