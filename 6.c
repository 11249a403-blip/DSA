#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char item){
    if(top == MAX-1) return;
    stack[++top] = item;
}

char pop(){
    if(top == -1) return '\0';
    return stack[top--];
}

char peek(){
    if(top == -1) return '\0';
    return stack[top];
}

int precedence(char c){
    switch(c){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int isOperator(char c){
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}

void infix_to_postfix(char infix[],char postfix[]){
    int i=0,j=0;
    char c;
    while((c=infix[i])!='\0'){
        if(isalnum(c)) postfix[j++]=c;
        else if(c=='(') push(c);
        else if(c==')'){
            while(peek()!='(') postfix[j++]=pop();
            pop();
        }
        else if(isOperator(c)){
            while(top!=-1 && precedence(peek())>=precedence(c))
                postfix[j++]=pop();
            push(c);
        }
        i++;
    }
    while(top!=-1) postfix[j++]=pop();
    postfix[j]='\0';
}

int main(){
    char infix[MAX],postfix[MAX];
    printf("Enter an infix expression: ");
    fgets(infix,MAX,stdin);
    infix[strcspn(infix,"\n")] = '\0';
    infix_to_postfix(infix,postfix);
    printf("Postfix expression: %s",postfix);
    return 0;
}
