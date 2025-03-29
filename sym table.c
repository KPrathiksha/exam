#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char id[50];
    char type[20];
    int address;
} Symbol;

Symbol table[MAX];
int count = 0;

void insert(char *id, char *type, int address) {
    strcpy(table[count].id, id);
    strcpy(table[count].type, type);
    table[count].address = address;
    count++;
    printf("Inserted: %s, %s, %d\n", id, type, address);
}

void display() {
    printf("\nSymbol Table:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %s %d\n", table[i].id, table[i].type, table[i].address);
    }
}

int main() {
    int choice, address;
    char id[50], type[20];
    
    while (1) {
        printf("\n1. Insert\n2. Display\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("ID: "); scanf("%s", id);
            printf("Type: "); scanf("%s", type);
            printf("Address: "); scanf("%d", &address);
            insert(id, type, address);
        } else if (choice == 2) {
            display();
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
