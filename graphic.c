#include "header.h"

void _patientDetails(int ID, char name[], int age, char number[], char email[], char gender){
    system("cls");
    MARGIN
    printf("\n\t\t\t---------------------------------------------------------\t\t\t\n");
    GOTOXY(24, 12); printf("|\n");
    GOTOXY(80, 12); printf("|\n");
    xsmMARGIN
    GOTOXY(45, 16)
    printf("PATIENT  MANAGER");
    GOTOXY(37, 17)
    printf("-----------------------------");
    GOTOXY(37, 20)
    printf("Name       :  %s", name);
    GOTOXY(37, 22)
    printf("Patient ID :  %d", ID);
    GOTOXY(37, 24)
    printf("Age        :  %d", age);
    GOTOXY(37, 26)
    printf("Gender     :  %c", gender);
    GOTOXY(37, 28)
    char contactNum[11];
    for(int i = 0; i < 10; ++i)
        contactNum[i] = number[i];
    printf("Contact    :  %s", contactNum);
    GOTOXY(37, 30)
    printf("Email      :  %s", email);
    
    for(int i = 13; i < 42; ++i){
        GOTOXY(24, i); printf("|\n");
    }

    for(int i = 13; i < 42; ++i){
        GOTOXY(80, i); printf("|\n");
    }


    printf("\t\t\t---------------------------------------------------------\t\t\t\n");
   
}




void _patientSummaryGraphics(int ID, char summary[]){
    system("cls");
    MARGIN
    printf("\n\t\t\t---------------------------------------------------------\t\t\t\n");
    GOTOXY(24, 12); printf("|\n");
    GOTOXY(80, 12); printf("|\n");
    xsmMARGIN
    GOTOXY(45, 16)
    printf("PATIENT  SUMMARY");
    GOTOXY(37, 17)
    printf("-----------------------------");
    char *value;
    GOTOXY(37, 20)
    value = strtok(summary, "\n");
    printf("%s", value);
    GOTOXY(37, 21)
    value = strtok(NULL, "\n");
    printf("%s", value);

    GOTOXY(37, 23)
    value = strtok(NULL, "\n");
    if(value){
        printf("%s", value);
        GOTOXY(37, 24)
        value = strtok(NULL, "\n");
        printf("%s", value);
    }

    GOTOXY(37, 26)
    value = strtok(NULL, "\n");
    if(value){
        printf("%s", value);
        GOTOXY(37, 27)
        value = strtok(NULL, "\n");
        printf("%s", value);
    }

    GOTOXY(37, 29)
    value = strtok(NULL, "\n");
    if(value){
        printf("%s", value);
        GOTOXY(37, 30)
        value = strtok(NULL, "\n");
        printf("%s", value);
    }

    GOTOXY(37, 32)
    value = strtok(NULL, "\n");
    if(value){
        printf("%s", value);
        GOTOXY(37, 33)
        value = strtok(NULL, "\n");
        printf("%s", value);
    }

    GOTOXY(37, 35)
    value = strtok(NULL, "\n");
    if(value){    
        printf("%s", value);
        GOTOXY(37, 36)
        value = strtok(NULL, "\n");
        printf("%s", value);
    }

    GOTOXY(37, 38)
    value = strtok(NULL, "\n");
    if(value){
        printf("%s", value);
        GOTOXY(37, 39)
        value = strtok(NULL, "\n");
        printf("%s", value);    
    }
    


    for(int i = 13; i < 42; ++i){
        GOTOXY(24, i); printf("|\n");
    }

    for(int i = 13; i < 42; ++i){
        GOTOXY(80, i); printf("|\n");
    }


    printf("\t\t\t---------------------------------------------------------\t\t\t\n");
}