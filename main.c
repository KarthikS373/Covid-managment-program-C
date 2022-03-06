#include "header.h"
#include "welcome.c"
#include "title.c"
#include "menu.c"


int main(){
    system("cls");
    welcomeScreen(); // welcome.c

    titleBar();  // title.c
    int choice = homeMenu();

    return 0;
}
