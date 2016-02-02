#include "std_operace.h"

//#define POCET_RADKU 4
#define POCET_SLOUPCU 5

static const int POCET_RADKU=4;

/**
* delimiters for main menu of program
*/
int menu_oddelovace(char c)
{
    char pole[POCET_RADKU][POCET_SLOUPCU] = {{'1','Z','z','1','1'},
                   {'2','N','n','2','2'},
                   {'3','M','m','3','3'},
                   {'4','K','k','Q','q'}};
    int i,j,index = -1;
    int nasel = 0;

    do
    {
        for(i=0; i<POCET_RADKU; i++)
        {
            for(j=0; j<POCET_SLOUPCU; j++)
            {
                if(!nasel)
                {
                    index = (pole[i][j]==c?i:-2) + 1;
                    nasel = index!=-1?1:0;
                }
            }
        }
        nasel = 1;
    }
    while(!nasel);

    return index;
}

int* submenu_1_starthry()
{
    /**
    * setting-up default values
    */
    int oponent_stupen = 0;
    int obtiznost_stupen = 0;
    char oponent[2][100];
    char obtiznost[3][100];
    static int pole[3];
    strcpy(oponent[0], "clovek");
    strcpy(oponent[1], "pocitac");
    strcpy(obtiznost[0], "I'm too young to die! (zacatecnik)");
    strcpy(obtiznost[1], "Hurt me plenty! (zlatý stred)");
    strcpy(obtiznost[2], "Nightmare! (no proste nigthmare :D)");
    int opakuj = 1;

    do
    {
        system(CLEAR_SCREEN);
        printf("(S)tart hry:\n-------------------------------------------------\nO(p)onent: %s\nO(b)tiznost: %s\n(N)avrat do hlavniho menu\n-------------------------------------------------\nVolba: ",oponent[oponent_stupen],obtiznost[obtiznost_stupen]);
        switch(getche())
        {
        case 'p':
        case 'P':
            oponent_stupen = (oponent_stupen + 1) % 2;
            break;
        case 'b':
        case 'B':
            obtiznost_stupen = (obtiznost_stupen + 1) % 3;
            break;
        case 's':
        case 'S':
            pole[0] = 1;
            opakuj = 0;
            break;
        case 'n':
        case 'N':
            printf("\nVracim se do hlavniho menu.\nStisknete libovolnou klavesu,");
            opakuj = 0;
            pole[0] = 0;
            getche();
            break;
        default:
            printf("\nNeplatna volba,\nStisknete libovolnou klavesu pro navrat do menu.");
            getche();
        }
    }
    while(opakuj);

    system(CLEAR_SCREEN);
    pole[1] = oponent_stupen;
    pole[2] = obtiznost_stupen;

    return pole;
}
