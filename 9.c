#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;   // top of stack

// Push operation
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;   // new node points to previous top
    top = newNode;         // update top
    printf("%d pushed to stack\n", value);
}

// Pop operation
void pop() {
    if (top == NULL) {
        printf("Stack is empty! Cannot pop.\n");
        return;
    }

    struct Node* temp = top;
    printf("%d popped from stack\n", top->data);
    top = top->next;
    free(temp);
}

// Peek operation
void peek() {
    if (top == NULL) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

// Display operation
void display() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    pop();
    peek();

    display();

    return 0;
}
