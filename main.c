#include "main.h"

int main(void){
    char tab[] = {' ',' ',' ',
                  ' ',' ',' ',
                  ' ',' ',' '};


    afficheTab(tab);
    /*LIGNE
    poserCase(0, tab, 'O');
    poserCase(1, tab, 'O');
    poserCase(2, tab, 'O');

    printf("-%d\n", partie_fini(tab, 0,'O'));
    printf("-%d\n", partie_fini(tab, 1,'O'));
    printf("-%d\n", partie_fini(tab, 2,'O'));
    */

    poserCase(0, tab, 'O');
    poserCase(3, tab, 'O');
    poserCase(4, tab, 'O');

    poserCase(6, tab, 'O');
   
    printf("-%d\n", partie_fini(tab, 0,'O'));
    printf("-%d\n", partie_fini(tab, 3,'O'));
    printf("-%d\n", partie_fini(tab, 6,'O'));

    afficheTab(tab);

    return 0;
}
