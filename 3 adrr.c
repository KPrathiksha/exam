#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int main() {
    char expr[MAX];
    char tempVar = 'T';
    int tCount = 1;
    
    printf("Enter an arithmetic expression: ");
    scanf("%s", expr);
    
    printf("Three Address Code:\n");
    
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            printf("T%d = %c %c %c\n", tCount, expr[i-1], expr[i], expr[i+1]);
            expr[i+1] = 'T';
            expr[i] = tCount + '0';
            tCount++;
        }
    }
    
    return 0;
}
