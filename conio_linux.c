/**
* conio.h is not standard part of the C and is basically obsolete
* - there are three solutions how to handle functions getch and getche
* -- use NCUrses
* -- use conio_ilinux.h
* -- use  fcntl() and ioctl() system calls
*
* NCurses might be the favourable option however to simplify
* the initial project I am going with the second option.
* If allowed by time I will rewrite it using the font() and
* ioctl() system calls. NCurses are at the moment overkill.
*
* The following code is not of my doing however it is freely usable
* under GNU/GPL license
*/

#ifndef _WIN32

#include <termios.h>
#include <unistd.h>
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
/* reads from keypress, echoes */
int getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

#endif
