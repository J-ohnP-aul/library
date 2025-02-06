#include<stdio.h>
#include<stdlib.h>
#include<ctype.h> 
#include<string.h>


struct student
{
    char fullName[50];
    char email[50];
    char regNo[50];
    char password[50];
    char userName[50];
};
struct book
{
	char name[20];
	char auther[20];
	int id;
};
struct book books[] = {};

struct book math = {"calculus1", "Dr_Omari", 111};
struct book soen = {"SystemAnalysisandD", "DrC.O.D", 112};
struct book phys = {"AppliedElectronics", "Dr_Edwin", 213};
struct book comp = {"compArchitecture", "Md_Arika", 100};
struct book soen1 = {"structProg","Benjamin", 102};
struct book comp1 = {"OperatingSystems", "modeWaOS", 113};

// MAIN SITES
void studentsite();
void loginsite();

char generateUserName(char email[50],char username[50]);
void displaylogin();


void displayMenu();
void displayLoginMenu();
int inptDta(void);
int inptDta1(void);//int comp and error staf
int inptDta2(void);
void clear_input_buffer();
char takeInput(char ch[50]);
void login();
void readLibRules();


int main()
{   
    // studentsite();
    loginsite();
    
    return 0;

}
void loginsite()
{
    system("clear");
    int opt;
    FILE *fpa,*fpr;
    struct student user;

    do
    {   
        displaylogin();
        opt = inptDta2();
        /* code */
        switch(opt){
            case 1:{
                char password2[50];
                system("clear");
                printf("\n\t\t>>>>>LOGIN DETAILS <<<<<\n\n");
                printf("\t\tEnter your full name:        ");
                takeInput(user.fullName);
                printf("\n\t\tEnter your email adress:   ");
                takeInput(user.email);
                printf ("\n\t\tEnter your RegNo:         ");
                takeInput(user.regNo);
                printf("\n\t\tEnter your password:       ");
                takeInput(user.password);
                system("clear");
                printf("\n\t\tRe-enter your password for confimation: ");
                takeInput(password2);
                // system("clear");

                if(!strcmp(user.password, password2)){//strcmp returns 0-false if the str are equal
                    generateUserName(user.email,user.userName);
                    printf("\n\t\tpassword matched, welcome:\t%s\n\n",user.userName);
                    
                    fpa = fopen("database.dat", "a");
                    printf("\n\t\t###>>You are sucsessfully loged in to the system");
                    fwrite(&user,sizeof(struct student),1,fpa);
                    if(fwrite != 0) printf("\n\n\t\tUser registration succes, your user-name is %s\n",user.userName);
                    else printf("SORRY SOMETHING WENT WRONG!!");
                    // if(fpa == NULL){
                    //     printf("\n\t\tError ocured in eading database");
                    // }
                    // else{
                    // }
                }else{
                    printf("\n\n\t\t><><><!!!password did not match!!");
                }
                fclose(fpa);
                break;
            }case 2:{
                int userFound = 0;
                system("clear");
                char usernamecmp[50],passwordcmp[50];
                struct student std1;
                printf("\n\t\tEnter your user name:\t");
                takeInput(usernamecmp);
                printf("\n\t\tEnter your password :\t");
                takeInput(passwordcmp);

                fpr = fopen("database.dat","r");

                while(fread(&std1,sizeof(struct student),1,fpr)){
                    if(!strcmp(std1.userName,usernamecmp)){
                        if(!strcmp(std1.password,passwordcmp)){
                            system("clear");
                            printf("\n\t\t\t\tWelcome back %s",std1.userName);
                            printf("\n\t|Full name:\t%s",std1.fullName);
                            printf("\n\t|Email    :\t%s",std1.email);
                            printf("\n\t|username :\t%s",std1.userName);
                            printf("\n\t|Reg numb :\t%s",std1.regNo);
                            printf("\n\t|_________________|\n\n\n");

                            studentsite();

                        }else{
                            printf("\n\t\tINVALID PASSWORD!!");
                        }
                        userFound = 1;
                    }
                }
                if(!userFound){
                    printf("\n\t\tUSER NOT REGISTERD KINDLY REGISTER!!\n\n");
                }
                fclose(fpr);
                break;
            }case 3:{
                system("clear");
                printf("\n\t _________________");
                printf("\n\t| BYE BYE FELLA :}|");
                printf("\n\t|_________________|");
                break;// return 0;
            }default:
                system("clear");
                printf("\n\n\t\tINVALID INPUT !!");

        }
    } while (opt != 3);   

}
void studentsite()
{
    struct book books[] = {math, soen, phys, comp, soen1, comp1};
    system("clear");
   	int opt;
    do{
		displayMenu();
		opt = inptDta1();
        switch(opt){
            case 1:{
                system("clear");
                // printf("\e[1;1H\e[2J");//ANSI escape seq
                for(int i=0; i<sizeof(books)/sizeof(books[0]); i++)
                {
                    printf("\n\t\tbook %d\n",i+1);
                    printf("\t\t-------------------------------*\n");
                    printf("\t\t|book name: %s\n",books[i].name);
                    printf("\t\t|auther: %s \n",books[i].auther);
                    printf("\t\t|book id: %d\n",books[i].id);
                    printf("\t\t-------------------------------*\n\n");
                }
                
                break;
            }case 2:{
                system("clear");
            	printf("\n\tEnter the book id..eg soen105 id-105\n");
                int idSearch =  inptDta();
                int found = 0;
				for(int i=0; i<sizeof(books)/sizeof(books[0]); i++)
				{
					if(idSearch == books[i].id)
					{
						printf("Available!!");
						printf("\nbook %d",i+1);
                        printf("\t\t-------------------------------*\n");
                        printf("\t\t|book name: %s\n",books[i].name);
                        printf("\t\t|auther: %s \n",books[i].auther);
                        printf("\t\t|book id: %d\n",books[i].id);
                        printf("\t\t-------------------------------*\n\n");
                        found = 1;
                        break;
					}if(!found){
                    system("clear");
                    printf("\n\t\tthe book not found\n");
                }
				}
                break;
            }case 3:
				readLibRules();
                break;
            case 4:
                login();          
                break;
            case 5:
                system("clear");
                printf("\n\t\tBYE BYE !!!");
                // exit(1);
                break;
            default:
                system("clear");
                printf("\n\t\tINVALID INPUT");
        }		
	}while(opt != 5);
}
char takeInput(char ch[50]){
    fgets(ch,50,stdin);
    ch[strlen(ch)-1] = 0;
    return ch[50];
}
int inptDta(void){
    int num;
    char input[50];
    while(1){
        printf("\n\n\tenter a digit:___ :\t");
        fgets(input,sizeof(input),stdin);
        //remove newline ch
        input[strcspn(input, "\n")] = 0;
        //digit confirmer
        int i;
        for(i=0; input[i] != '\0'; i++)
        {
            if(!isdigit(input[i])){
                printf("\n\t\t!!INVALID INPUT ONLY DIGITS ALLOWED!!!");
                // clear_input_buffer();
                break;
            }
        }
        if(input[i] == '\0'){
        // convert string to int
        num = atoi(input);    
        return num;
        }
    }
}
int inptDta1(void){
    int num;
    char input[50];
    while(1){
        printf("\n\n\tenter a digit:___ :\t");
        fgets(input,sizeof(input),stdin);
        //remove newline ch
        input[strcspn(input, "\n")] = 0;
        //digit confirmer
        int i;
        for(i=0; input[i] != '\0'; i++)
        {
            if(!isdigit(input[i])){
                printf("\n\t\t!!INVALID INPUT ONLY DIGITS ALLOWED!!!");
                // clear_input_buffer();
                system("clear");
                displayMenu();
                break;
            }
        }
        if(input[i] == '\0'){
        // convert string to int
        num = atoi(input);    
        return num;
        }
    }
}
int inptDta2(void){
    int num;
    char input[50];
    while(1){
        printf("\n\n\tenter a digit:___ :\t");
        fgets(input,sizeof(input),stdin);
        //remove newline ch
        input[strcspn(input, "\n")] = 0;
        //digit confirmer
        int i;
        for(i=0; input[i] != '\0'; i++)
        {
            if(!isdigit(input[i])){
                printf("\n\t\t!!INVALID INPUT ONLY DIGITS ALLOWED!!!:");
                system("clear");
                displaylogin();
                // clear_input_buffer();
                break;
            }
        }
        if(input[i] == '\0'){
        // convert string to int
        num = atoi(input);    
        return num;
        }
    }
}
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// >>display menus
void displayMenu()
{  
	printf("\n\t********** Welcome to library plartfom  ********");
	printf("\n\t1.Display books");
	printf("\n\t2.Search books");
	printf("\n\t3.read Library rules");
	printf("\n\t4.Mark attendance");
	// printf("\n\t5.Return book");
	printf("\n\t5.Exit");
}
void displayLoginMenu(){
    printf("\n\t***welcome to attndance rec***\n");
    printf("\n1\tsign in at the entrance\n");
    printf("2\tshow sign in members\n");
    printf("3\tExit");
}

void login()
{   
    system("clear");
    int opt;

    char lname[50];
    char fName[50];
    char number[50];

    FILE *pWrite;
    FILE *pRead;    
    do{
        displayLoginMenu();
        opt = inptDta();
        switch (opt)
        {
        case 1:{
            //adding user data to database
            system("clear");
            printf("\nEnter first name: ");
            takeInput(fName);
            printf("\nEnter last name: ");
            takeInput(lname);
            printf("\nEnter phone number: ");
            takeInput(number);

            pWrite = fopen("/home/noble/Desktop/library/database/user_data.txt", "a");
            
            if (pWrite != NULL){
                fprintf(pWrite, "%s %s %s\n", fName,lname,number);
                system("clear");
                printf("\n\tThank you %s you are signed in to the system!!\n\n",lname);
            }else{
                // goto ErroHandler;
                printf("unknown Error");
            }
            fclose(pWrite);
            break;
        }case 2:{
            //print the login user databases
            system("clear");

            pRead = fopen("/home/noble/Desktop/library/database/user_data.txt", "r");
            
            if(pRead != NULL){
                int i = 1;
                printf("\n>>>\nfIRST.N\t\tLAST.N\t\tPHONE.No\n");
                while(!feof(pRead)){
                    i++;
                    fscanf(pRead, "%s %s %s", fName, lname, number);
                    
                    if(!feof(pRead)){
                        printf("\t\n %d._%s\t\t%s\t\t%s",i, fName, lname, number);
                    }
                    printf("\n");
                }
            }
            else{
                // goto ErroHandler;
                printf("unknown Error");
            }
            fclose(pRead);
            break;
        }case 3:
            system("clear");
            break;
        default:
            system("clear");
            printf("\n\tINVALID CATEGORY!!\n\n");
        }

    }while (opt != 3);
    

}
void readLibRules(){
    system("clear");


    printf(">>>\n>>\n>Penlties are available!!\n\n");
	FILE *pF = fopen("/home/noble/Desktop/c-files/poem.txt", "r");
    char buffer[255];

    if(pF == NULL){
        printf("unable to open the file\n");
    }else{
        while(fgets(buffer, 255, pF) != NULL)        
        {
            printf("%s", buffer);   
        }
    }

    
    
    fclose(pF);
    printf("\n\n\n*>>>Kindly abide regards johnpol<<\n");
}

//LOGIN MODULE
char generateUserName(char email[50],char username[50]){
    for(int i=0;i<strlen(email);i++){
        if(email[i] == '@') break;
        else username[i] = email[i];
    }
}
void displaylogin(){
    printf("\n\t\t===========>>WELCOME TO THE SCHOOL LIBRARY system<<<============\n");
    printf("\t\t\t1.Sign up\n");
    printf("\t\t\t2.Login\n");
    printf("\t\t\t3.Exit .");
}