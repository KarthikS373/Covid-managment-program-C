#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;

    fp = fopen("covidStats.csv", "r");
    
    if (fp == NULL)
    {
        printf("Trouble reading file! \nProgram Terminating ... ");
        exit(0);
    }
    char line [500];
    while (fgets(line, 500, fp) != NULL)
    {
        printf("\n%s", line);
    }

}