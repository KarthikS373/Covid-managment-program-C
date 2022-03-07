#include "header.h"

typedef struct patient{
    ull ID;
    char firstName[20];
    char lastName[20];
    int age;
    char contactNumber[10];
    char email[30];
    char passwd[20];
    } patient;

// Insert data into patientLog.csv
void _patientInsertCreds(ull ID, char name[], int age, char contact[], char email[]){
    FILE * patientFile = fopen("./files/patientLog.csv", "w");
    if(patientFile == NULL){
        printf("\t\t\t Service currently unavailable !!\n");
        printf("\t\t\t Please press and key to return.....\n");
        getch();
    } else {
        fprintf(patientFile, "%llu, %s, %d, %s, %s\n", ID, name, age, contact, email );
        xsmMARGIN
        printf("Patient added successfully");
    }
    fclose(patientFile);
    return;
}

// Store patient ID and password 
void _patientStorePasswd(ull ID, char passwd[]){
    FILE * passwdFile = fopen("./files/patientPasswd.csv", "w");
    if(passwdFile == NULL){
        printf("\t\t\t Error saving passwrd retry again !!\n");
        printf("\t\t\t Please press and key to return.....\n");
        getch();
    } else {
        fprintf(passwdFile, "%llu, %s", ID, passwd );
        xsmMARGIN
        printf("password added successfully");
    }
    fclose(passwdFile);
    return;
    
}

ull _generateID(){
    ull ID = (rand() % (900000)) + 100000;
    return ID;
}


void patientReg(){
    system("cls");
    patient p;
    srand((unsigned) time(0));
    p.ID =  _generateID();
    char name[40];
    short validate = 0;
    // Name validation
    do{
        printf("\n\t\t\t Enter the patient name: \n");
        scanf("%s %s", &p.firstName, &p.lastName);
        strcpy(name, p.firstName);
        strcat(name, " ");
        strcat(name, p.lastName);
        if( strlen(name) <= 0 ){
            printf("\nEnter a valid name !!");
            validate = 0;
        } else {
            validate = 1;
        }
    } while(!validate);


    // Age validation
    do{
        printf("\n\t\t\t Enter the patient age: \n");
        scanf("%d", &p.age);
        if( p.age <= 0 ) {
            printf("\nEnter a valid age !!");
            validate = 0;
        } else {
            validate = 1;
        }
    } while (!validate);

    // Contact number
    do{
        printf("\n\t\t\t Enter the patient contact number: \n");
        scanf("%s", &p.contactNumber);
        if( strlen(p.contactNumber) != 10 ) {
            printf("\nEnter a valid phone number !!");
            validate = 0;
        } else {
            validate = 1;
        }
    } while (!validate);

    // Email
    do{
        printf("\n\t\t\t Enter the patient email: \n");
        scanf("%s", &p.email);
        int ct = 0;
        for (int i = 0; i < strlen(p.email); i++) 
            if ( p.email[i] == '@' )
                ct++;
        if(ct == 0) {
            printf("Please enter a valid email !!");
            validate = 0;
        } else {
            validate = 1;
        }
    } while (!validate);

    // Password
    do{
        printf("\n\t\t\t Enter the password for your account: \n");
        scanf("%s", &p.passwd);
        if(strlen(p.passwd) <= 3){
            printf("\nEnter a valid password with 4+ characters !!!");
            validate = 0;
            continue;
        }
        char cpasswd[20];
        printf("\n\t\t\t Confirm password: \n");
        scanf("%s", &cpasswd);

        short tempVerif = 0;
        for(int j = 0; j < strlen(p.passwd); j++)
            if(p.passwd[j] == cpasswd[j])
                tempVerif = 1;

        if ( !tempVerif ){
            printf("Please check ur password !!");
            validate = 0;
        } else {
            validate = 1;
        }
    } while (!validate);

    if(validate){
        _patientInsertCreds(p.ID, name, p.age, p.contactNumber, p.email);
        _patientStorePasswd(p.ID, p.passwd);
        MARGIN
    } 
}