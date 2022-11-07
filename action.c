#include "main.h"
#include "action.h"

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
            cpt +=1;
        }
    }

    if(cpt == taille_tab){
        return -1;
    }

    cpt = 0;

    for(int i=taille_tab-1;i<taille_tab*taille_tab-1;i+=taille_tab-1){
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

struct info_jeu initInfoJeu(){
    int taille_map = 3;

    struct info_jeu* info = malloc(
        sizeof(char) * (taille_map * taille_map)
        + 5* sizeof(int)
    );
    info->taille_map= taille_map;
    info->derniere_case_joue=0;
    info->tour = -1;
    info->nb_partie = 10;
    info->map=malloc(sizeof(char) * (taille_map * taille_map));
    info->partie_fini=0;
    initMap(info->map, info->taille_map);

    return *info;
}

void *play_iavsia(void *data){
    //struct info_jeu *game = data;
    struct info_jeu *game = data;
    int pions[] = {'X', 'O'};
    while (!game->partie_fini){

            pthread_mutex_lock(&verrou);
            if(game->partie_fini){
                pthread_mutex_unlock(&verrou);
                return NULL;
            }
            ++game->tour;

            
            int n = rand()%(game->taille_map*game->taille_map);
            game->derniere_case_joue = n;
            while (poserCase(game->derniere_case_joue, game->map, pions[game->tour%2])){
                n = rand()%(game->taille_map*game->taille_map);
                game->derniere_case_joue = n;
            }
            game->partie_fini = (partie_fini(game->map, game->derniere_case_joue, 
                                        pions[game->tour%2], game->taille_map, game->tour));
        pthread_mutex_unlock(&verrou);
    }

    return NULL;
}


int deroulement_ia_vs_ia(){

    struct info_jeu game = initInfoJeu();
    pthread_t bot1, bot2;


    pthread_mutex_init(&verrou, NULL);

    pthread_create(&bot1, NULL, play_iavsia, (void *) &game );
    pthread_create(&bot2, NULL, play_iavsia, (void *) &game );

    pthread_join(bot1, NULL);
    pthread_join(bot2, NULL);

    pthread_mutex_destroy(&verrou);
    
    
    if (game.partie_fini == -1){
        return game.tour%2;
    }else{
        return -1;
    }
}