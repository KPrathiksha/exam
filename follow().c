#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

int main() {
    char production[MAX][MAX];
    char follow[MAX][MAX];
    int numProductions;
    
    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);
    getchar();
    
    printf("Enter the productions (e for epsilon):\n");
    for (int i = 0; i < numProductions; i++) {
        fgets(production[i], MAX, stdin);
        production[i][strcspn(production[i], "\n")] = '\0';
    }
    
    for (int i = 0; i < numProductions; i++) {
        printf("FOLLOW(%c) = { ", production[i][0]);
        
        if (i == 0) {
            strncat(follow[i], "$", 1); 
        }
        
        for (int j = 0; j < numProductions; j++) {
            for (int k = 2; production[j][k] != '\0'; k++) {
                if (production[j][k] == production[i][0]) {
                    if (production[j][k + 1] != '\0') {
                        strncat(follow[i], &production[j][k + 1], 1);
                    } else {
                        strncat(follow[i], follow[j], MAX - strlen(follow[i]) - 1);
                    }
                }
            }
        }
        
        printf("%s }\n", follow[i]);
    }
    
    return 0;
}
