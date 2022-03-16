#include "header.h"

COORD c;
#define GOTOXY(x, y) c.X = x; c.Y = y; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);


void _patientDetails(int ID, char name[], int age, char number[], char email[], char gender){
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
    printf("Name       :  %s", name);
    GOTOXY(40, 22)
    printf("Patient ID :  %d", ID);
    GOTOXY(40, 24)
    printf("Age        :  %d", age);
    GOTOXY(40, 26)
    printf("Gender     :  %c", gender);
    GOTOXY(40, 28)
    char contactNum[11];
    for(int i = 0; i < 10; ++i)
        contactNum[i] = number[i];
    printf("Contact    :  %s", contactNum);
    GOTOXY(40, 30)
    printf("Email      :  %s", email);
    
    for(int i = 13; i < 42; ++i){
        GOTOXY(24, i); printf("|\n");
    }

    for(int i = 13; i < 42; ++i){
        GOTOXY(80, i); printf("|\n");
    }


    printf("\t\t\t---------------------------------------------------------\t\t\t\n");
   
}
