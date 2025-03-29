#include <stdio.h>
#include <string.h>

int main() {
    char string[50];
    int flag = 0, count = 0;

    printf("The grammar is: S->aS, S->Sb, S->ab\n");
    printf("Enter the string to be checked:\n");
    
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';  // Remove newline from input

    if (string[0] == 'a') {
        flag = 0;
        for (count = 1; string[count - 1] != '\0'; count++) {
            if (string[count] == 'b') {
                flag = 1;
                continue;
            } else if ((flag == 1) && (string[count] == 'a')) {
                printf("The string does not belong to the specified grammar\n");
                break;
            } else if (string[count] == 'a') {
                continue;
            } else if ((flag == 1) && (string[count] == '\0')) {
                printf("String not accepted.....!!!!\n");
                break;
            } else {
                printf("String accepted\n");
                break;
            }
        }
    } else {
        printf("String not accepted.....!!!!\n");
    }

    return 0;
}
