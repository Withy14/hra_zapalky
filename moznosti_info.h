#ifndef MOZNOSTI_INFO_H_INCLUDED
#define MOZNOSTI_INFO_H_INCLUDED

int moznosti_menu();
int moznosti_menu_oddelovace(char c);
void info();

#ifndef MAX_SIZE
#define MAX_SIZE 1000
#endif

typedef struct
{
    char autor[MAX_SIZE];
    int autor_id;
    float verze;
    char strucne_info[MAX_SIZE];
}  info_o_programu;

#endif // MOZNOSTI_INFO_H_INCLUDED
