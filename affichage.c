#include "affichage.h"
#include "main.h"
 
void afficheTab(char* tab,int taille){
    printf("+");
    for (int i = 0; i < taille; i++)
    {
        printf("-+");
    }
    printf("\n");
    

    for (int i = 0; i < taille; i++){
        for (int j = 0; j < taille; j++)
        {
            printf("|%c", tab[i*taille+j]);
        }
        printf("|\n+");
        
        for (int i = 0; i < taille; i++){
            printf("-+");
        }
        printf("\n");    
    }
}

void menu(){
    printf("Bienvenue sur le jeu du TIC-TAC-TOE\n");
    printf("1. Partie 1VS1\n2. Joueur VS Ordinateur\n3. Ordinateur VS Ordinateur\n");
    printf("4. Historique de parties\n");
}