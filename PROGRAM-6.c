#include<stdio.h>
#include<stdlib.h>

// Define a structure for a Binary Search Tree (BST) node
struct BST {
    int data;            // Holds the data (key) of the node
    struct BST *left;    // Pointer to the left child
    struct BST *right;   // Pointer to the right child
};
typedef struct BST node; // Create an alias `node` for struct BST

// Function to insert a key into the BST
node *insert(node *root, int key) {
    if(root == NULL) {   // If the tree is empty or we reach a null spot
        root = (node *) malloc(sizeof(node)); // Allocate memory for a new node
        root->data = key;      // Assign the key to the new node
        root->left = root->right = NULL; // Initialize left and right children as NULL
        return root;           // Return the new node
    }
    if(key < root->data)       // If the key is less, insert in the left subtree
        root->left = insert(root->left, key);
    else                       // Otherwise, insert in the right subtree
        root->right = insert(root->right, key);

    return root;               // Return the unchanged root node
}

// Function for in-order traversal (left, root, right)
void inorder(node *root) {
    if(root != NULL) {
        inorder(root->left);         // Traverse the left subtree
        printf(" %d", root->data);   // Print the root's data
        inorder(root->right);        // Traverse the right subtree
    }
}

// Function for pre-order traversal (root, left, right)
void preorder(node *root) {
    if(root != NULL) {
        printf(" %d", root->data);   // Print the root's data
        preorder(root->left);        // Traverse the left subtree
        preorder(root->right);       // Traverse the right subtree
    }
}

// Function for post-order traversal (left, right, root)
void postorder(node *root) {
    if(root != NULL) {
        postorder(root->left);       // Traverse the left subtree
        postorder(root->right);      // Traverse the right subtree
        printf(" %d", root->data);   // Print the root's data
    }
}

// Function to search for a key in the BST
void search(node *root, int key) {
    if(root == NULL) {              // If the tree is empty or key is not found
        printf("Key not found");
        return;
    }
    if(root->data == key) {         // If the key matches the root's data
        printf("Key found");
        return;
    }
    if(key < root->data) {          // If the key is smaller, search in the left subtree
        search(root->left, key);
    } else {                        // Otherwise, search in the right subtree
        search(root->right, key);
    }
}

// Main function
void main() {
    int n, i, key, choice;
    node *root = NULL;             // Initialize the root of the BST as NULL

    // Input: Number of nodes to insert into the BST
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input: The elements (keys) to insert into the BST
    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);  // Insert each key into the BST
    }

    // Infinite loop for menu-driven operations
    while(1) {
        // Menu options
        printf("\nEnter choice: ");
        printf("\n1: Inorder\t2: Preorder\t3: Postorder\t4: Search\t5: Exit\n");
        scanf("%d", &choice);

        // Switch-case to handle the user's choice
        switch(choice) {
            case 1: // In-order traversal
                printf("\nInorder: ");
                inorder(root);
                break;

            case 2: // Pre-order traversal
                printf("\nPre-order: ");
                preorder(root);
                break;

            case 3: // Post-order traversal
                printf("\nPost-order: ");
                postorder(root);
                break;

            case 4: // Search for a key
                printf("Enter search element: ");
                scanf("%d", &key);
                search(root, key);
                break;

            case 5: // Exit the program
                exit(0);

            default: // Handle invalid input
                printf("Invalid choice!");
        }
    }
}
