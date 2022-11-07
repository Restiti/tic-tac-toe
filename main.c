#include "main.h"
#define MAX_ENTREE 80


void pvp(){
    struct info_jeu game = initInfoJeu();
    int joueur[] = {'X', 'O'};
    char choix[512] = ""; 
    while (!partie_fini(game.map , game.derniere_case_joue, joueur[game.tour%2], game.taille_map, game.tour)){
        ++game.tour;
        system("clear");
        afficheTab(game.map, game.taille_map);

        printf("C'est au tour du joueur %d\n", game.tour%2 + 1);
        fgets(choix, MAX_ENTREE, stdin);
        game.derniere_case_joue = atoi(choix) - 1;
        int is_numeric = game.derniere_case_joue > 0 && game.derniere_case_joue < game.taille_map * game.taille_map -2;
        while (poserCase(game.derniere_case_joue, game.map, joueur[game.tour%2]) && !is_numeric){
            system("clear");
            if (!is_numeric){
                printf("La saisie n'est pas valide\n");
            }else{
                printf("La case est déjà prise\n");
            }
            afficheTab(game.map, game.taille_map);
            fgets(choix, MAX_ENTREE, stdin);
            game.derniere_case_joue = atoi(choix) - 1;
            is_numeric = game.derniere_case_joue > 0 && game.derniere_case_joue < game.taille_map * game.taille_map -2;
        }
    }

    system("clear");
    afficheTab(game.map, game.taille_map);
    if (partie_fini(game.map, game.derniere_case_joue, joueur[game.tour%2], game.taille_map, game.tour) == -1)
    {
        printf("Le joueur %d a gagné\n", game.tour%2 + 1);
    }else{
        printf("C'est une égalité\n");
    }
}

void pve(){
    struct info_jeu game = initInfoJeu();
    int pions[] = {'X', 'O'};
    srand(time(NULL));
    int tourJoueur = rand()%2;
    char choix[512] = ""; 

    while (!partie_fini(game.map, game.derniere_case_joue, pions[game.tour%2], game.taille_map, game.tour)){
        ++game.tour;
        system("clear");
        afficheTab(game.map, game.taille_map);
        
        if (game.tour%2 == tourJoueur){

            printf("C'est au tour du joueur %d\n", game.tour%2 + 1);
            fgets(choix, MAX_ENTREE, stdin);
            game.derniere_case_joue = atoi(choix) - 1;
            int is_numeric = game.derniere_case_joue > 0 && game.derniere_case_joue < game.taille_map * game.taille_map -2;
            while (poserCase(game.derniere_case_joue, game.map, pions[game.tour%2]) && !is_numeric){
                system("clear");
                if (!is_numeric){
                    printf("La saisie n'est pas valide\n");
                }else{
                    printf("La case est déjà prise\n");
                }
                afficheTab(game.map, game.taille_map);
                fgets(choix, MAX_ENTREE, stdin);
                game.derniere_case_joue = atoi(choix) - 1;
                is_numeric = game.derniere_case_joue > 0 && game.derniere_case_joue < game.taille_map * game.taille_map -2;
            }
        }else{
            //automatique
            printf("C'est au tour de l'ordi\n");
            int n = rand()%(game.taille_map*game.taille_map);
            game.derniere_case_joue = n;
            while (poserCase(game.derniere_case_joue, game.map, pions[game.tour%2])){
                system("clear");
                n = rand()%(game.taille_map*game.taille_map);
                game.derniere_case_joue = n;
                afficheTab(game.map, game.taille_map);
            }
        }
    }
    system("clear");

    afficheTab(game.map, game.taille_map);
    if (partie_fini(game.map, game.derniere_case_joue, pions[game.tour%2], game.taille_map, game.tour) == -1){
        printf("Le joueur %d a gagné\n", game.tour%2 + 1);
    }else{
        printf("C'est une égalité\n");
    }
}

void iaVSia(){
    srand(time(NULL));
    int nbPartie = 100;
    int *resultat = malloc(nbPartie * sizeof(int));

    for (int i = 0; i < nbPartie; i++){
        int res = deroulement_ia_vs_ia();
        *(resultat+i)=res;
    }
    int nbEgalite = 0;
    int winJ1 = 0;
    int winJ2 = 0;
    for (int i = 0; i < nbPartie; i++){
        switch (resultat[i])
        {
        case -1:
            nbEgalite++;
            break;
        case 0:
            winJ1++;
            break;
        case 1:
            winJ2++;
            break;    
        default:
            break;
        }
    }
    printf("Nb egalite: %d\n", nbEgalite);
    printf("Win J1    : %d\n", winJ1);
    printf("Win J2    : %d\n", winJ2);

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
        iaVSia();
    }


    return 0;
}
