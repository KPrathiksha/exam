#include <stdio.h>
#include <string.h>

#define MAX 100

int top = -1;
char stack[MAX], input[MAX];

int main() {
    int i = 0;
    printf("Enter the string: ");
    scanf("%s", input);
    strcat(input, "$\0");
    
    stack[++top] = '$';
    printf("STACK\tINPUT\tACTION\n");
    
    while (1) {
        for (int j = 0; j <= top; j++) printf("%c", stack[j]);
        printf("\t");
        for (int j = i; j < strlen(input); j++) printf("%c", input[j]);
        printf("\t");
        
        if (stack[top] == '$' && input[i] == '\0') {
            printf("Accepted\n");
            break;
        }
        
        if (input[i] == 'i') {
            stack[++top] = 'E';
            printf("Shift\n");
            i++;
        } else if (input[i] == '+' || input[i] == '*') {
            top--;
            stack[++top] = 'E';
            printf("Reduced: E->E%cE\n", input[i]);
            i++;
        } else if (input[i] == '(' || input[i] == ')') {
            top--;
            stack[++top] = 'E';
            printf("Reduced: E->(E)\n");
            i++;
        } else {
            printf("Error\n");
            break;
        }
    }
    return 0;
}
