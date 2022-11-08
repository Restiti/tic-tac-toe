//Mettre le prototype des fonctions de action ici
int poserCase(int num_case, char* tab, char pion);
int partie_fini(char* tab, int num_case, char pion, int taille_tab, int taille);
void initMap(char* tab, int taille);
struct info_jeu initInfoJeu(int taille_map);
void *play_iavsia(void *data);
int deroulement_ia_vs_ia(char* fichier, int taille_map);
