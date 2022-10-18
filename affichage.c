#include "affichage.h"
#include "main.h"

void afficheTab(char* tab){
    printf(" +-+-+\n");
    for (int i = 0; i < TAILLE_TAB; i++){
        for (int j = 0; j < TAILLE_TAB; j++)
        {
            printf("|%c", tab[i*TAILLE_TAB+j]);
        }
        printf("|\n +-+-+\n");
    }
}

void menu(){
    printf("Bienvenue sur le jeu du TIC-TAC-TOE\n");
    printf("1. Partie 1VS1\n2. Joueur VS Ordinateur\n3. Ordinateur VS Ordinateur\n");
}