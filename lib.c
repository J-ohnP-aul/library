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

void displayMenu();
void login();
void readLibRules();
int searchBook();


int main()
{   
   	struct book books[] = {math, soen, phys, comp, soen1, comp1};
    system("clear");
   	int opt,idSearch;
    do{
		displayMenu();
		scanf("%d",&opt);
        if(opt == 1)
        {   system("clear");
            // printf("\e[1;1H\e[2J");//ANSI escape seq
            for(int i=0; i<sizeof(books)/sizeof(books[0]); i++)
            {
                printf("\t\tbook %d\n",i+1);
                printf("\t\t-------------------------------*\n");
                printf("\t\t|book name: %s\n",books[i].name);
                printf("\t\t|auther: %s \n",books[i].auther);
                printf("\t\t|book id: %d\n",books[i].id);
                printf("\t\t-------------------------------*\n\n");
            }
        }else if(opt == 2){
				idSearch =  searchBook();
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
					}else{
						continue;
					}
				}
        }else if(opt == 3){
				readLibRules();
        }else if(opt == 4){
                login();}           
        // }else if(opt == 6){
        //     printf("\n\t\tBYE BYE !!!");
        // }
        else{
            printf("\n\t\tINVALID INPUT ");
        }

		
	}while(opt != 5);

}

void displayMenu()
{   
    // system("clear");

	printf("\n\t********** Welcome to library plartfom  ********");
	printf("\n\t1.Display books");
	printf("\n\t2.Search books");
	printf("\n\t3.read Library rules");
	printf("\n\t4.confirm Registration");
	// printf("\n\t5.Return book");
	printf("\n\t5.Exit\n\n\tChoose the options:_ ");


}

int inptDta(void){
    int num;
    char input[50];
    printf("\n\t\tchoose an option:\t");
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
    // printf("you entered: %d\n",num);
    
    return num;
}
void login()
{   
    system("clear");
    int response;

    char lname[20] = {0};
    char fName[20] = {0};
    char number[20] = {0};

    FILE *pWrite;
    FILE *pRead;

    printf("\n\t***Registerd users***\n");
    printf("\n1\tRegister to be a member\n");
    printf("2\tconfirm Registration\n\n");
    printf("Select an option: ");   

    scanf("%d",&response);

    if(response == 1)
    {
        //adding to file
        printf("\nEnter first name: ");
        scanf("%s", fName);
        printf("\nEnter last name: ");
        scanf("%s", lname);
        printf("\nEnter phone number: ");
        scanf("%s", number);

        pWrite = fopen("/home/noble/Desktop/library/database/user_data.txt", "a");
        
        if (pWrite != NULL){
            fprintf(pWrite, "%s %s %s\n", fName,lname,number);
        }else{
            // goto ErroHandler;
            printf("unknown Error");
        }
        fclose(pWrite);
    }
    else if(response == 2){
        //print the log book
        pRead = fopen("/home/noble/Desktop/library/database/user_data.txt", "r");
        
        if(pRead != NULL){
            printf("\nfirst.N\tlast.N\tPhone.No\n");
            while(!feof(pRead)){
                fscanf(pRead, "%s %s %s", fName, lname, number);
                
                if(!feof(pRead)){
                    printf("\n%s\t%s\t%s", fName, lname, number);
                }
                printf("\n");
            }
        }
        else{
            // goto ErroHandler;
            printf("unknown Error");
        }
        fclose(pRead);
    }else{
        printf("\nInvalid selection\n");
    }
    // exit(EXIT_SUCCESS);//EXIT NORMALZ

    // ErroHandler:
    // // printf("unknown Error");
    //     perror("The following error occured");
    //     exit(EXIT_FAILURE); //exit prog with error
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
int searchBook()
{	
    system("clear");
	int id;
	printf("\nEnter the book id..eg soen105 id-105\nenter the id:_");
	scanf("%d",&id);
    system("clear");
	return id;
}