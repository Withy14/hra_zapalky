/**
* @author Mario Kalus, 162992
* @date 05.01.2016
* @version 0.1
*
* @note Initial program for classic game of matches
*
*/

#include "std_operace.h"
#include "hra_vs.h"
#include "moznosti_info.h"
#include "moznosti_nastaveni.h"


int main()
{
    int pokracuj = 1;
    int volba;
    int * pole;
    int porazeny;
    /** fflush(stdin); */
    do
    {
        printf("Hra Zapalky\n------------------\n(Z)acit novou hru\n(N)acist ulozenou\n(M)oznosti\n(K)onec\n------------------\nVolba: ");
        volba = menu_oddelovace(getche());
        switch(volba)
        {
        case 1:
            /**
            * pole[0] = 0...no start, =1..start
            * pole[1] = 0...human, =1...CPU
            * pole[2] = 0,1,2...obtiznost pro CPU
            */
            pole = submenu_1_starthry();

            /**
            * printf("Pole: %d %d %d", pole[0], pole[1], pole[2]);
            */
            if(pole[0] == 1)
            {
                int oponent = pole[1];
                int obtiznst = pole[2];
                porazeny = starthry(oponent, obtiznst);
                (oponent == 0)?(porazeny = porazeny==0?2:1):(porazeny = porazeny==4?4:1);
                if (porazeny != 4)
                {
                    printf("Hrac %d prohral, zbyla na nej posledni zapalka.", porazeny);
                }
                else
                {
                    printf("Porazil si pocitac, neeeeee.");
                }
                getch();
            }
            break;
        case 2:
            system(CLEAR_SCREEN);
            printf("\n2 - Funkce ulozeni neni implemenotvana.\nBude soucasti client-server modulu.");
            getch();
            break;
        case 3:
            moznosti_menu();
            break;
        case 4:
            printf("\nUkoncuji program.\nDekuji za pouzitit.");
            getch();
            pokracuj = 0;
            break;
        default:
            ;
            printf("\nNeplatna volba,\nStisknete libovolnou klavesu pro navrat do menu.");
            getch();
            /** break; //neni nutny v default */
        }
        system(CLEAR_SCREEN);
    }
    while (pokracuj == 1);
    return 0;
}
