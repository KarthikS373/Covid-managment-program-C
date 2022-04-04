#include "header.h"

int homeMenu(){
    printf("\t\t\t\t  Menu: \n");
    smMARGIN
    printf("\t\t\t\t      1. Patient Registration  \n\n");
    xsmMARGIN
    printf("\t\t\t\t      2. Patient Login  \n\n");
    xsmMARGIN
    printf("\t\t\t\t      3. Covid Stats  \n\n");
    xsmMARGIN
    printf("\t\t\t\t      4. Vaccinne helper  \n\n");
    xsmMARGIN
    printf("\t\t\t\t      5. Health Check  \n\n");
    xsmMARGIN
    printf("\t\t\t\t      ENTER MENU: ");
    FLUSH
    char choices[2];
    fgets(choices, 2, stdin);
    return (atoi(choices));
}


int patientLogMenu(){
    printf("\t\t\t\t  Menu: \n");
    smMARGIN
    printf("\t\t\t\t      1. Patient Details  \n\n");
    xsmMARGIN
    printf("\t\t\t\t      2. Add Issue  \n\n");
    xsmMARGIN
    printf("\t\t\t\t      3. Patient summary  \n\n");
    xsmMARGIN
    printf("\t\t\t\t      4. Exit  \n\n");
    xsmMARGIN
    printf("\t\t\t\t      ENTER MENU: ");
    FLUSH
    char choices[2];
    fgets(choices, 2, stdin);
    return (atoi(choices));
}