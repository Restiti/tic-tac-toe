#include "main.h"
#define MAX_ENTREE 80

void pvp(){
    int taille_tab = 3;
    char* tab = malloc(sizeof(char) * taille_tab);
    initMap(tab, taille_tab);

    int joueur[] = {'X', 'O'};
    int case_joue = 0;
    int tour = -1;
    char choix[512] = ""; 

    while (!partie_fini(tab, case_joue, joueur[tour%2], taille_tab, tour)){
        ++tour;
        system("clear");
        afficheTab(tab, taille_tab);

        printf("C'est au tour du joueur %d\n", tour%2 + 1);
        fgets(choix, MAX_ENTREE, stdin);
        case_joue = atoi(choix) - 1;
        int is_numeric = case_joue > 0 && case_joue < taille_tab * taille_tab -2;
        while (poserCase(case_joue, tab, joueur[tour%2]) && !is_numeric){
            system("clear");
            if (!is_numeric){
                printf("La saisie n'est pas valide\n");
            }else{
                printf("La case est déjà prise\n");
            }
            afficheTab(tab, taille_tab);
            fgets(choix, MAX_ENTREE, stdin);
            case_joue = atoi(choix) - 1;
            is_numeric = case_joue > 0 && case_joue < taille_tab * taille_tab -2;
        }
    }
    system("clear");
    afficheTab(tab, taille_tab);
    if (partie_fini(tab, case_joue, joueur[tour%2], taille_tab, tour) == -1)
    {
        printf("Le joueur %d a gagné\n", tour%2 + 1);
    }else{
        printf("C'est une égalité\n");
    }
}

void pve(){
    int taille_tab = 25;
    char* tab = malloc(sizeof(char) * taille_tab);
    initMap(tab, taille_tab);
    int pions[] = {'X', 'O'};
    srand(time(NULL));
    int tourJoueur = rand()%2;
    int case_joue = 0;
    int tour = -1;
    char choix[512] = ""; 

    while (!partie_fini(tab, case_joue, pions[tour%2], taille_tab, tour)){
        ++tour;
        system("clear");
        afficheTab(tab, taille_tab);
        
        if (tour%2 == tourJoueur){

            printf("C'est au tour du joueur %d\n", tour%2 + 1);
            fgets(choix, MAX_ENTREE, stdin);
            case_joue = atoi(choix) - 1;
            int is_numeric = case_joue > 0 && case_joue < taille_tab * taille_tab -2;
            while (poserCase(case_joue, tab, pions[tour%2]) && !is_numeric){
                system("clear");
                if (!is_numeric){
                    printf("La saisie n'est pas valide\n");
                }else{
                    printf("La case est déjà prise\n");
                }
                afficheTab(tab, taille_tab);
                fgets(choix, MAX_ENTREE, stdin);
                case_joue = atoi(choix) - 1;
                is_numeric = case_joue > 0 && case_joue < taille_tab * taille_tab -2;
            }
        }else{
            //automatique
            printf("C'est au tour de l'ordi\n");
            int n = rand()%(taille_tab*taille_tab);
            case_joue = n;
            while (poserCase(case_joue, tab, pions[tour%2])){
                system("clear");
                n = rand()%10;
                case_joue = n;
                afficheTab(tab, taille_tab);
            }
        }
    }
    system("clear");

    afficheTab(tab, taille_tab);
    if (partie_fini(tab, case_joue, pions[tour%2], taille_tab, tour) == -1){
        printf("Le joueur %d a gagné\n", tour%2 + 1);
    }else{
        printf("C'est une égalité\n");
    }
}


int main(void){

    char choix[512] = ""; 

    do{
        system("clear");
        menu();
        fgets(choix, MAX_ENTREE, stdin);
    }while (!strstr(choix, "1")  && !strstr(choix, "2")  && !strstr(choix, "3") );

    if (strstr(choix, "1")){
        pvp();
    }else if (strstr(choix, "2")){
        pve();
    }else{
        printf("ORDI vs ORDI\n");
    }
    
    return 0;
}
