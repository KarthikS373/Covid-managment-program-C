#include "header.h"

void covidStats () {
   
    char city[30];
    int cases;
    int deaths;

    FILE * statsfile = fopen("./files/covidStats.csv", "r");
    if(!statsfile){
        printf("\t\t\t Services Currently unavailable Sorry for the inconvinience!... !!\n");
        printf("\t\t\t Please press any key to return.....\n");
        getch();
    } else {
        char line[50];
        int row = 0;
        int column = 0;
        printf("\t  -------------------------------------------------------------------------------------------\t\t\t\n");
        GOTOXY(52, 2)
        printf("COVID STATS");
        GOTOXY(37, 3)
        printf("----------------------------------------\n");

        GOTOXY(16, 4)
        printf("STATE");
        GOTOXY(16, 5)
        printf("-------");
        GOTOXY(53, 4)
        printf("ACTIVE");
        GOTOXY(53, 5)
        printf("--------");
        GOTOXY(89, 4)
        printf("DEATH");
        GOTOXY(89, 5)
        printf("-------");
        printf("\n\n");
        while (fgets(line, sizeof(line), statsfile)) {
            char *value;
            printf("\t\t");
            value = strtok(line, ",");
            while (value != NULL){
                printf("%-52s", value);
                value = strtok(NULL, ",");
                printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            }
            printf("\n");
        }
        for(int i = 1; i < 80; ++i){
            GOTOXY(10, i); printf("|\n");
        }

        for(int i = 1; i < 80; ++i){
            GOTOXY(100, i); printf("|\n");
        }

        printf("\t  -------------------------------------------------------------------------------------------\t\t\t\n");
    }

}