#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n;
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    getchar();
    
    char grammar[MAX][MAX];
    printf("Enter the productions (e.g., A->ab|ac):\n");
    for (int i = 0; i < n; i++) {
        fgets(grammar[i], MAX, stdin);
        grammar[i][strcspn(grammar[i], "\n")] = '\0';
    }
    
    printf("\nGrammar after eliminating left factoring:\n");
    for (int i = 0; i < n; i++) {
        char *arrow = strstr(grammar[i], "->");
        if (!arrow) continue;
        
        *arrow = '\0';
        char *nonTerminal = grammar[i];
        char *productions = arrow + 2;
        
        char *first = strtok(productions, "|");
        char prefix[MAX];
        strcpy(prefix, first);
        
        for (char *token = strtok(NULL, "|"); token; token = strtok(NULL, "|")) {
            int j = 0;
            while (prefix[j] && token[j] && prefix[j] == token[j]) j++;
            prefix[j] = '\0';
        }
        
        if (strlen(prefix) > 0) {
            printf("%s -> %s%s'\n", nonTerminal, prefix, nonTerminal);
            printf("%s' -> ", nonTerminal);
            int firstPrinted = 0;
            for (char *token = strtok(productions, "|"); token; token = strtok(NULL, "|")) {
                if (strncmp(token, prefix, strlen(prefix)) == 0) {
                    if (firstPrinted) printf(" | ");
                    printf("%s", token + strlen(prefix));
                    firstPrinted = 1;
                }
            }
            printf(" | ε\n");
        } else {
            printf("%s -> %s\n", nonTerminal, productions);
        }
    }
    
    return 0;
}
