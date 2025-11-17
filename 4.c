#include <stdio.h>
#define MAX 10

int main() {

    int stack[MAX];
    int top = -1;
    int choice, item;

    while (1) {

        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:   // PUSH
                if (top == MAX - 1) {
                    printf("Stack Overflow\n");
                } else {
                    printf("Enter item to push: ");
                    scanf("%d", &item);
                    top++;
                    stack[top] = item;
                    printf("Inserted %d\n", item);
                }
                break;

            case 2:   // POP
                if (top == -1) {
                    printf("Stack Underflow\n");
                } else {
                    printf("Deleted %d\n", stack[top]);
                    top--;
                }
                break;

            case 3:   // DISPLAY
                if (top == -1) {
                    printf("Stack empty\n");
                } else {
                    printf("Stack elements: ");
                    for (int i = top; i >= 0; i--) {
                        printf("%d ", stack[i]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
