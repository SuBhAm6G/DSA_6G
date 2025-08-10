// a) Write a program in C to evaluate a postfix expression. MultiDigit Input should be considered.
#include <stdio.h>
#include <stdlib.h>

//pop,push,isEmpty,isFull
int isFull(int *top, int *n){
    if(*top >= (*n)-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(int *top){
    if(*top<0){
        return 1;
    }
    else
        return 0;
}
void Push(int *stack,int item,int *top, int *n){
    if(isFull(top,n)){
        printf("Stack Overflow\n");
        return;
    }
    stack[++(*top)]=item;
}

int Pop(int *stack,int *top){
    if(isEmpty(top)){
        printf("Stack Underflow\n");
        return 0;
    }
    return stack[(*top)--];
}

//Evaluation Function
int Evaluator(char *expr, int *stack, int *top, int*n){
    int i;
    //iterate through each character
    //digit checking
    for (i = 0; expr[i]!='\0'; i++)
    {
        if(expr[i]>=48 && expr[i]<=57){
            int num=0;
            while(expr[i]>=48 && expr[i]<=57){
                num=num*10 + (expr[i]-'0');
                i++;
            }
            Push(stack,num,top,n);
            i--;
        }
        else if(expr[i]==' '){
            continue;
        }
        else if(expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='/'){
            if(*top<1){
                printf("Insufficient Operands\n");
                return -1;
            }
            int a=Pop(stack, top);
            int b=Pop(stack, top);
            
            switch(expr[i]){
                case '+':
                    Push(stack, (a+b), top, n);
                    break;
                case '-':
                    Push(stack, (b-a), top, n);
                    break;
                case '*':
                    Push(stack, (a*b), top, n);
                    break;
                case '/':
                    if(a==0){
                        printf("Division by zero error\n");
                        return -1;
                    }
                    Push(stack, (b/a), top, n);
                    break;
            }
        }
        else if(expr[i]=='\n'){
            continue;
        }
        else{
            printf("Invalid Stack Character spotted %c", expr[i]);
            return 0;
        }
    }
    if(*top != 0) {
        printf("Invalid expression: multiple values remaining\n");
        return -1;
    }
    int result=Pop(stack, top);
    *top=-1;
    return result;
    
}
int main() {
    //Using memory allocation
    char *expr;
    int *stack;
    int n;
    int top=-1;
    printf("Enter Maximum number of characters allowed in postfix expression: ");
    scanf("%d", &n);
    getchar();
    stack=(int*)malloc(n*sizeof(int));     
    expr=(char*)malloc(n*sizeof(char));
    printf("Enter the postfix expression: ");
    fgets(expr, n, stdin);
    int result=Evaluator(expr,stack,&top,&n);
    printf("The Result is: %d", result);

    free(stack);
    free(expr);
    return 0;
}