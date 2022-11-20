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

int ask_nb_partie(){

    char choix[512] = ""; 
    int nb_partie = 0;

    while (nb_partie == 0)
    {
        printf("Nb partie?\n");
        fgets(choix, MAX_ENTREE, stdin);
        nb_partie = atoi(choix);
    }
    
    return nb_partie;
}

int ask_taille_carte(){
    char choix[512] = ""; 
    int taille_carte = -1;

    while (taille_carte <= 0 || taille_carte > 9)
    {
        printf("Taille de la carte (9 max)?\n");
        fgets(choix, MAX_ENTREE, stdin);
        taille_carte = atoi(choix);
    }
    
    return taille_carte;
}