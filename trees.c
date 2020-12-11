#include <stdio.h>
#include "tree.h"

// FUNCTION DEFINITIONS
node * convert(node * root);
void convertRecursive(node * current, node ** lastNode);
void printList(node * head);

// Don't change the main function
int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        printf("Not enough arguments\n");
        return -1;
    }

    node * root = create_tree(argv[1]);
    root = convert(root);
    printList(root);
    deleteList(root);
}

// Converts a tree to a doubly linked list
node * convert(node * root)
{
    // YOUR CODE HERE
    node* lastnode = NULL;
    convertRecursive(root, &lastnode);
    return *lastnode;
}

// Recursive helper function for converting a tree to a doubly linked list
void convertRecursive(node * current, node ** lastNode)
{   //lastNode -> node* -> node
    //originally: lastNode -> Null -> ?
    //YOUR CODE HERE
    if (current == NULL) return; //no tree at all
    static node* prev = NULL; //previously visited node is NULL
                              //static so that it is accessible in all recursive calls
                              //this will be modified once start creating dll
    convertRecursive(current->left,lastNode);
    if (prev == NULL){ //this will be true only for one instance, which is when the first leftmost leaf node is reached
                       //when this condition is reached, dll then begins to be created
        *lastNode = current; 
        *lastNode->left = NULL;
    }
    else{
        current->left = prev;   //this is making the left pointer of our current node points towards the previous node we created
        prev->right = current;  //our previous node's next point towards our current node
    }
    prev = current; //previously visited node is the one we currently on
    
    convertRecursive(current->right, lastNode);
    
}


// Given a doubly linked list prints out the list from left to right
// then from right to left (ensures all left and right pointers are correct)
void printList(node * head)
{
    node * previous;
    printf("Left to right traversal: \n");
    while (head != NULL)
    {
        printf("%d ", head->value);
        previous = head;
        head = head->right;
    }
    printf("\nRight to left traversal: \n");
    head = previous;
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->left;
    }
    printf("\n");
}