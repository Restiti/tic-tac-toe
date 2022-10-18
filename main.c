#include "main.h"
#define MAX_ENTREE 80

void pvp(){
    char tab[] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int joueur[] = {'X', 'O'};
    int case_joue = 0;
    int tour = -1;
    char choix[512] = ""; 

    while (partie_fini(tab, case_joue, joueur[tour%2])){
        ++tour;
        system("clear");
        afficheTab(tab);

        printf("C'est au tour du joueur %d\n", tour%2 + 1);
        fgets(choix, MAX_ENTREE, stdin);
        case_joue = choix[0] - '0' - 1;
        while (poserCase(case_joue, tab, joueur[tour%2])){
            system("clear");
            printf("La case est déjà prise\n");
            afficheTab(tab);
            fgets(choix, MAX_ENTREE, stdin);
            case_joue = choix[0] - '0' + 1;
        }
    }
    system("clear");
    afficheTab(tab);
    printf("Le joueur %d a gagné\n", tour%2 + 1);
}


int main(void){

    char choix[512] = ""; 

    do{
        system("clear");
        menu();
        fgets(choix, MAX_ENTREE, stdin);
    }while (!strstr(choix, "1")  && !strstr(choix, "2")  && !strstr(choix, "3") );

    if (strstr(choix, "1")){
        printf("PVP\n");
        pvp();
    }else if (strstr(choix, "2")){
        printf("PVE\n");
    }else{
        printf("ORDI vs ORDI\n");
    }
    
    return 0;
}
