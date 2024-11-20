/* Program - AVL Tree Implementation */
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the AVL tree
struct AVL {
    int key;                 // The key or data stored in the node
    struct AVL *left;        // Pointer to the left child
    struct AVL *right;       // Pointer to the right child
    int height;              // Height of the node
};
typedef struct AVL node;     // Alias `node` for the AVL structure

// Function to get the height of a node
int getHeight(node *n) {
    if (n == NULL)           // If the node is NULL, height is 0
        return 0;
    return n->height;        // Otherwise, return the height of the node
}

// Function to create a new AVL tree node
node *createNode(int key) {
    node* n = (node *) malloc(sizeof(node)); // Allocate memory for the new node
    n->key = key;           // Assign the key value
    n->left = NULL;         // Initialize left child to NULL
    n->right = NULL;        // Initialize right child to NULL
    n->height = 1;          // New node has height 1 (leaf node)
    return n;
}

// Utility function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to calculate the balance factor of a node
int getBalanceFactor(node *n) {
    if (n == NULL)          // If the node is NULL, balance factor is 0
        return 0;
    return getHeight(n->left) - getHeight(n->right); // Difference in height of left and right subtrees
}

// Function to perform a left rotation
node* leftRotate(node* A) {
    node* B = A->left;       // B becomes the new root
    node* RB = B->right;     // Right child of B becomes the left child of A

    B->right = A;            // Rotate: A becomes the right child of B
    A->left = RB;            // Update A's left child to RB

    // Update heights
    A->height = max(getHeight(A->right), getHeight(A->left)) + 1;
    B->height = max(getHeight(B->right), getHeight(B->left)) + 1;

    return B;                // Return the new root (B)
}

// Function to perform a right rotation
node* rightRotate(node* A) {
    node* B = A->right;      // B becomes the new root
    node* LB = B->left;      // Left child of B becomes the right child of A

    B->left = A;             // Rotate: A becomes the left child of B
    A->right = LB;           // Update A's right child to LB

    // Update heights
    A->height = max(getHeight(A->right), getHeight(A->left)) + 1;
    B->height = max(getHeight(B->right), getHeight(B->left)) + 1;

    return B;                // Return the new root (B)
}

// Function to perform a left-right rotation
node* leftrightRotate(node* A) {
    node* B = A->left;       // B is the left child of A
    node* C = B->right;      // C is the right child of B

    // Perform rotations to balance the tree
    C->left = B;
    C->right = A;
    B->right = NULL;         // Nullify unnecessary connections
    A->left = NULL;

    // Update heights
    A->height = max(getHeight(A->right), getHeight(A->left)) + 1;
    B->height = max(getHeight(B->right), getHeight(B->left)) + 1;
    C->height = max(getHeight(C->right), getHeight(C->left)) + 1;

    return C;                // Return the new root (C)
}

// Function to perform a right-left rotation
node* rightleftRotate(node* A) {
    node* B = A->right;      // B is the right child of A
    node* C = B->left;       // C is the left child of B

    // Perform rotations to balance the tree
    C->left = A;
    C->right = B;
    A->right = NULL;         // Nullify unnecessary connections
    B->left = NULL;

    // Update heights
    A->height = max(getHeight(A->right), getHeight(A->left)) + 1;
    B->height = max(getHeight(B->right), getHeight(B->left)) + 1;
    C->height = max(getHeight(C->right), getHeight(C->left)) + 1;

    return C;                // Return the new root (C)
}

// Function to insert a key into the AVL tree
node *insert(node* n, int key) {
    int bf;                  // Balance factor
    if (n == NULL)           // If the node is NULL, create a new node
        return createNode(key);

    if (key < n->key)        // Insert in the left subtree if the key is smaller
        n->left = insert(n->left, key);
    else if (key > n->key)   // Insert in the right subtree if the key is larger
        n->right = insert(n->right, key);

    // Update the height of the current node
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));

    // Get the balance factor to check if the node became unbalanced
    bf = getBalanceFactor(n);

    // Perform rotations based on the type of imbalance
    if (bf > 1 && key < n->left->key) // Left-Left case
        return leftRotate(n);
    if (bf < -1 && key > n->right->key) // Right-Right case
        return rightRotate(n);
    if (bf > 1 && key > n->left->key) // Left-Right case
        return leftrightRotate(n);
    if (bf < -1 && key < n->right->key) // Right-Left case
        return rightleftRotate(n);

    return n;                // Return the (possibly updated) root
}

// Function to print the tree in 2D style
void printtree(node *root, int space, int n) {
    int i;
    if (root == NULL)        // If the tree is empty, do nothing
        return;

    space += n;              // Increase the space for indentation

    printtree(root->right, space, n); // Print the right subtree

    printf("\n");
    for (i = n; i < space; i++) // Print spaces for indentation
        printf(" ");
    printf("(%d)\n", root->key); // Print the key of the current node

    printtree(root->left, space, n); // Print the left subtree
}

// Main function to drive the program
int main() {
    node *root = NULL;       // Initialize the AVL tree root as NULL
    int n, i, key;

    // Input: Number of nodes
    printf("Enter the number of nodes\n");
    scanf("%d", &n);

    // Input: Keys for the nodes
    for (i = 0; i < n; i++) {
        printf("Enter the key\n");
        scanf("%d", &key);
        root = insert(root, key); // Insert each key into the AVL tree
    }

    // Print the tree in 2D style
    printtree(root, 0, n);
    return 0; // End of program
}
