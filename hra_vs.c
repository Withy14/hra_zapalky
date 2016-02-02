#include "std_operace.h"
#include "hra_vs.h"
#include <ctype.h>
#include <time.h>

int starthry(int oponent, int obtiznost)
{
    system(CLEAR_SCREEN);

    int porazeny;

    if(oponent == 0)
    {
        printf("V ramci fair-play verim, ze se budete poctive stridat ve hre.\nStisknete libovolnou klavesu pro start hry.");
        getche();
        system(CLEAR_SCREEN);
        porazeny = human_oponent(obtiznost);
    }
    else if (oponent == 1)
    {
        system(CLEAR_SCREEN);
        printf("Budete hrat proi PC.\nObtiznos je: %d", obtiznost);
        srand (time(NULL));
        int randNum = (rand()%2)+1;
        int start = 0;
        printf("\nZacinat bude: ");
        if(randNum == 1)
        {
            printf("PC");
            start = 0;
        }
        else if (randNum == 2)
        {
            printf("clovek");
            start = 1;
        }
        porazeny = pc_oponent(obtiznost, start);
    }
    getche();
    return porazeny;
}

void tiskni_sirky(int pocet)
{
    int i;
    for(i = 0; i<pocet; i++)
    {
        printf("| ");
    }
    printf("\n");
    for(i = 0; i<pocet; i++)
    {
        printf("| ");
    }
    printf("\n");
    for(i = 0; i<pocet; i++)
    {
        printf("O ");
    }
}

int human_oponent(int obtiznost)
{
    int pocet = 30, odeber = 0;
    int hrac = 0;
    tiskni_sirky(pocet);
    do
    {
        if(obtiznost == 0)
        {
            printf("\nHrac %d (potvrdte enterem): ", hrac + 1);
            scanf("%d", &odeber);
            if(odeber>0 && odeber<4)
            {
                pocet = pocet - odeber;
                hrac = (hrac + 3) % 2;
                tiskni_sirky(pocet);
            }
            else
            {
                printf("Neplatna volba. Zadejte znova.");
                getche();
            }
            odeber = 0;
            fflush(stdin);
        }
        else
        {
            printf("\nHrac %d: ", hrac + 1);
            odeber = getche() - 48;
            printf("\n");
            if(odeber>0 && odeber<4)
            {
                pocet = pocet - odeber;
                hrac = (hrac + 3) % 2;
                tiskni_sirky(pocet);
            }
            else
            {
                printf("Neplatna volba. Zadejte znova.");
                getch();
            }
            odeber = 0;
            fflush(stdin);
        }
    }
    while(pocet > 0);
    return hrac;
}

int pc_oponent(int obtiznost, int start)
{
        system(CLEAR_SCREEN);
        int hrac = 0;
        int prvni_tah = 0;
        int pocet = 30, odeber = 0;
        int randNum;
        tiskni_sirky(pocet);
        /** Prvni krok pro cloveka */
        if(start == 0 && prvni_tah == 0)
        {
            printf("\nPocet sirek k odebrani: ");
            odeber = getche() - 48;
            printf("\n");
            if(odeber>0 && odeber<4)
            {
                pocet = pocet - odeber;
                tiskni_sirky(pocet);
                prvni_tah = 1;
                hrac = 1;
            }
            else
            {
                printf("Neplatna volba. Zadejte znova.");
                getche();
            }
            odeber = 0;
            fflush(stdin);
        }

        switch(obtiznost)
        {
        case 0:
            randNum = 0;
            break;
        case 1:
            randNum = (rand()%3)+1;
            break;
        case 2:
            randNum = 101;
            break;
        }

        int vyherni_zbytek = 0;
        int pokracuj = 1;
        do
        {
            vyherni_zbytek = pocet % 4;
            if(pocet != 1)
            {
                hrac = 4;
                if((obtiznost == 2) || (obtiznost == 1 && randNum == 2))
                {
                    switch(vyherni_zbytek)
                    {
                        case 0:
                            printf("\nOdebiram: 3\n");
                            pocet = pocet - 3;
                            tiskni_sirky(pocet);
                            break;
                        case 1:
                            srand (time(NULL));
                            randNum = (rand()%3)+1;
                            printf("\nOdebiram: %d\n", randNum);
                            if (pocet != 1)
                            {
                                pocet = pocet - randNum;
                            }
                            else
                            {
                                pocet = pocet - 1;
                            }
                            tiskni_sirky(pocet);
                            break;
                        case 2:
                            printf("\nOdebiram: 1\n");
                            pocet = pocet - 1;
                            tiskni_sirky(pocet);
                            break;
                        case 3:
                            printf("\nOdebiram: 2\n");
                            pocet = pocet - 2;
                            tiskni_sirky(pocet);
                            break;
                        default:
                            ;
                    }
                }
                else
                {
                    srand (time(NULL));
                    randNum = (rand()%3)+1;
                    printf("\nOdebiram: %d\n", randNum);
                    if (pocet != 1)
                    {
                        pocet = pocet - randNum;
                    }
                    else
                    {
                        pocet = pocet - 1;
                    }
                    tiskni_sirky(pocet);
                }
            }
            else
            {
                printf("\nOdebiram: 1\n");
                pocet = pocet - 1;
                tiskni_sirky(pocet);
                hrac = 4;
            }

            pokracuj = 1;
            while((pokracuj == 1) && (pocet >= 0))
            {
                printf("\nPocet sirek k odebrani: ");
                odeber = getche() - 48;
                printf("\n");
                if(odeber>0 && odeber<4)
                {
                    pocet = pocet - odeber;
                    tiskni_sirky(pocet);
                    pokracuj = 0;
                    hrac = 1;
                }
                else
                {
                    printf("Neplatna volba. Zadejte znova.");
                    //getche();
                }
            }

//            while((pokracuj == 1) && (pocet == 2))
//            {
//                printf("\nPocet sirek k odebrani: ");
//                odeber = getche() - 48;
//                printf("\n");
//                if(odeber > 0 && odeber < 3)
//                {
//                    pocet = pocet - odeber;
//                    tiskni_sirky(pocet);
//                    pokracuj = 0;
//                    hrac = 1;
//                }
//                else
//                {
//                    printf("Neplatna volba. Zadejte znova.");
//                    //getche();
//                }
//            }
//
//            while((pokracuj == 1) && (pocet == 1))
//            {
//                printf("\nPocet sirek k odebrani: 1");
//                pocet = pocet - odeber;
//                tiskni_sirky(pocet);
//                pokracuj = 0;
//                hrac = 1;
//            }

            odeber = 0;
            fflush(stdin);
        }
        while(pocet > 0);
        return hrac;
}
