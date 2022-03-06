#include "header.h"
#include "utils.c"

void welcomeScreen(){
    margin();
    printf("\t\t\t-----------------------------------------------------------------\n");

    printf("\t\t\t|\t                                          \t\t|\n");
    printf("\t\t\t|\t       Welcome to Covid Managment Program \t\t|\n");
    printf("\t\t\t|\t                                          \t\t|\n");
    printf("\t\t\t-----------------------------------------------------------------\n");
    printf("\n");

    printf("\t\t\t\tPress any key to continue.........");
    getch();
    system("cls");

}       
                  