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
    
    if(tour > taille_tab * taille_tab - 2) return 1;
    
    //Ligne

    if(num_case%taille_tab == 0){
        if(tab[num_case+1] == pion && tab[num_case+2] == pion){
            return -1;
        }   
    }else if(num_case%taille_tab == taille_tab-1){
        if(tab[num_case-1] == pion && tab[num_case-2] == pion){
            return -1;
        }
    }else if(tab[num_case-1] == pion && tab[num_case+1] == pion){
        return -1;
    }

    //Colonne
    if(num_case/taille_tab == 0){
        if(tab[num_case+ taille_tab] == pion && tab[num_case + 2 * taille_tab] == pion){
            return -1;
        }
    }else if(num_case/taille_tab == taille_tab-1){
        if(tab[num_case-1*taille_tab] == pion && tab[num_case-2*taille_tab] == pion){
            return -1;
        }
    }else if(tab[num_case-1*taille_tab] == pion && tab[num_case+1*taille_tab] == pion){
            return -1;
        
    }
    //Diagonale
    /*
    if (num_case == 5){

    }
    */
    
    return 0;
}

void initMap(char* tab, int taille){

    for (int i = 0; i < taille*taille; i++){
            tab[i] = ' ';
    }
}
