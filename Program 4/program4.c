#include <stdio.h>
#define SIZE 5  // Size of the queue

// Global variables
int queue[SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() {
    return (rear == SIZE - 1);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Function to insert an element in the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1) front = 0;  // Set front if inserting the first element
        rear++;
        queue[rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

// Function to delete an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to delete.\n");
    } else {
        printf("%d deleted from the queue.\n", queue[front]);
        front++;
        if (front > rear) {
            // Reset the queue if all elements are deleted
            front = rear = -1;
        }
    }
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
