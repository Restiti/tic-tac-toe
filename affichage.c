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