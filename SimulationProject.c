#include <stdio.h>
#include <string.h>

#define MAX 10   // Maximum 10 members

// Structure to store each person's data
typedef struct {
    int id;
    char name[50];
} Person;

Person stack[MAX];
int top = -1;

// Birth (Push)
void push(Person p) {
    if (top == MAX - 1) {
        printf("Population limit reached! Cannot add more members.\n");
        return;
    }

    stack[++top] = p;
    printf("Birth occurred! %s (ID: %d) added.\n", p.name, p.id);

    if (top == MAX - 1) {
        printf("Warning: Maximum limit (10 members) reached!\n");
    }
}

// Death (Pop)
void pop() {
    if (top == -1) {
        printf("Birth rate is low! No population left.\n");
        return;
    }

    printf("Person %s (ID: %d) has died and removed.\n",
           stack[top].name, stack[top].id);

    top--;

    if (top == -1) {
        printf("Birth rate is low! Population is empty now.\n");
    }
}

// Display all members
void display() {
    if (top == -1) {
        printf("No population! Birth rate is low.\n");
        return;
    }

    printf("\nCurrent Population (%d members):\n", top + 1);
    for (int i = top; i >= 0; i--) {
        printf("Name: %s | ID: %d\n", stack[i].name, stack[i].id);
    }
}

int main() {
    int choice;
    Person p;

    while (1) {
        printf("\n--- POPULATION MENU ---\n");
        printf("1. Birth (Push)\n");
        printf("2. Death (Pop)\n");
        printf("3. Display Population\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Person Name: ");
                scanf(" %[^\n]", p.name); // Read full string including spaces
                printf("Enter Person ID: ");
                scanf("%d", &p.id);
                push(p);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Input!\n");
        }
    }
}
