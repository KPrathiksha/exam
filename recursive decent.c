#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

void E();
void E_prime();
void T();
void T_prime();
void F();

void E() {
    T();
    E_prime();
}

void E_prime() {
    if (input[pos] == '+') {
        pos++;
        T();
        E_prime();
    }
}

void T() {
    F();
    T_prime();
}

void T_prime() {
    if (input[pos] == '*') {
        pos++;
        F();
        T_prime();
    }
}

void F() {
    if (input[pos] == 'i') {
        pos++;
    } else if (input[pos] == '(') {
        pos++;
        E();
        if (input[pos] == ')') {
            pos++;
        } else {
            printf("Error: Missing closing parenthesis\n");
        }
    } else {
        printf("Error: Invalid character\n");
    }
}

int main() {
    printf("Enter the string: ");
    scanf("%s", input);
    E();
    if (input[pos] == '\0') {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }
    return 0;
}
