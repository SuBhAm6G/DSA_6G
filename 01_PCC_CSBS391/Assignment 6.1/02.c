// B) Write a C program to add two  polynomials. 
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    int exp;
    struct node *next;
} node;

int isEmpty(node *head) {
    return head == NULL;
}

void insertNode(node **head) {
    node *newNode = (node*)malloc(sizeof(node));
    printf("Enter val: ");
    scanf("%d", &newNode->val);
    printf("Enter exponent: ");
    scanf("%d", &newNode->exp);
    newNode->next = NULL;
    
    if (isEmpty(*head)) {
        *head = newNode;
        return;
    }
    
    if (newNode->exp > (*head)->exp) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    node *temp = *head;
    while (temp->next != NULL && temp->next->exp > newNode->exp) {
        temp = temp->next;
    }
    
    if (temp->next != NULL && temp->next->exp == newNode->exp) {
        temp->next->val += newNode->val;
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(node *head) {
    if (isEmpty(head)) {
        printf("0\n");
        return;
    }
    
    int first = 1;
    while (head != NULL) {
        if (head->val != 0) {
            if (!first && head->val > 0) {
                printf(" + ");
            } else if (head->val < 0) {
                printf(" - ");
                head->val = -head->val;
            }
            
            if (head->exp == 0) {
                printf("%d", head->val);
            } else if (head->exp == 1) {
                if (head->val == 1) {
                    printf("x");
                } else {
                    printf("%dx", head->val);
                }
            } else {
                if (head->val == 1) {
                    printf("x^%d", head->exp);
                } else {
                    printf("%dx^%d", head->val, head->exp);
                }
            }
            first = 0;
        }
        head = head->next;
    }
    printf("\n");
}

void insertResult(node **head, int val, int exp) {
    if (val == 0) return;
    
    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->exp = exp;
    newNode->next = NULL;
    
    if (isEmpty(*head)) {
        *head = newNode;
        return;
    }
    
    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void addPolynomial(node *head1, node *head2, node **head3) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->exp > head2->exp) {
            insertResult(head3, head1->val, head1->exp);
            head1 = head1->next;
        } else if (head1->exp < head2->exp) {
            insertResult(head3, head2->val, head2->exp);
            head2 = head2->next;
        } else {
            int sum = head1->val + head2->val;
            if (sum != 0) {
                insertResult(head3, sum, head1->exp);
            }
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    
    while (head1 != NULL) {
        insertResult(head3, head1->val, head1->exp);
        head1 = head1->next;
    }
    
    while (head2 != NULL) {
        insertResult(head3, head2->val, head2->exp);
        head2 = head2->next;
    }
}

void freePolynomial(node **head) {
    while (*head != NULL) {
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    node *head1 = NULL;
    node *head2 = NULL;
    node *head3 = NULL;
    int choice;
    
    while (1) {
        printf("\n1. Add Node to Polynomial 1 | ");
        printf("2. Add Node to Polynomial 2 | ");
        printf("3. Display Polynomial 1 | ");
        printf("4. Display Polynomial 2 | ");
        printf("5. Add Polynomials | ");
        printf("6. Display Sum of Polynomials | ");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insertNode(&head1);
                break;
            case 2:
                insertNode(&head2);
                break;
            case 3:
                printf("Polynomial 1: ");
                display(head1);
                break;
            case 4:
                printf("Polynomial 2: ");
                display(head2);
                break;
            case 5:
                freePolynomial(&head3);
                addPolynomial(head1, head2, &head3);
                printf("Polynomials added successfully!\n");
                break;
            case 6:
                printf("Sum of Polynomials: ");
                display(head3);
                break;
            case 7:
                freePolynomial(&head1);
                freePolynomial(&head2);
                freePolynomial(&head3);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}