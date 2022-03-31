#ifndef HEADERFILE_H

    #include<stdio.h>
    #include<windows.h>
    #include<conio.h>
    #include<ctype.h>
    #include<string.h>
    #include<stdlib.h>
    #include<time.h>

    typedef unsigned long long ull;
    typedef long long ll;

    #define MARGIN printf("\n\n\n\n\n\n\n\n\n\n"); 
    #define smMARGIN printf("\n\n\n\n"); 
    #define xsmMARGIN printf("\n\n"); 
    #define ENTER 13
    #define TAB 9
    #define BKSP 8
    #define SPACE 32
    #define FLUSH fflush(stdin); fflush(stdout);

    #include "pateint.h"
    #include "menu.h"
    #include "title.h"
    #include "graphic.h"

    #ifndef GOTO_XY
        #define GOTO_XY
            COORD c;    
            #define GOTOXY(x, y) c.X = x; c.Y = y; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    #endif
    
#endif