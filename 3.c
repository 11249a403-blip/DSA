#include <stdio.h>
#include <stdlib.h>

int TOP = -1, MAX;
char *STACK;

// Push function
void PUSH(char item) {
    if (TOP == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        TOP++;
        STACK[TOP] = item;
    }
}

// Pop function
char POP() {
    if (TOP == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        char item = STACK[TOP];
        TOP--;
        return item;
    }
}

// String reversal function
void stringReversal() {
    char *string = (char *) malloc(sizeof(char) * (MAX + 1));
    if (string == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the string (max %d characters): ", MAX);
    scanf("%s", string);

    // Push each character into stack
    for (int i = 0; i < MAX && string[i] != '\0'; i++) {
        PUSH(string[i]);
    }

    printf("Reversed string: ");
    while (TOP != -1) {
        printf("%c", POP());
    }

    printf("\n");
    free(string);
}

int main() {
    printf("Enter the size of char stack: ");
    scanf("%d", &MAX);

    STACK = (char *) malloc(sizeof(char) * MAX);
    if (STACK == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    stringReversal();

    free(STACK);
    return 0;
}
