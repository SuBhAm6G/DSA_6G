#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct node{
    char *expr;
    struct node *next;
}n;

int isEmpty(n *top){
    return (top==NULL);
}

int isOperator(char c){
    return (c=='+'||c=='-'||c=='*'||c=='/');
}

void Push(n **top, char* exp){
    n *newnode=(n*)malloc(sizeof(n));
    newnode->expr=(char*)malloc(sizeof(exp)+1);
    strcpy(newnode->expr, exp);
    newnode->next=*top;
    *top=newnode;
}

char* Pop(n **top){
    if(isEmpty(*top)){
        printf("Stack is Empty\n");
        exit(1);
    }
    n *temp=*top;
    char *ch=temp->expr;
    *top=temp->next;
    free(temp);
    return ch;
}

void PostToInfix(n **top, char *expr){
    if(expr[0]=='\0'){
        printf("No input");
        exit(1);
    }
    for(int i=0; expr[i]!='\0'; i++){
        char ch=expr[i];
        if(isalnum(ch)){
            char op[2]={ch, '\0'};
            Push(top, op);
        }
        else if(isspace(ch)){
            continue;
        }
        else if(isOperator(ch)){
            char *A=Pop(top);
            char *B=Pop(top);
            char temp[20];
            sprintf(temp,"%s%c%s",B,ch,A);
            Push(top,temp);
        }
    }
    char *result=Pop(top);
    printf("%s", result);
}
int main() {
    n *top=NULL;
    char *expr=(char*)malloc(100*sizeof(char));
    printf("Enter a Postfix Expression: ");
    scanf("%s", expr);
    PostToInfix(&top, expr);
    return 0;
}
