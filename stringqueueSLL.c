#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[100];
    struct node* next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(char* value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->data, value);  // Copy string into the node's data
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued '%s' to queue\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct node* temp = front;
    printf("Dequeued '%s' from queue\n", temp->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = front;
    printf("QUEUE: ");
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
        printf("\nMENU\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();  // To clear the newline character from the buffer

        switch (choice) {
            case 1:
                printf("Enter string to enqueue: ");
                fgets(value, 100, stdin);
                value[strcspn(value, "\n")] = 0; // Remove the newline character
                enqueue(value);
                break;
            case 2:
                dequeue();
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