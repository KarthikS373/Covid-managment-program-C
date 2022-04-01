#include "header.h"

typedef struct patient{
    ull ID;
    char firstName[20];
    char lastName[20];
    int age;
    char gender;
    char contactNumber[11];
    char email[30];
    char passwd[20];
    } patient;


// ********************************************** PATIENT FILE INSERTING **********************************************
// Insert data into patientLog.csv
void _patientInsertCreds(ull ID, char name[], int age, char contact[], char email[], char gender){
    FILE * patientFile = fopen("./files/patientLog.csv", "a");
    if(patientFile == NULL){
        printf("\t\t\t Service currently unavailable !!\n");
        printf("\t\t\t Please press and key to return.....\n");
        getch();
    } else {
        fprintf(patientFile, "%llu, %s, %d, %s, %s, %c\n", ID, name, age, contact, email, gender );
        xsmMARGIN
        printf("\t\t\tPatient added successfully");
    }
    fclose(patientFile);
    return;
}

// Store patient ID and password 
void _patientStorePasswd(ull ID, char passwd[]){
    FILE * passwdFile = fopen("./files/patientPasswd.csv", "a");
    if(passwdFile == NULL){
        printf("\t\t\t Error saving passwrd retry again !!\n");
        printf("\t\t\t Please press and key to return.....\n");
        getch();
    } else {
        fprintf(passwdFile, "%llu, %s\n", ID, passwd );
        xsmMARGIN
        printf("\t\t\tpassword added successfully");
    }
    fclose(passwdFile);
    return;
    
}


//  ******************************* PATIENT REGISTRATION *******************************
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
        printf("\n\t\t\t Enter the patient name: ");
        scanf("%s %s", &p.firstName, &p.lastName);
        strcpy(name, p.firstName);
        strcat(name, " ");
        strcat(name, p.lastName);
        if( strlen(name) <= 0 ){
            printf("\n\t\t\tEnter a valid name !!");
            xsmMARGIN
            validate = 0;
        } else {
            validate = 1;
        }
    } while(!validate);


    // Age validation
    do{
        printf("\n\t\t\t Enter the patient age: ");
        scanf("%d", &p.age);
        if( p.age <= 0 ) {
            printf("\n\t\t\tEnter a valid age !!");
            xsmMARGIN
            validate = 0;
        } else {
            validate = 1;
        }
    } while (!validate);


    // Gender validation
    do{
        printf("\n\t\t\t Enter the patient Gender (M/F/O): ");
        FLUSH
        scanf("%c", &p.gender);
        p.gender = toupper(p.gender);
        if( p.gender != 'M' && p.gender != 'F' && p.gender != 'O') {
            printf("\n\t\t\tEnter a valid Gender !!");
            xsmMARGIN
            validate = 0;
        } else {
            validate = 1;
        }
    } while (!validate);

    // Contact number
    do{
        printf("\n\t\t\t Enter the patient contact number: ");
        scanf("%s", &p.contactNumber);
        if( strlen(p.contactNumber) != 10 ) {
            printf("\n\t\t\tEnter a valid phone number !!");
            xsmMARGIN
            validate = 0;
        } else {
            validate = 1;
        }
    } while (!validate);

    // Email
    do{
        printf("\n\t\t\t Enter the patient email: ");
        scanf("%s", &p.email);
        int ct = 0;
        for (int i = 0; i < strlen(p.email); i++) 
            if ( p.email[i] == '@' )
                ct++;
        if(ct == 0) {
            printf("\t\t\tPlease enter a valid email !!");
            xsmMARGIN
            validate = 0;
        } else {
            validate = 1;
        }
    } while (!validate);

    // Password
    do{
        printf("\n\t\t\t Enter the password for your account: ");
        scanf("%s", &p.passwd);
        if(strlen(p.passwd) <= 4){
            printf("\n\t\t\tEnter a valid password with 4+ characters !!!");
            validate = 0;
            xsmMARGIN
            continue;
        }
        char cpasswd[20];
        printf("\n\t\t\t Confirm password: ");
        scanf("%s", &cpasswd);

        short tempVerif = 0;
        int len = ( strlen(p.passwd) >= strlen(cpasswd)) ? strlen(p.passwd) : strlen(cpasswd);
        for(int j = 0; j < strlen(p.passwd); j++)
            if(!strcmp(p.passwd, cpasswd))
                tempVerif = 1;

        if ( !tempVerif ){
            printf("\t\t\tPlease check ur password !!");
            validate = 0;
            xsmMARGIN
        } else {
            validate = 1;
        }
    } while (!validate);

    if(validate){
        _patientInsertCreds(p.ID, name, p.age, p.contactNumber, p.email, p.gender);
        _patientStorePasswd(p.ID, p.passwd);
        printf("\n\t\t\t\t Your Patient ID is %d", p.ID);
        MARGIN
    } 
}




// **************************************** PATIENT FILE RETRIVING **************************************************

char * _authorizeLogin(int ID){
    FILE * passwdFile = fopen("./files/patientPasswd.csv", "r");
    if(!passwdFile){
        printf("\t\t\t Services Currently unavailable Sorry for the inconvinience!... !!\n");
        printf("\t\t\t Please press and key to return.....\n");
        getch();
    } else {
        char line[200];
        int row = 0;
        int column = 0;

        while (fgets(line, sizeof(line), passwdFile)) {
            char *value;
            value = strtok(line, ",");
            if(atoi(value) == ID){
                value = strtok(NULL, ",");
                return value;
            }
        }
        
    }
    char error[] = "error__";
    char * errorCode = error;
    fclose(passwdFile);
    return errorCode;
}

patient __CurrentPatient;
char __currentPatientName[100];
void _fetchPatientDetails(int ID){
    FILE * patientFile = fopen("./files/patientLog.csv", "r");
    if(!patientFile){
        printf("\t\t\t Services Currently unavailable Sorry for the inconvinience!... !!\n");
        printf("\t\t\t Please press and key to return.....\n");
        getch();
    } else {
        char line[200];
        int row = 0;
        int column = 0;

        while (fgets(line, sizeof(line), patientFile)) {
            char *value;
            value = strtok(line, ",");
            if(atoi(value) == ID){
                __CurrentPatient.ID = ID;
                value = strtok(NULL, ",");
                strcpy(__currentPatientName, value);
                value = strtok(NULL, ",");
                __CurrentPatient.age = atoi(value);
                value = strtok(NULL, ",");
                char number[10];
                strcpy(number, value);
                strcpy(__CurrentPatient.contactNumber, number);

                printf("%s num", __CurrentPatient.contactNumber);
                value = strtok(NULL, ",");
                strcpy(__CurrentPatient.email, value);
                value = strtok(NULL, ",");
                if (strcmp(value, "M"))
                    __CurrentPatient.gender = 'M';
                else if (strcmp(value, "F"))
                    __CurrentPatient.gender = 'F';
                else 
                    __CurrentPatient.gender = 'O';
            }
        }
        
    }
}



void _patientAddIssue(int ID, char _patientIssue[]){
    FILE * patientFile = fopen("./files/patientSummary.csv", "a");
    if(patientFile == NULL){
        printf("\t\t\t Service currently unavailable !!\n");
        printf("\t\t\t Please press and key to return.....\n");
        getch();
    } else {
        time_t current_time;
        time(&current_time);
        fprintf(patientFile, "%d, %s", ID, _patientIssue);
        fprintf(patientFile, ", %s", ctime(&current_time));
        xsmMARGIN
        printf("\t\t\tIssue added successfully");
    }
    fclose(patientFile);
    return;
}

char __summary[(int)1e5] = "";
void _patientSummary(int ID){
    FILE * patientFile = fopen("./files/patientSummary.csv", "r");
    if(patientFile == NULL){
        printf("\t\t\t Service currently unavailable !!\n");
        printf("\t\t\t Please press and key to return.....\n");
        getch();
    } else {
        char line[200];
        int row = 0;
        int column = 0;
        while (fgets(line, sizeof(line), patientFile)) {
            char *value;
            value = strtok(line, ",");
            if(atoi(value) == ID){
                value = strtok(NULL, ",");
                char temp[1000] = "";
                strcat(temp, value);
                value = strtok(NULL, ",");
                strcat(__summary, value);
                strcat(__summary, " :\t");
                strcat(__summary, temp);
                strcat(__summary, "\n");
            }
        }
    }
    fclose(patientFile);
    return;
}



// **************************************** PATIENT LOGIN *****************************************************

void patientLogDetails(){
    system("cls");
    patientTitleBar();
    smMARGIN
    char Identify[10];
    FLUSH
    printf("\t\t\t Enter the patient ID : ");
    gets(Identify);
    int ID  = atoi(Identify);
    char * passwd = _authorizeLogin(ID); // returns the password as a string pointer
    char pass[100];
    strcpy(pass, passwd);
    if(!strcmp(passwd, "error__")){
        xsmMARGIN
        printf("\t\t\t ID not found.....\n");
        printf("\t\t\t Please press and key to return.....\n");
        FLUSH
        getch();
        return;
    } else{
        _fetchPatientDetails(ID);
        _patientDetails(__CurrentPatient.ID, __currentPatientName, __CurrentPatient.age, __CurrentPatient.contactNumber, __CurrentPatient.email, __CurrentPatient.gender); 
    }
    MARGIN
}

void patientIssue(){
    system("cls");
    patientTitleBar();
    smMARGIN
    char Identify[10];
    FLUSH
    printf("\t\t\t Enter the patient ID : ");
    gets(Identify);
    int ID  = atoi(Identify);
    char * passwd = _authorizeLogin(ID); // returns the password as a string pointer
    char pass[100];
    if(!strcmp(passwd, "error__")){
        xsmMARGIN
        printf("\t\t\t ID not found.....\n");
        printf("\t\t\t Please press and key to return.....\n");
        FLUSH
        getch();
        return;
    } else{
        char _patientIssue[1000];
        FLUSH
        xsmMARGIN
        printf("\t\t\t Enter the Issue : ");
        FLUSH
        fgets(_patientIssue, 250, stdin);
        _patientIssue[strcspn(_patientIssue, "\n")] = 0;
        _patientAddIssue(ID, _patientIssue);
    }
    MARGIN
}
void patientSummary(){
    system("cls");
    patientTitleBar();
    smMARGIN
    char Identify[10];
    printf("\t\t\t Enter the patient ID : ");
    FLUSH
    gets(Identify);
    int ID  = atoi(Identify);
    char * passwd = _authorizeLogin(ID); // returns the password as a string pointer
    char pass[100];
    if(!strcmp(passwd, "error__")){
        xsmMARGIN
        printf("\t\t\t ID not found.....\n");
        printf("\t\t\t Please press and key to return.....\n");
        FLUSH
        getch();
        return;
    } else{
        FLUSH
        _patientSummary(ID);
        _patientSummaryGraphics(ID, __summary);
        strcpy(__summary, "");
    }
    MARGIN
}

void patientLog(){
    patientTitleBar();
    smMARGIN
    int choice = patientLogMenu();
    switch(choice){
        case 1 : 
            patientLogDetails();
            break;
        case 2 : 
            patientIssue();
            break;
        case 3 : 
            patientSummary();
            break;
        default : 
            printf("INVALID");
    }
}