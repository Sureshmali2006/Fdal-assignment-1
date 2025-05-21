#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[100];
    struct node* next;
};

struct node* top = NULL;

void push(char* value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->data, value); // Copy the string into the node's data
    newNode->next = top;
    top = newNode;
    printf("Pushed '%s' onto stack\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct node* temp = top;
    printf("Popped '%s' from stack\n", temp->data);
    top = top->next;
    free(temp);
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node* temp = top;
    printf("STACK: ");
    while (temp != NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    char value[100];

    do {
        printf("\nMENU\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();  // To clear the newline character from the input buffer

        switch (choice) {
            case 1:
                printf("Enter string to push: ");
                fgets(value, 100, stdin);
                value[strcspn(value, "\n")] = 0; // Remove the newline character
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}