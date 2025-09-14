#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char data;
    struct node *next;
} n;

int isEmpty(n *top) {
    return (top == NULL);
}

void Push(n **top, char c) {
    n *newnode = (n *)malloc(sizeof(n));
    newnode->data = c;
    newnode->next = *top;
    *top = newnode;
}

char Pop(n **top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    n *temp = *top;
    char c = temp->data;
    *top = temp->next;
    free(temp);
    return c;
}

char Peek(n *top) {
    if (isEmpty(top)) return '\0';
    return top->data;
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void InfixToPostfix(char *expr) {
    n *top = NULL;
    char result[200];
    int k = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (isalnum(ch)) {
            result[k++] = ch;
        } else if (ch == '(') {
            Push(&top, ch);
        } else if (ch == ')') {
            while (!isEmpty(top) && Peek(top) != '(') {
                result[k++] = Pop(&top);
            }
            if (!isEmpty(top) && Peek(top) == '(') {
                Pop(&top);
            }
        } else {
            while (!isEmpty(top) && precedence(Peek(top)) >= precedence(ch)) {
                result[k++] = Pop(&top);
            }
            Push(&top, ch);
        }
    }

    while (!isEmpty(top)) {
        result[k++] = Pop(&top);
    }

    result[k] = '\0';
    printf("%s", result);
}

int main() {
    char expr[100];
    printf("Enter an Infix Expression: ");
    scanf("%s", expr);
    InfixToPostfix(expr);
    return 0;
}
