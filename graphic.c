#include "header.h"

COORD c;
#define GOTOXY(x, y) c.X = x; c.Y = y; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);


void _patientDetails(){
    system("cls");
    MARGIN
    printf("\n\t\t\t---------------------------------------------------------\t\t\t\n");
    GOTOXY(24, 12); printf("|\n");
    GOTOXY(80, 12); printf("|\n");
    xsmMARGIN
    printf("\t\t\t|\t\t      PATIENT  MANAGER    \t\t|");
    
    for(int i = 13; i < 42; ++i){
        GOTOXY(24, i); printf("|\n");
    }

    for(int i = 13; i < 42; ++i){
        GOTOXY(80, i); printf("|\n");
    }


    printf("\t\t\t---------------------------------------------------------\t\t\t\n");
}
