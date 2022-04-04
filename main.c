#include "header.h"
#include "welcome.c"


int main(){
    system("cls");
    welcomeScreen(); // welcome.c

    TOP:
    titleBar();  // title.c
    int choice = homeMenu(); // menu.c

    system("cls");
    switch(choice){
        case 1: 
            patientReg();
            break;
        case 2:
            patientLog();
            break;
        case 3:
            covidStats();
            break;
        case 4:
            select_doc();
            break;
        case 5:
            health();
            break;
        case 6:
            goto EXIT;
            break;
        default:
            printf("Invalid entry!");
    }

    xsmMARGIN
    sleep(2);
    goto TOP;

    EXIT:
      printf("\t\t\t\t-----------------------------------------------------------------\n");
      printf("\t\t\t\t|\t                                                  \t|\n");
      printf("\t\t\t\t|\tThank You for using our Health Checker! Stay Safe!\t|\n");
      printf("\t\t\t\t|\t                                                  \t|\n");
      printf("\t\t\t\t-----------------------------------------------------------------\n");
      printf("\n");
    return 0;
}