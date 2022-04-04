#include "header.h"

void health()
{


    MARGIN


    printf("\t\t\t-----------------------------------------------------------------\n");
    printf("\t\t\t|\t                                          \t\t|\n");
    printf("\t\t\t|\t       Welcome to Health Checker!         \t\t|\n");
    printf("\t\t\t|\t                                          \t\t|\n");
    printf("\t\t\t-----------------------------------------------------------------\n");
    printf("\n");


    smMARGIN


    printf("\t\t\t\t        You ready to begin!? [y/n] : ");
    char ans;
    FLUSH
    scanf(" %c",&ans);
    xsmMARGIN


    if(ans=='y' || ans=='Y')
    {
     printf("\t\t\t\t            Let's begin!!!            \t\t\n");
     system("cls");
     MARGIN
     printf("\t\t\t\t     Please give correct answers.....      \t\t\n");
     printf("\t\t\t\tAccurate answers help us - help you better!\t\t\n");
     smMARGIN
     printf("\t\t\t\tPress any key to continue.........");
     getch();
     system("cls");
     float n;


     MARGIN

     a:
       {
        n=0;
        char answer1, answer2, answer3, answer4, answer5, answer6, answer7;
        printf("\t\t\t\tAre you having Sore Throat or Cough or Fever? [y/n] : "); //Set A (Question 1)
        FLUSH
        scanf(" %c",&answer1);
        if(answer1=='y' || answer1=='Y') //Incrementing 'n' if the user enters 'y' or 'Y' to calculate risk percentage
        n++;
        else if(answer1!='y' && answer1!='n' && answer1!='Y' && answer1!='N') //Invalid Entry
        {
           printf("\t\t\t\tInvalid entry!\n");
           printf("\t\t\t\tPlease enter 'y' for Yes or 'n' for No.\n");
           printf("\t\t\t\tPress any key to continue.........");
           getch();
           system("cls");
           goto a;
        }


        printf("\n");


        printf("\t\t\t\tAre you having Hearing Impairment or Loss of senses of Smell and Taste or Body Ache? [y/n] : "); //Set A (Question 2)
        FLUSH
        scanf(" %c",&answer2);
        if(answer2=='y' || answer2=='Y') //Incrementing 'n' if the user enters 'y' or 'Y' to calculate risk percentage
        n++;
        else if(answer2!='y' && answer2!='n' && answer2!='Y' && answer2!='N') //Invalid Entry
        {
           printf("\t\t\t\tInvalid entry!\n");
           printf("\t\t\t\tPlease enter 'y' for Yes or 'n' for No.\n");
           printf("\t\t\t\tPress any key to continue.........");
           getch();
           system("cls");
           goto a;
        }


        printf("\n");


        printf("\t\t\t\tAre you having Chest Congestion or Runny Nose or Difficulty in Breathing? [y/n] : "); //Set A (Question 3)
        FLUSH
        scanf(" %c",&answer3);
        if(answer3=='y' || answer3=='Y') //Incrementing 'n' if the user enters 'y' or 'Y' to calculate risk percentage
        n++;
        else if(answer3='y' && answer3!='n' && answer3!='Y' && answer3!='N') //Invalid Entry
        {
           printf("\t\t\t\tInvalid entry!\n");
           printf("\t\t\t\tPlease enter 'y' for Yes or 'n' for No.\n");
           printf("\t\t\t\tPress any key to continue.........");
           getch();
           system("cls");
           goto a;
        }


        printf("\n\n\n\n");


        printf("\t\t\t\tDo you have Diabetes or Kidney Disorder? [y/n] : "); //Set B (Question 1)
        FLUSH
        scanf(" %c",&answer4);
        if(answer4=='y' || answer4=='Y') //Incrementing 'n' if the user enters 'y' or 'Y' to calculate risk percentage
        n++;
        else if(answer4!='y' && answer4!='n' && answer4!='Y' && answer4!='N') //Invalid Entry
        {
           printf("\t\t\t\tInvalid entry!\n");
           printf("\t\t\t\tPlease enter 'y' for Yes or 'n' for No.\n");
           printf("\t\t\t\tPress any key to continue.........");
           getch();
           system("cls");
           goto a;
        }


        printf("\n");


        printf("\t\t\t\tDo you have Asthma or Lung Diseases? [y/n] : "); //Set B (Question 2)
        FLUSH
        scanf(" %c",&answer5);
        if(answer5=='y' || answer5=='Y') //Incrementing 'n' if the user enters 'y' or 'Y' to calculate risk percentage
        n++;
        else if(answer5!='y' && answer5!='n' && answer5!='Y' && answer5!='N') //Invalid Entry
        {
           printf("\t\t\t\tInvalid entry!\n");
           printf("\t\t\t\tPlease enter 'y' for Yes or 'n' for No.\n");
           printf("\t\t\t\tPress any key to continue.........");
           getch();
           system("cls");
           goto a;
        }


        printf("\n");


        printf("\t\t\t\tDo you have Hypertension or Heart Diseases? [y/n] : "); //Set B (Question 3)
        FLUSH
        scanf(" %c",&answer6);
        if(answer6=='y' || answer6=='Y') //Incrementing 'n' if the user enters 'y' or 'Y' to calculate risk percentage
        n++;
        else if(answer6!='y' && answer6!='n' && answer6!='Y' && answer6!='N') //Invalid Entry
        {
           printf("\t\t\t\tInvalid entry!\n");
           printf("\t\t\t\tPlease enter 'y' for Yes or 'n' for No.\n");
           printf("\t\t\t\tPress any key to continue.........");
           getch();
           system("cls");
           goto a;
        }


        printf("\n\n\n\n");


        printf("\t\t\t\tHave you travelled anywhere in the past 14 days? [y/n] : "); //Set C (Question 1)
        FLUSH
        scanf(" %c",&answer7);
        printf("\n");
        if(answer7=='y' || answer7=='Y') //Incrementing 'n' if the user enters 'y' or 'Y' to calculate risk percentage
        {
         n++;
         b:
         char travel;
         printf("\t\t\t\tDomestic or Abroad? (Enter 'd' for Domestic and 'a' for Abroad) : ");
         FLUSH
         scanf(" %c",&travel);
         if (travel!='d' && travel!='a' && travel!='D' && travel!='A')
         {
           printf("\t\t\t\tInvalid entry!\n");
           printf("\t\t\t\tPlease enter 'd' for Domestic Travel or 'A' for International Travel!\n");
           printf("\t\t\t\t");
           goto b;
         }
         char place_name[MAX_LIMIT];
         printf("\t\t\t\tEnter the name of the place : ");
         FLUSH
         fgets(place_name, MAX_LIMIT, stdin);
        }
        else if(answer7!='y' && answer7!='n' && answer7!='Y' && answer7!='N') //Invalid Entry
        {
           printf("\t\t\t\tInvalid entry!\n");
           printf("\t\t\t\tPlease enter 'y' for Yes or 'n' for No.\n");
           printf("\t\t\t\tPress any key to continue.........");
           getch();
           system("cls");
           goto a;
        }
      }
      xsmMARGIN
      float risk_per = (n/7)*100; //calculation of risk percentage
      printf("\t\t\t\tYour risk percentage is %.2f%%.\n", risk_per);
      if (risk_per>75 && risk_per<=100) //High Risks
      {
      printf("\t\t\t\tAccording to our Health Checker, you are at ");
      printf("\033[0;31m");
      printf("HIGH RISK");
      printf("\033[0m");
      printf(" of being affceted by the Corona Virus!\n");
      }
      else if (risk_per<=75 && risk_per>50) //Moderate Risks
      {
      printf("\t\t\t\tAccording to our Health Checker, you are have ");
      printf("\033[0;31m");
      printf("MODERATE");
      printf("\033[0m");
      printf(" chances of being affceted by the Corona Virus!\n");
      }
      else if (risk_per<=50 && risk_per>25) //Low Risks
      {
      printf("\t\t\t\tAccording to our Health Checker, you are at ");
      printf("\033[0;32m");
      printf("LOW RISK");
      printf("\033[0m");
      printf(" of being affceted by the Corona Virus!\n");
      }
      else if (risk_per<=25 && risk_per>0) //At least Risks
      {
      printf("\t\t\t\tAccording to our Health Checker, you are at ");
      printf("\033[0;32m");
      printf("LEAST RISK");
      printf("\033[0m");
      printf(" of being affceted by the Corona Virus!\n");
      }
      printf("\t\t\t\t-----------------------------------------------------------------\n");
      printf("\t\t\t\t|\t                                                  \t|\n");
      printf("\t\t\t\t|\tThank You for using our Health Checker! Stay Safe!\t|\n");
      printf("\t\t\t\t|\t                                                  \t|\n");
      printf("\t\t\t\t-----------------------------------------------------------------\n");
      printf("\n");
   }
   else
   {
    printf("\t\t\t-----------------------------------------------------------------\n");
    printf("\t\t\t|\t                                          \t\t|\n");
    printf("\t\t\t|\t          Thank You! Stay Safe!           \t\t|\n");
    printf("\t\t\t|\t                                          \t\t|\n");
    printf("\t\t\t-----------------------------------------------------------------\n");
    printf("\n");
   }
}