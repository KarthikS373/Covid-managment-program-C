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
        printf("password added successfully");
    }
    fclose(passwdFile);
    return;
    
}

ull _generateID(){
    ull ID = (rand() % (900000)) + 100000;
    return ID;
}


int _validateForm(char name[], int age, char email[], char contact[], char passwd[], char cpasswd[]){
    if( strlen(name) <= 0 ){
        printf("Enter a valid name !!");
        return -1;
    } else if( age <= 0 ) {
        printf("Enter a valid age !!");
        return -2;
    } else if( strlen(contact) != 10 ){
        printf("Enter a phone number !!");
        return -3;
    } else if( passwd != cpasswd || strlen(passwd) <= 4){
        printf("Please check ur password !!");
        return -4;
    } else {
        int ct = 0;
        for (int i = 0; i < strlen(email); i++) 
            if ( email[i] == '@' )
                ct++;
        if(ct == 0){
            printf("Please enter a valid email !!");
            return -5;
        }
    }
    return 1;
}
    

void patientReg(){
    system("cls");
    patient p;
    srand((unsigned) time(0));
    p.ID =  _generateID();
    NAME:
    printf("\n\t\t\t Enter the patient name: \n");
    scanf("%s %s", &p.firstName, &p.lastName);
    AGE:
    printf("\n\t\t\t Enter the patient age: \n");
    scanf("%d", &p.age);
    CONTACT:
    printf("\n\t\t\t Enter the patient contact number: \n");
    scanf("%s", &p.contactNumber);
    EMAIL:
    printf("\n\t\t\t Enter the patient email: \n");
    scanf("%s", &p.email);
    char name[40];
    strcpy(name, p.firstName);
    strcat(name, " ");
    strcat(name, p.lastName);
    
    PASSWD:
    printf("\n\t\t\t Enter the password for your account: \n");
    scanf("%s", &p.passwd);
    char cpasswd[20];
    printf("\n\t\t\t Confirm password: \n");
    scanf("%s", &cpasswd);

    int validate = _validateForm(name, p.age, p.email, p.contactNumber, p.passwd, cpasswd);
    if(validate){
        _patientInsertCreds(p.ID, name, p.age, p.contactNumber, p.email);
        _patientStorePasswd(p.ID, p.passwd);
    } else {
        switch (validate) {
        case -1 :
            goto NAME;
            break;
        case -2 :
            goto AGE;
            break;
        case -3 :
            goto CONTACT;
            break;
        case -4 :
            goto PASSWD;
            break;
        case -5 :
            goto EMAIL;
            break;
        
        default:
            break;
        }
    }
}