#include "header.h"
#include "welcome.c"
#include "title.c"


int main(){
    system("cls");
    welcomeScreen(); // welcome.c
    patientTitleBar(); // title.c
    titleBar();  // title.c

    return 0;
}
