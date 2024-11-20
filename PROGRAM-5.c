#include<stdio.h>
#include<stdlib.h>

// Define a structure for a singly linked list node
struct SLL {
    int usn;             // Store the USN of the student
    char name[20];       // Store the name of the student
    char mode[20];       // Store the mode (e.g., regular/distance) of the student
    struct SLL *next;    // Pointer to the next node in the list
};
typedef struct SLL node; // Create an alias `node` for struct SLL

node *start = NULL;       // Initialize the start pointer of the list to NULL

// Function prototypes
node *createNode();        // Function to create a new node
void insertEnd();          // Function to insert a node at the end of the list
void display();            // Function to display the contents of the list
void deleteKey();          // Function to delete a node by USN

// Main function
void main() {
    int i, n, choice, ele;

    // Infinite loop to repeatedly show menu options to the user
    while(1) {
        // Menu options
        printf("Enter your choice: ");
        printf("1: Insert\t2: Display\t3: Delete\t4: Add to branch\t5: Exit\n");
        scanf("%d", &choice);

        // Switch-case to handle user input
        switch(choice) {
            case 1: // Insert nodes at the end
            case 4: // Option 4 is treated the same as Insert
                printf("Enter number of students: \n");
                scanf("%d", &n);  // Number of students to add
                for(i = 0; i < n; i++) {
                    insertEnd();  // Add each student to the list
                }
                break;

            case 2: // Display the list
                display();
                break;

            case 3: // Delete a node based on USN
                deleteKey();
                break;

            case 5: // Exit the program
                exit(0);

            default: // Handle invalid input
                printf("Invalid choice");
        }
    }
}

// Function to create a new node and populate it with user input
node *createNode() {
    node *newnode;  // Pointer to the new node
    newnode = (node *) malloc(sizeof(node)); // Allocate memory for the node

    // Prompt the user to enter details for the new node
    printf("Enter USN | Name | Mode: ");
    scanf("%d %s %s", &newnode->usn, newnode->name, newnode->mode);

    newnode->next = NULL;  // Initialize the next pointer to NULL
    return newnode;        // Return the created node
}

// Function to display the list
void display() {
    node *temp = start;  // Temporary pointer to traverse the list

    if(start == NULL) {  // Check if the list is empty
        printf("List empty, cant display");
        return;
    }

    printf("Students in class are: \n");
    while(temp != NULL) {  // Traverse the list and print each node
        printf("USN: %d\tName: %s\tMode: %s\n", temp->usn, temp->name, temp->mode);
        temp = temp->next;
    }
}

// Function to insert a node at the end of the list
void insertEnd() {
    node *newnode, *temp;

    newnode = createNode(); // Create a new node

    if(start == NULL) {     // If the list is empty, set the start pointer
        start = newnode;
        return;
    }

    temp = start;           // Start from the beginning of the list
    while(temp->next != NULL) { // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newnode;   // Link the last node to the new node
}

// Function to delete a node based on a key (USN)
void deleteKey() {
    node *temp = start, *prev;
    int key;

    if(start == NULL) { // Check if the list is empty
        printf("\nList is empty, cant delete");
        return;
    }

    printf("Enter key: "); // Prompt the user to enter the USN to delete
    scanf("%d", &key);

    // Special case: if the node to be deleted is the first node
    if(start->usn == key) {
        start = start->next;      // Move the start pointer to the next node
        printf("deleted: %d", temp->usn);
        free(temp);               // Free the memory of the deleted node
        return;
    }

    // Traverse the list to find the node with the given USN
    while(temp != NULL && temp->usn != key) {
        prev = temp;              // Keep track of the previous node
        temp = temp->next;
    }

    if(temp == NULL) {            // If the key is not found
        printf("USN invalid");
        return;
    }

    // Update the links to exclude the node to be deleted
    prev->next = temp->next;
    printf("Deleted element is: %d", temp->usn);
    free(temp);                   // Free the memory of the deleted node
}
