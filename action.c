#include "action.h"
#include "main.h"

int poserCase(int num_case, char* tab, char pion){
    if (tab[num_case] == ' '){
        tab[num_case] = pion;
        return 0;
    }
    return -1;
}

int partie_fini(char* tab, int num_case, char pion){
    //Ligne
    if(num_case%TAILLE_TAB == 0){
        if(tab[(num_case+1)%TAILLE_TAB + (num_case+1)/TAILLE_TAB] == pion && tab[(num_case+2)%TAILLE_TAB + (num_case+2)/TAILLE_TAB] == pion){
            return 0;
        }
    }else if(num_case%TAILLE_TAB == TAILLE_TAB-1){
        if(tab[(num_case-1)%TAILLE_TAB + (num_case-1)/TAILLE_TAB] == pion && tab[(num_case-2)%TAILLE_TAB + (num_case-2)/TAILLE_TAB] == pion){
            return 0;
        }
    }else{
        if(tab[(num_case-1)%TAILLE_TAB + (num_case-1)/TAILLE_TAB] == pion && tab[(num_case+1)%TAILLE_TAB + (num_case+1)/TAILLE_TAB] == pion){
            return 0;
        }
    }
    //Colonne
        if(num_case/TAILLE_TAB == 0){
        if(tab[(num_case+1*TAILLE_TAB)%TAILLE_TAB + (num_case+1*TAILLE_TAB)/TAILLE_TAB] == pion && tab[(num_case+2*TAILLE_TAB)%TAILLE_TAB + (num_case+2*TAILLE_TAB)/TAILLE_TAB] == pion){
            return 0;
        }
    }else if(num_case/TAILLE_TAB == TAILLE_TAB-1){
        if(tab[(num_case-1*TAILLE_TAB)%TAILLE_TAB + (num_case-1*TAILLE_TAB)/TAILLE_TAB] == pion && tab[(num_case-2*TAILLE_TAB)%TAILLE_TAB + (num_case-2*TAILLE_TAB)/TAILLE_TAB] == pion){
            return 0;
        }
    }else{
        if(tab[(num_case-1*TAILLE_TAB)%TAILLE_TAB + (num_case-1*TAILLE_TAB)/TAILLE_TAB] == pion && tab[(num_case+1*TAILLE_TAB)%TAILLE_TAB + (num_case+1*TAILLE_TAB)/TAILLE_TAB] == pion){
            return 0;
        }
    }

    
    return -1;
}