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
        char line[200];
        int row = 0;
        int column = 0;

        while (fgets(line, sizeof(line), statsfile)) {
            char *value;
            value = strtok(line, ",");
            while (value != NULL)
            {
                printf("%-52s", value);
                value = strtok(NULL, ",");
            }
            printf("\n");
            
            // if(atoi(value) == ID){
                // value = strtok(NULL, ",");
            //     return value;
            // }
        }
        
    }

}