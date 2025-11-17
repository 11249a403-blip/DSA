#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtEnd(int newData){
    struct Node newNode = (struct Node)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void printList(){
    struct Node *node = head;
    if(node == NULL){
        printf("List empty\n");
        return;
    }
    while(node != NULL){
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void deleteAtBeginning(){
    if(head == NULL) return;
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd(){
    if(head == NULL) return;
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head, *prev = NULL;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void deleteAtMiddle(int pos){
    if(head == NULL) return;
    if(pos == 1){
        deleteAtBeginning();
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    for(int i = 1; i < pos && temp != NULL; i++){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

int main(){
    int n, value, choice, pos;

    printf("How many nodes do you want to insert: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);
        insertAtEnd(value);
    }

    printf("List after inserting nodes:\n");
    printList();

    while(1){
        printf("\nChoose what to delete:\n");
        printf("1: Delete at beginning\n");
        printf("2: Delete at middle (position)\n");
        printf("3: Delete at end\n");
        printf("4: Display list\n");
        printf("5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                deleteAtBeginning();
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtMiddle(pos);
                break;

            case 3:
                deleteAtEnd();
                break;

            case 4:
                printList();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
