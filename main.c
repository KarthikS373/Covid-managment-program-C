#include "header.h"
#include "welcome.c"


int main(){
    system("cls");
    welcomeScreen(); // welcome.c

    titleBar();  // title.c
    int choice = homeMenu();

    switch(choice){
        case 1:
            patientReg();
        default:
            printf("INVALID OPTION");
    }

    return 0;
}
