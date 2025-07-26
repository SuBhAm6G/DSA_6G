//Evaluate value of a polynomial using Horner's method. Take input from user

#include <stdio.h>
#include <stdlib.h>

//Horner's Recursion
double Horner(int coeff[], int n, int x){
    //Base Case
    if(n==0)
        return coeff[0];
    //recursive Case
    else
        return Horner(coeff+1, n-1,x)*x+coeff[0];
}

int main() {
    int n, *coeff, x;
    printf("Enter the degree of equation: ");
    scanf("%d", &n);
    //allocating memory
    coeff=(int*)malloc((n+1)*sizeof(int));
    if(coeff==NULL){
        perror;
    }
    //Taking input of coefficients and x
    for (int i = n; i >= 0; i--)
    {
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%d", &coeff[i]);
    }
    printf("\n");
    printf("The polynomial is: ");
    for (int i = n; i >= 0; i--)
    {
        printf(" (%d)x^%d ", coeff[i], i);
        if(i>0){
            printf("+");
        }
    }
    printf("\n");
    printf("Enter x: ");
    scanf("%d", &x);
    printf("\n");

    //Calling function and printing result
    printf("The value of given polynomial is = %d", (int)Horner(coeff,n,x));
    free(coeff);
    return 0;
}