#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <fcntl.h>

#define TAILLE_NOM 64
#define MAX_ENTREE 80

pthread_mutex_t verrou;
struct info_jeu {
    char* map;
    int taille_map;
    int derniere_case_joue;
    int tour;
    int nb_partie;
    int partie_fini;
    char* fichier;
} ;  

#include "affichage.h"
#include "action.h"
#include "histo.h"
