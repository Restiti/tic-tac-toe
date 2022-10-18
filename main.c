#include "main.h"

int main(void){
    char tab[] = {' ',' ',' ',
                  ' ',' ',' ',
                  ' ',' ',' '};


    //afficheTab(tab);
    /*
    poserCase(0, tab, 'O');
    poserCase(1, tab, 'O');
    poserCase(2, tab, 'O');

    printf("-%d\n", partie_fini(tab, 0,'O'));
    printf("-%d\n", partie_fini(tab, 1,'O'));
    printf("-%d\n", partie_fini(tab, 2,'O'));
    
   */
    poserCase(2, tab, 'O');
    poserCase(5, tab, 'O');
    poserCase(8, tab, 'O');

   
    printf("-%d\n", partie_fini(tab, 2,'O'));
    printf("-%d\n", partie_fini(tab, 5,'O'));
    printf("-%d\n", partie_fini(tab, 8,'O'));
    
    afficheTab(tab);

    return 0;
}
