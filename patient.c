#include "header.h"

typedef struct patient{
    int ID;
    char firstName[20];
    char lastName[20];
    int age;
    char contactNumber[10];
    char email[30];
    } patient;

void patientInsertCreds(char name[], int age, ull passwd){
    FILE * patientFile = fopen("./files/patientLog.csv", "w");
    if(patientFile == NULL){
        printf("\t\t\t Service currently unavailable !!\n");
        printf("\t\t\t Please press and key to return.....\n");
        getch();
        return;
    } else {
        
    }
    fclose(patientFile);
}