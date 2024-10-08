#include <stdio.h>
#include <stdlib.h>

#define INIT_CAPACITY 2 // Initial stack capacity

// Function to double the size of the stack when it's full
void doubleStackSize(int **stack, int *capacity) {
    *capacity *= 2;                                         // Double the capacity
    *stack = (int*)realloc(*stack, (*capacity) * sizeof(int)); // Reallocate memory for the array
    printf("Stack size doubled to %d\n", *capacity);
}

// Function to check if the stack is empty
int isEmpty(int top) {
    return top == -1;
}

// Function to push an element onto the stack
void push(int **stack, int *top, int *capacity, int data) {
    // If the stack is full, double its size
    if (*top == *capacity - 1) {
        doubleStackSize(stack, capacity);
    }
    (*stack)[++(*top)] = data; // Increment top and push the data
    printf("%d pushed to stack\n", data);
}

// Function to pop an element from the stack
int pop(int *stack, int *top) {
    if (isEmpty(*top)) {
        printf("Stack underflow. Cannot pop.\n");
        return -1; // Return -1 if stack is empty
    }
    return stack[(*top)--]; // Pop the top element and decrement top
}

// Function to peek at the top element of the stack
int peek(int *stack, int top) {
    if (isEmpty(top)) {
        printf("Stack is empty. No top element.\n");
        return -1; // Return -1 if stack is empty
    }
    return stack[top];
}

// Function to display the stack elements
void display(int *stack, int top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Menu-driven program to test stack operations
int main() {
    int *stack = (int*)malloc(INIT_CAPACITY * sizeof(int)); // Dynamically allocate memory for the stack array
    int capacity = INIT_CAPACITY;  // Set initial capacity
    int top = -1;                  // Initialize top as -1 (stack is empty)

    int choice, value;

    // Menu for stack operations
    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, &top, &capacity, value);
                break;
            case 2:
                value = pop(stack, &top);
                if (value != -1) {
                    printf("%d popped from stack\n", value);
                }
                break;
            case 3:
                value = peek(stack, top);
                if (value != -1) {
                    printf("Top element is %d\n", value);
                }
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                free(stack); // Free dynamically allocated memory for the stack
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
