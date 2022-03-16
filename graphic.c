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
    GOTOXY(45, 16)
    printf("PATIENT  MANAGER");
    GOTOXY(40, 17)
    printf("-------------------------");
    GOTOXY(40, 20)
    printf("Name       :  %s");
    GOTOXY(40, 22)
    printf("Patient ID :  %d");
    GOTOXY(40, 24)
    printf("Gender     :  %c");
    GOTOXY(40, 26)
    printf("Contact    :  %s");
    GOTOXY(40, 28)
    printf("Email      :  %s");
    
    for(int i = 13; i < 42; ++i){
        GOTOXY(24, i); printf("|\n");
    }

    for(int i = 13; i < 42; ++i){
        GOTOXY(80, i); printf("|\n");
    }


    printf("\t\t\t---------------------------------------------------------\t\t\t\n");
}
