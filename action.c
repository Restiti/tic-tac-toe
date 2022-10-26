#include "action.h"
#include "main.h"

int poserCase(int num_case, char* tab, char pion){
    if (tab[num_case] == ' '){
        tab[num_case] = pion;
        return 0;
    }
    return -1;
}

int partie_fini(char* tab, int num_case, char pion, int taille_tab, int tour){
    //match nul
    if(tour > taille_tab * taille_tab - 2) return 1;
    int ligne = (num_case/taille_tab)*taille_tab;
    int colonne = num_case%taille_tab;
    //Ligne
    int cpt = 0;
    for(int i=ligne;i<ligne+taille_tab;i++){
        if(tab[i] == pion ){
            cpt += 1 ;
        }
    }
    if(cpt == taille_tab){
            return -1;
    }




    //Colonne
    cpt = 0;
    for(int i=colonne;i< taille_tab*taille_tab;i+=taille_tab){
        if(tab[i] == pion){
            cpt +=1;
        }
    }

    if(cpt == taille_tab){
        return -1;
    }


    //Diagonale
    cpt = 0;
    for(int i=0;i<taille_tab*taille_tab;i+=taille_tab+1){
        if(tab[i] == pion){
            cpt += 1;
        }
    }

    if(cpt == taille_tab){
        return -1;
    }

    cpt = 0;

    for(int i=taille_tab-1;i<taille_tab*taille_tab;i+=taille_tab-1){
        if(tab[i] == pion){
            cpt +=1;
        }
    }

    if(cpt == taille_tab){
        return -1;
    }
    
    return 0;
}

void initMap(char* tab, int taille){

    for (int i = 0; i < taille*taille; i++){
            tab[i] = ' ';
    }
}
