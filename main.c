#include "main.h"
#define MAX_ENTREE 80


void pvp(){

    int taille_carte = 5;
    printf("Taille de la carte?\n");
    scanf("%d", &taille_carte);

    struct info_jeu game = initInfoJeu(taille_carte);
    int joueur[] = {'X', 'O'};
    char choix[512] = ""; 
    fgets(choix, MAX_ENTREE, stdin);

    char fichier[74] = "";

    genere_fichier(fichier, TAILLE_NOM, taille_carte);

    save_entete(fichier, taille_carte, 1);
    game.fichier = fichier;
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
        enregistre_case(game.derniere_case_joue, joueur[game.tour%2], game.fichier);

    }
    enregistre_case(-1, 'F', game.fichier);
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

    int taille_carte = 5;
    printf("Taille de la carte?\n");
    scanf("%d", &taille_carte);

    struct info_jeu game = initInfoJeu(taille_carte);
    int pions[] = {'X', 'O'};
    srand(time(NULL));
    int tourJoueur = rand()%2;
    char choix[512] = ""; 
    fgets(choix, MAX_ENTREE, stdin);

    char fichier[74] = "";

    genere_fichier(fichier, TAILLE_NOM, taille_carte);

    save_entete(fichier, taille_carte, 1);
    game.fichier = fichier;
    
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
        enregistre_case(game.derniere_case_joue, pions[game.tour%2], game.fichier);

    }
    enregistre_case(-1, 'F', game.fichier);
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
    int nbPartie = 10000000;

    printf("Nombre de partie?\n");
    scanf("%d", &nbPartie);

    int *resultat = malloc(nbPartie * sizeof(int));
    
    //Faire la fonction qui demande la taille de la map
    int taille_carte = 3;
    printf("Taille de la carte?\n");
    scanf("%d", &taille_carte);
    char fichier[74] = "";

    genere_fichier(fichier, TAILLE_NOM, taille_carte);

    save_entete(fichier, taille_carte, nbPartie);

    for (int i = 0; i < nbPartie; i++){
        printf("Partie %d\n", i);
        int res = deroulement_ia_vs_ia(fichier, taille_carte);
        *(resultat+i)=res; 
    }
    //deroule_partie(fichier);

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
void charge_partie(){
    FILE* fichier;
    char choix[512] = ""; 
    char cmd[50];
    char nom_file[70];

    system("ls save| tr ' ' '\n' | nl ");
    
    fgets(choix, MAX_ENTREE, stdin);
    int num_fichier = atoi(choix);
    printf("FIchier numero %d\n", num_fichier);
    sprintf(cmd, "ls save | tr ' ' '\\n' | head -n %d | tail -n 1", num_fichier);

    fichier = popen(cmd, "r");
    fscanf(fichier, "%s", nom_file);
    fclose(fichier);
    
    char chemin[] = "save/";
    strcat(chemin, nom_file);
    strcpy(nom_file, chemin);
    
    deroule_partie(nom_file);
}



int main(void){
    
    char choix[512] = ""; 

    do{
        system("clear");
        menu();
        fgets(choix, MAX_ENTREE, stdin);
    }while (!strstr(choix, "1")  && !strstr(choix, "2")  && !strstr(choix, "3") && !strstr(choix, "4") );

    if (strstr(choix, "1")){
        pvp();
    }else if (strstr(choix, "2")){
        pve();
    }else if(strstr(choix, "3")){
        iaVSia();
    }else{
        charge_partie();
    }


    return 0;
}
