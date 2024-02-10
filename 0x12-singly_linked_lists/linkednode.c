#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Print the linked list
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void insertAtBeginning(struct Node** head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void insertAtEnd(struct Node** head, int data) {
    struct Node *newNode = createNode(data); 
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *last = *head; 
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}
void deleteNode(struct Node** head, int key) {
    struct Node *temp = *head, *prev;

    // If the key is in the head node
    if (temp != NULL && temp->data == key) {
        *head = temp->next;  
        free(temp);             
        return;
    }

    // Search for the key and keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key wasn't found
    if (temp == NULL) return;

    // Unlink the node
    prev->next = temp->next;
    free(temp); 
}
int main() {
    struct Node *head = NULL;

    insertAtEnd(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtEnd(&head, 3);
    insertAtBeginning(&head, 4);

    printf("Linked list: ");
    printList(head); 

    deleteNode(&head, 3);

    printf("Linked list after deletion: ");
    printList(head);

    return 0;
}
