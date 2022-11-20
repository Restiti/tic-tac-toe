#include "main.h"
#include "histo.h"

void genere_fichier(char* nom, int taille, int tailleCarte){
      time_t now = time(NULL);
      struct tm * tm = localtime(&now);
      /* Utilise tm_year, tm_mday, tm_month, tm_hour, tm_min, tm_sec ou strftime: */
      strftime(nom, taille, "%A-%B-%d-%Y-%H:%M:%S", tm);
      char chemin[74] = "save/";
      strcat(chemin, nom);
      strcpy(nom, chemin);
      FILE* fichier = fopen(nom, "a");
      printf("%d\n", tailleCarte);


      fclose(fichier);
}

void save_entete(char* fichier_name, int taille_carte, int nb_partie){

  FILE* fichier = NULL;
  fichier = fopen(fichier_name, "a");

  char text[20];
  sprintf(text, "%d %d\n", taille_carte, nb_partie);   


  if (fichier != NULL){
    fputs(text , fichier);
    fclose(fichier);
  }
}

void enregistre_case(int case_joue, char pion, char* fichier_name){
  FILE* fichier = NULL;
  fichier = fopen(fichier_name, "a");
  char text[20];
  sprintf(text, "%d - %c\n", case_joue, pion);   

  if (fichier != NULL){
    fputs(text , fichier);
    fclose(fichier);
  }
}

void deroule_partie(char* nom_fichier){
  FILE* fichier;

  fichier = fopen(nom_fichier, "r");
  

  int taille_map;
  int nb_tour;
  fscanf(fichier, "%d %d", &taille_map, &nb_tour);
  printf("Taille de la carte : %d\n", taille_map);
  printf("Nombre de tour     : %d\n", nb_tour);
  
  for (int i = 0; i < nb_tour; i++){
    printf("Partie %d\n", i);
    struct info_jeu game = initInfoJeu(taille_map);
    int case_file = 0;
    char pion_file = ' ';
    
    while (case_file != -1 && pion_file != 'F'){
      game.tour++;
      fscanf(fichier, "%d - %c\n", &case_file, &pion_file);
      poserCase(case_file, game.map, pion_file);
    }
    afficheTab(game.map, taille_map);

  }
  
  
  fclose(fichier);
}