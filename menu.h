#ifndef H_MENU_H
#define H_MENU_H



//FILE* fopen(const char* nomDuFichier, const char* modeOuverture);
//int fclose(FILE* pointeurSurFichier);
void intro();

void menuDemarrage(Player **ppj, ListePlayer **ppl);

void purgeSTDIN();

void menu_jeu(Player **ppj, Enemy **ppe, ListePlayer **ppl, ListeEnemy **pple);

void menuAttack(Player **ppj, Enemy **ppe);

/*
int menuCreationPerso();
int menuNom(Player *pp);
int menuSexe(Player *pp);
int menuCasteMale(Player *pp);
int menuCasteFemelle();
*/

#endif
