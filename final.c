
#include <stdio.h>
#include <stdlib.h>

// Define node structure - written in class
typedef struct node {
    int data;
    struct node* next;
} node;

// Print entire list - written in class
void printList(node *head)
{
    node *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Insert node at beginning of the list - written in class
node *insertFront(node *head, int val)
{
    node *newNode = malloc(sizeof(node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    newNode->data = val;
    newNode->next = head;

    return newNode;
}

// Insert node at end of list - written in class
void insertBack(node *head, int val)
{
    if (head == NULL) {
        return;
    }

    node *newNode = malloc(sizeof(node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = val;
    newNode->next = NULL;

    node *current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Delete node at front of list - written in class
node *deleteFront(node *head)
{
    if (head == NULL) {
        return NULL;
    }

    node *current = head;
    head = head->next;

    printf("deleting %d\n", current->data);
    free(current);

    return head;
}

// Delete node at end of list - written in class
void deleteBack(node *head)
{
    if (head == NULL) {
        return;
    }

    if (head->next == NULL) {
        printf("deleting %d\n", head->data);
        free(head);
        return;
    }

    node *current = head;

    while (current->next->next != NULL) {
        current = current->next;
    }

    printf("deleting %d\n", current->next->data);
    free(current->next);

    current->next = NULL;
}

// Print the value of a node at a specified index in the list
void printIndex(node *head, int index)
{
    node *current = head;
    int count = 0;

    while (current != NULL) {
        if (count == index) {
            printf("The value located at index %d is %d\n",
                   index, current->data);
            return;
        }

        current = current->next;
        count++;
    }

    printf("Index %d is out of range.\n", index);
}

// Confirm or deny the existence of a value in the list
int isInList(node *head, int value)
{
    node *current = head;

    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }

        current = current->next;
    }

    return 0;
}

// Find the total number of nodes in the list
int sizeOfList(node *head)
{
    int size = 0;
    node *current = head;

    while (current != NULL) {
        size++;
        current = current->next;
    }

    return size;
}

// Find the smallest value in the list
int findMin(node *head)
{
    if (head == NULL) {
        return -1;
    }

    int min = head->data;
    node *current = head->next;

    while (current != NULL) {
        if (current->data < min) {
            min = current->data;
        }

        current = current->next;
    }

    return min;
}

// Find the largest value in the list
int findMax(node *head)
{
    if (head == NULL) {
        return -1;
    }

    int max = head->data;
    node *current = head->next;

    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
        }

        current = current->next;
    }

    return max;
}

int main()
{
    //--DO NOT CHANGE THIS SECTION--//

    // Create and initialize head pointer
    node *head = NULL;

    //~~~~Insert Nodes~~~~//

    head = insertFront(head, 42);
    head = insertFront(head, 37);
    head = insertFront(head, 235);
    head = insertFront(head, 877);
    head = insertFront(head, 88);
    head = insertFront(head, 401);
    head = insertFront(head, 323);
    head = insertFront(head, 461);
    head = insertFront(head, 784);
    head = insertFront(head, 358);

    insertBack(head, 12);
    insertBack(head, 713);
    insertBack(head, 209);
    insertBack(head, 466);
    insertBack(head, 55);
    insertBack(head, 10);
    insertBack(head, 515);
    insertBack(head, 2);
    insertBack(head, 75);
    insertBack(head, 199);

    // Print the list
    printf("--Initial List--\n");
    printList(head);

    //--END OF SECTION--//

    // Print the value located at index 6 (using printIndex())
    printIndex(head, 6);

    // Print the value located at index 10 (using printIndex())
    printIndex(head, 10);

    // Print the value located at index 16 (using printIndex())
    printIndex(head, 16);

    // Print the size of the linked list (using sizeOfList())
    printf("The list has %d values in it\n", sizeOfList(head));

    // Print the minimum value in the list (using findMin())
    printf("The smallest value in the list is %d\n", findMin(head));

    // Print the maximum value in the list (using findMax())
    printf("The Largest value in the list is %d\n", findMax(head));

    // Check if the value 89 is in the list (using isInList())
    int check1 = 89;

    printf("The value of %d is %s the list\n",
           check1, isInList(head, check1) ? "in" : "not in");

    // Check if the value of 55 is in the list (using isInList())
    int check2 = 55;

    printf("The value of %d is %s the list\n",
           check2, isInList(head, check2) ? "in" : "not in");

    return 0;
}
