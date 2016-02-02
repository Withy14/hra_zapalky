#include "std_operace.h"
#include "moznosti_info.h"

#define POCET_RADKU_v2 5
#define POCET_SLOUPCU_v2 5

int moznosti_menu()
{
    int volba;
    int pokracuj = 1;
    do
    {
        system(CLEAR_SCREEN);
        printf("Moznosti a informace o programu\n");
        printf("--------------------------------\n");
        printf("(I)nfo o programu\n");
        printf("(E)ULA\n");
        printf("(P)arametry\n");
        /** printf("(H)elp\n"); */
        printf("(N)avrat do hlavniho menu\n");
        printf("--------------------------------\n");
        printf("Volba: ");
        volba = moznosti_menu_oddelovace(getche());
        switch(volba)
        {
        case 1:
            info();
            break;
        case 2:
            system(CLEAR_SCREEN);
            printf("EULA programu\n------------------------------------------------------------\n");
            printf("Program spada pod licenci GNU/GPLv2.\nDulezite body GNU/GPL:\n-- program lze modifikovat\n-- program lze sirit\n-- musi byt zachovano jmeno autoria\n-- program nesmi byt pouzit ke komercnim ucelum\n");
            printf("Plne zneni GNU/GPLv2 pro pripad jakychkoliv nejasnosti:\n-- http://www.gnu.org/licenses/old-licenses/gpl-2.0.html");
            printf("\n------------------------------------------------------------\n");
            getch();
            break;
        case 3:
            system(CLEAR_SCREEN);
            printf("\n3 -Parametry - uprava parametru neni implementovana.\nBude soucasti client-server modulu.");
            getch();
            break;
        case 4:
            printf("\nHelp");
            break;
        case 5:
            printf("\nVracim se do hlavniho menu.\nStisknete libovolnou klavesu");
            pokracuj = 0;
            getche();
            break;
        default:
            ;
            /** printf("Neplatna volba."); */
            /** break; */
        }
    }
    while (pokracuj == 1);

    return 0;
}

int moznosti_menu_oddelovace(char c)
{
    char pole[POCET_RADKU_v2][POCET_SLOUPCU_v2] = {{'1','I','i','1','1'},
                   {'2','E','e','2','2'},
                   {'3','P','p','3','3'},
                   {'4','H','h','3','3'},
                   {'5','N','n','4','4'}};
    int i,j,index = -1;
    int nasel = 0;

    do
    {
        for(i=0; i<POCET_RADKU_v2; i++)
        {
            for(j=0; j<POCET_SLOUPCU_v2; j++)
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

void info()
{
    system(CLEAR_SCREEN);
    printf("Info o programu\n-----------------------------------------------\n");
    info_o_programu t_info;
    char test_text1[MAX_SIZE], test_text2[MAX_SIZE], radek[MAX_SIZE];
    int nasel_a = 0, nasel_i = 0, nasel_v = 0, nasel_info = 0;
    FILE * fp;
    fp = fopen("proginfo.txt","rt");
    if(fp != NULL)
    {
        while(fgets(radek,MAX_SIZE,fp) != NULL)
        {
            //fgets(radek,100,fp);
            sscanf(radek ,"%s %[^\n]s", test_text1, test_text2);
            if(nasel_a == 0)
            {
                strcmp("Autor:",test_text1) == 0?(strcpy(t_info.autor,test_text2)):(strcpy(t_info.autor,"n/a"));
                strcmp("Autor:",test_text1) == 0?(nasel_a = 1):0;
            }
            if(nasel_i == 0)
            {
                strcmp("ID:",test_text1) == 0?(t_info.autor_id=strtol(test_text2,NULL,10)):(t_info.autor_id=-1);
                strcmp("ID:",test_text1) == 0?(nasel_i = 1):0;
            }
            if(nasel_v == 0)
            {
                strcmp("Verze:",test_text1) == 0?(t_info.verze=strtof(test_text2,NULL)):(t_info.verze=-1);
                strcmp("Verze:",test_text1) == 0?(nasel_v = 1):0;
            }
            if(strcmp("Strucne_info:",test_text1) == 0)
            {
                if(nasel_info == 0)
                {
                    strcpy(t_info.strucne_info,test_text2);
                    nasel_info = 1;
                }
                else
                {
                    strcat(t_info.strucne_info,"\n-- ");
                    strcat(t_info.strucne_info,test_text2);
                }
            }
        }
        printf("Autor programu: %s, %d", t_info.autor, t_info.autor_id);
        printf("\nVerze programu: %.2f", t_info.verze);
        printf("\nStrucne info:\n-- %s", t_info.strucne_info);
        printf("\n-----------------------------------------------\n");
    }
    fclose(fp);
    getche();
}
