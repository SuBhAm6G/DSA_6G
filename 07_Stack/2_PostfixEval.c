#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
    int val;
    struct node *next;
}n;

int isEmpty(n *top){
    if(top==NULL)
        return 1;
    else
        return 0;
}
void Push(n **top, int val){
    n *newnode=(n*)malloc(sizeof(n));
    newnode->val=val;
    newnode->next=*top;
    *top=newnode;
}

int Pop(n **top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
        return 0;
    }
    n *temp=*top;
    int val = (*top)->val;
    *top=(*top)->next;
    free(temp);
    return val;
}

void Display(n *top){ 
    if(isEmpty(top)){
        printf("Stack Underflow\n");
        return;
    }
    n *temp=top;
    while(temp!=NULL){
        printf("%d ", temp->val);
        temp=temp->next;
    }
    printf("\n");
}

int PostfixEval(n **top, char expr[]){
    for (int i = 0; expr[i] != '\0'; i++)
    {
        char c=expr[i];
        if(isdigit(c)){
            Push(top, c - '0');
        }
        else{
            int a=Pop(top);
            int b=Pop(top);
            switch(c){
                case '+': Push(top, b+a);
                break;
                case '-': Push(top, b-a);
                break;
                case '*': Push(top, b*a);
                break;
                case '/': if(a==0){
                    printf("Can't divide by zero\n");
                    exit(1);
                }
                Push(top, b/a);
                break;
            }
        }
    }
    return Pop(top);
}
int main() {
    n *top=NULL;
    char *expr=(char*)calloc(100,sizeof(char));
    printf("Enter Postfix expression: ");
    scanf("%s", expr);
    getchar();
    int result=PostfixEval(&top, expr);
    printf("The result is: %d", result);
    return 0;
}
