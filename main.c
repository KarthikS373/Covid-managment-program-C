#include "header.h"
#include "welcome.c"


int main(){
    system("cls");
    welcomeScreen(); // welcome.c

    titleBar();  // title.c
    int choice = homeMenu(); // menu.c

    system("cls");
    switch(choice){
        case 1: 
            patientReg();
            break;
        default:
            printf("Invalid entry");
    }


    return 0;
}
