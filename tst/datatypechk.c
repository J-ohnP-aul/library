#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    int num;
    char input[50];
    printf("Enter an integer: ");
    fgets(input,sizeof(input),stdin);

    //remove newline ch
    input[strcspn(input, "\n")] = 0;

    //check if char are digits;
    int i;
    for(i=0; input[i] != '\0'; i++)
    {
        if(!isdigit(input[i])){
            printf("Erro the input is not an integer!!\n");
            return 1;//exit with error code
        }
    }

    // convert string to int
    num = atoi(input);
    printf("you entered: %d\n",(num * 2));
    
    return 0;
}