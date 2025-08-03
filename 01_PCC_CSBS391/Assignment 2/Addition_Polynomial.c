// Write a program for polynomial addition.
#include <stdio.h>
#include <stdlib.h>

long long int evaluate(int *Poly, int deg, int x);

int CoeffReader(int *Poly, int deg){
    int i;
    for (i = 0; i <= deg; i++)
    {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &Poly[i]);
    }
    if (i == deg + 1)
        return 1;
    else
        return 0;
    
}

void Print(int *Poly, int deg){
    for (int i = deg; i >= 0; i--)
    {
        if (i == 0)
            printf("%d", Poly[i]);
        else
            printf("%dx^%d + ", Poly[i], i);
    }
}

long long int evaluate(int *Poly, int deg, int x){
    long long int result = Poly[deg];
    for (int i = deg - 1; i >= 0; i--)
    {
        result = result * x + Poly[i];
    }
    return result;
}

int main(){
    int *Poly1, *Poly2, *sum;
    int deg1,deg2,max_deg;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1);
    printf("Enter degree of second polynomial: ");
    scanf("%d", &deg2);
    max_deg=deg1>deg2?deg1:deg2;
    Poly1=(int*)calloc(max_deg+1,sizeof(int));//using calloc to initialize allocated memory to zero
    Poly2=(int*)calloc(max_deg+1,sizeof(int));
    sum=(int*)calloc(max_deg+1,sizeof(int));

    //Reading Coeffs for first Polynomials
    printf("Enter coefficients of first polynomial:\n");
    if(CoeffReader(Poly1,deg1))
        printf("Coefficients of first polynomial read successfully.\n");
    else
        printf("Error reading coefficients of first polynomial.\n");

    //Reading Coeffs for second Polynomials
    printf("Enter coefficients of second polynomial:\n");
    if(CoeffReader(Poly2,deg2))
        printf("Coefficients of second polynomial read successfully.\n");
    else
        printf("Error reading coefficients of first polynomial.\n");

    //Print Polynomials
    printf("First Polynomial: ");
    Print(Poly1, deg1);
    printf("\nSecond Polynomial: ");
    Print(Poly2, deg2);

    //Addition of Polynomial
    for (int i = 0; i <= max_deg; i++)
    {
        sum[i]=Poly1[i]+Poly2[i];
    }
    printf("\n Summation of Polynomial is: ");
    Print(sum, max_deg);

    int x;
    printf("\n\nEnter the value of x to evaluate the polynomial: ");
    scanf("%d", &x);

    long long int final_result = evaluate(sum, max_deg, x);
    printf("Value of the polynomial for x = %d is: %lld\n", x, final_result);



    free(Poly1);
    free(Poly2);
    free(sum);

    return 0;
}
