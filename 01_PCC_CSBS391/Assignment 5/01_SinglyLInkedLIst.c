//a) Implement Singly Linked List and related operations  like insertion, deletion, display, reverse and sort in C. 
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int val;
	struct node *next;
}n;

int isEmpty(n *head){
	if(head==NULL)
		return 1;
	else
		return 0;
}

int getLength(n *head){
	if(isEmpty(head)){
		return 0;
	}
	else{
		n *temp=head;
		int count=0;
		while(temp!=NULL){
			count++;
			temp=temp->next;
		}
		return count;
	}
}
void create(n **head){
	n *newnode=(n*)malloc(sizeof(n));
	printf("Enter value of newnode: ");
	scanf("%d", &newnode->val);
	newnode->next==NULL;
	if(isEmpty(*head)){
		*head=newnode;
		return;
	}
	n *temp=*head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
}

void display(n *head){
	if(isEmpty(head)){
		printf("List is Empty\n");
		return;
	}
	n *temp=head;
	while(temp!=NULL){
		printf("%d ",temp->val);
		temp=temp->next;
	}
	printf("\n");
}

void InsAtBegin(n **head){
	n *newnode=(n*)malloc(sizeof(n));
	printf("Enter value of newnode: ");
	scanf("%d", &newnode->val);
	newnode->next==NULL;
	if(isEmpty(*head)){
		*head=newnode;
		return;
	}
	n *temp=*head;
	newnode->next=*head;
	*head=newnode;
}
void InsAtEnd(n **head){
	if(isEmpty(*head)){
		InsAtBegin(head);
		return;
	}
	n *newnode=(n*)malloc(sizeof(n));
	printf("Enter value of newnode: ");
	scanf("%d", &newnode->val);
	newnode->next==NULL;
	n *temp=*head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
	
}
void InsAtPos(n **head,int pos){
	int len=getLength(*head);
	if(pos>len+1 || pos<1){
		printf("Invalid Positon\n");
		return;
	}
	if(isEmpty(*head) || pos ==1){
		InsAtBegin(head);
		return;
	}
	if(pos==len+1){
		InsAtEnd(head);
		return;
	}
	n *newnode=(n*)malloc(sizeof(n));
	printf("Enter value of newnode: ");
	scanf("%d", &newnode->val);
	newnode->next==NULL;
	int i;
	n *temp=*head;
	for(i=1; i<pos -1; i++){
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;	
}

void DelAtBegin(n **head){
	if(isEmpty(*head)){
		printf("List is Empty\n");
		return;
	}
	n *temp=*head;
	*head=temp->next;
	free(temp);
}
void DelAtEnd(n **head){
	if(isEmpty(*head)){
		printf("List is Empty\n");
		return;
	}
	if((*head)->next==NULL){
		DelAtBegin(head);
		return;
	}
	n *temp=*head;
	n *prev=NULL;
	while(temp->next!=NULL){
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	free(temp);
}
void DelByVal(n **head, int val){
	if(isEmpty(*head)){
		printf("List is Empty\n");
		return;
	}
	n *temp=NULL;
	n *prev=NULL;
	for(temp=*head; temp!=NULL; temp=temp->next){
		if(temp->val==val){
			break;
		}
		prev=temp;
	}
	if(temp==NULL){
		printf("Value not found\n");
		return;
	}
	prev->next=temp->next;
	free(temp);
}
void Reverse(n **head){
	if(isEmpty(*head)){
		printf("List is Empty\n");
		return;
	}
	if((*head)->next==NULL){
		printf("Only one element is in List\n");
		return;
	}
	n *prev=NULL, *curr=*head, *next=*head;
	
	while(next!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	*head=prev;
}
void Sort(n **head){
	if(isEmpty(*head)){
		printf("List is Empty\n");
		return;
	}
	if((*head)->next==NULL){
		printf("Only one element is in List\n");
		return;
	}
	n *i=NULL;
	int temp;
	int swapped;
	do{
	swapped=0;
	for(i=*head; i->next!=NULL; i=i->next){
		if((i->val)>(i->next->val)){
		temp=i->val;
		i->val=i->next->val;
		i->next->val=temp;
		swapped=1;
		}
	}
	}while(swapped);
}
int main(){
	n *head=NULL;
	int n;
	while(1){
		printf("Menu:\n1. Create | 2. Display | 3. Insertion At Beginning | 4. Insertion At End | 5. Insertion At Position | 6. Deletion At Begin | 7. Deletion At End | 8. Deletion By Value | 9. Reverse | 10. Sort | 11. Exit\n");
		printf("Enter Your Choice: ");
		scanf("%d", &n);
		switch(n){
			case 1: create(&head);
				break;
			case 2: printf("The list is: ");
				display(head);
				break;
			case 3: InsAtBegin(&head);
				printf("\nThe new list: ");
				display(head);
				break;
			case 4: InsAtEnd(&head);
				printf("\nThe new list: ");
				display(head);
				break;
			case 5: int pos;
				printf("Enter the position: ");
				scanf("%d", &pos);
				InsAtPos(&head, pos);
				printf("\nThe new list: ");
				display(head);
				break;
			case 6: DelAtBegin(&head);
				printf("\nThe new list: ");
				display(head);
				break;
			case 7: DelAtEnd(&head);
				printf("\nThe new list: ");
				display(head);
				break;
			case 8: int val;
				printf("Enter the value: ");
				scanf("%d", &val);
				DelByVal(&head, val);
				printf("\nThe new list: ");
				display(head);
				break;
			case 9: Reverse(&head);
				printf("\nThe new list: ");
				display(head);
				break;
			case 10: Sort(&head);
				printf("\nThe new list: ");
				display(head);
				break;
			case 11: exit(0);
			default: printf("Invalid Choice\n");
		}
	}

return 0;
}
