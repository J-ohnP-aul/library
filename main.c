#include<stdio.h>
#include<string.h>
char name[20];
char auther[20];
int id;

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
// void displayBook();
//void addBook(char name,char title, char auther, int id);
int searchBook();
void issueBook(int opt);
char returnBook(int opt);


int main()
{
	struct book books[] = {math, soen, phys, comp, soen1, comp1};
	int opt,idSearch;

	displayMenu();
	scanf("%d",&opt);
	
	switch(opt)
	{
		case 1:
			// system("clear");
			printf("\e[1;1H\e[2J");//ANSI escape seq
			// displayBook();
			for(int i=0; i<sizeof(books)/sizeof(books[0]); i++)
			{
	 			printf("\nbook %d",i+1);
 				printf("\n-------------------------------*\n|book name: %s\n|auther: %s \n|book id: %d\n-------------------------------*\n", books[i].name, books[i].auther, books[i].id);
 			}	
			break;
		case 2:
			idSearch =  searchBook();
			for(int i=0; i<sizeof(books)/sizeof(books[0]); i++)
			{
				if(idSearch == books[i].id)
				{
					printf("Available!!");
					printf("\nbook %d",i+1);
					printf("\n-------------------------------*\n|book name: %s\n|auther: %s \n|book id: %d\n-------------------------------*\n", books[i].name, books[i].auther, books[i].id);
				}else{
					continue;
				}
			}
			break;
						
	}
}
void displayMenu()
{

	printf("\n\t********** Welcome to library plartfom  ********");
	printf("\n\t1.Display books");
	printf("\n\t2.Search books");
	printf("\n\t3.Add a book");
	printf("\n\t4.issue Book");
	printf("\n\t5.Return book");
	printf("\n\t6.Exit\n\n\tChoose the options:_ ");


}
// void displayBook(books*)
// {
// 	for(int i=0; i<sizeof(books)/sizeof(books[0]); i++)
// 	{
// 		printf("book %d",i);
// 		printf("\n----------------\n|book name: %s\n|auther: %s\n|book id: %d\n----------------\n", books[i].name, books[i].auther, books[i].id);
// 	}
// }
// void addBook(char name, char title, char auther, int id)
// {	
// 	for(int i=0; i<(sizeof(books)/sizeof(books[0]))+1; i++){
// 		struct book newbook = 
// 	}
// 	// printf("\nEnter the name of the book\n");
// 	// scanf("%s",&name);
// 	// printf("\nEnter the tiile of the book: ");
// 	// scanf("%s",&title);
// 	// printf("Enter the authers name: ");
// 	// scanf("%s",&auther);
// 	// printf("Enter the book id: ");
// 	// scanf("%i",&id);
// 	// books[(sizeof(books)/sizeof(books[0]))+1] = name;

// 	// struct book name = {title,auther,id};
// }
int searchBook()
{	
	int id;
	printf("\nEnter the book id..eg soen105 id-105\nenter the id:_");
	scanf("%d",&id);
	return id;
}


