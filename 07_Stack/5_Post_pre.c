#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char *expr;
    struct node *next;
} n;

int isEmpty(n *top) {
    return (top == NULL);
}

void Push(n **top, char *exp) {
    n *newnode = (n *)malloc(sizeof(n));
    newnode->expr = (char *)malloc(strlen(exp) + 1);
    strcpy(newnode->expr, exp);
    newnode->next = *top;
    *top = newnode;
}

char* Pop(n **top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    n *temp = *top;
    char *c = temp->expr;
    *top = temp->next;
    free(temp);
    return c;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void PrefixToPostfix(char *expr) {
    n *top = NULL;
    int len = strlen(expr);

    for (int i = len - 1; i >= 0; i--) {
        char ch = expr[i];

        if (isalnum(ch)) {
            char op[2] = {ch, '\0'};
            Push(&top, op);
        } else if (isOperator(ch)) {
            char *op1 = Pop(&top);
            char *op2 = Pop(&top);

            char temp[200];
            sprintf(temp, "%s%s%c", op1, op2, ch);

            Push(&top, temp);
        }
    }

    char *result = Pop(&top);
    printf("%s", result);
}

int main() {
    char expr[100];
    printf("Enter a Prefix Expression: ");
    scanf("%s", expr);
    PrefixToPostfix(expr);
    return 0;
}
