#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
int main()
{
    int sum,cnumber;
    char cResponse = '\0';
    // char *pC;
    // pC = &cResponse;
    printf("\nPlease enter a digit: ");
    scanf("%c", &cResponse);
    if (isdigit(cResponse)){
        printf("\nThank you\n");
        // sum = cnumber*2;
    }
    else{
        printf("\nYou did not enter a digit\n");
    }
        
    sum = atoi(cResponse);
    printf("%d",sum);
    return 0;
}