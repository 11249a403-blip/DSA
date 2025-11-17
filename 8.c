#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;  // <-- Added this pointer
};

// Insert at the end
void insertAtEnd(struct node** head, int newdata) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = newdata;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (*head == NULL) {
        *head = newnode;
        return;
    }

    struct node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;  // <-- set backward link
}

// Print list forward
void printList(struct node* node) {
    if (node == NULL) {
        printf("List empty.\n");
        return;
    }

    printf("Forward: ");
    struct node* last;
    while (node != NULL) {
        printf("%d <-> ", node->data);
        last = node;
        node = node->next;
    }
    printf("NULL\n");
}

// Print list backward
void printReverse(struct node* node) {
    if (node == NULL) {
        printf("List empty.\n");
        return;
    }

    // Move to the last node
    while (node->next != NULL)
        node = node->next;

    printf("Reverse: ");
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->prev;
    }
    printf("NULL\n");
}

// Delete at beginning
void deleteAtBeginning(struct node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    struct node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL)
        (*head)->prev = NULL; // <-- update prev pointer

    free(temp);
}

// Delete at end
void deleteAtEnd(struct node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = *head;

    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

// Delete at given position
void deleteAtPosition(struct node** head, int pos) {
    if (*head == NULL) {
        printf("List empty.\n");
        return;
    }

    struct node* temp = *head;

    if (pos == 1) {
        deleteAtBeginning(head);
        return;
    }

    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position not found.\n");
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}

int main() {
    struct node* head = NULL;
    int choice, val, pos;

    while (1) {
        printf("\n1. Insert at end\n2. Delete at beginning\n3. Delete at end\n4. Delete at position\n5. Display forward\n6. Display reverse\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            insertAtEnd(&head, val);
            break;
        case 2:
            deleteAtBeginning(&head);
            break;
        case 3:
            deleteAtEnd(&head);
            break;
        case 4:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(&head, pos);
            break;
        case 5:
            printList(head);
            break;
        case 6:
            printReverse(head);
            break;
        case 7:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
