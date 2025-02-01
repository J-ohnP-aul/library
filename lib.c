#include<stdio.h>
#include<stdlib.h>
#include<ctype.h> 
#include<string.h>


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

void studentsite();
void displayMenu();
void displayLoginMenu();
int inptDta(void);//int comp and error staf
char takeInput(char ch[50]);
void login();
void readLibRules();


int main()
{   
    studentsite();
    
    return 0;

}
void studentsite()
{
    struct book books[] = {math, soen, phys, comp, soen1, comp1};
    system("clear");
   	int opt;
    do{
		displayMenu();
		opt = inptDta();
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
                exit(1);
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
    printf("\n\n\tenter a digit:___ :\t");
    fgets(input,sizeof(input),stdin);

    //remove newline ch
    input[strcspn(input, "\n")] = 0;

    //check if char are digits;
    int i;
    for(i=0; input[i] != '\0'; i++)
    {
        if(!isdigit(input[i])){
            printf("\n\t\t!!INVALID INPUT ");
            exit(1);
        }
    }

    // convert string to int
    num = atoi(input);    
    return num;
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
