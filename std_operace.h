#ifndef STD_OPERACE_H_INCLUDED
#define STD_OPERACE_H_INCLUDED

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
    #include<conio.h>
#else
    #define CLEAR_SCREEN "clear"
    #include "conio_linux.h"
#endif

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int menu_oddelovace(char c);
int * submenu_1_starthry();

#endif // STD_OPERACE_H_INCLUDED
