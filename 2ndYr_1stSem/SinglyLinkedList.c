#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
}*head;

void display();
int length();
void deleteFirst();
void insertFirst(int data);
void deleteLast();
void insertLast(int data);

int main()
{
	head = NULL;
	printf("0.Exit\n1.Display\n2.Length\n3.InsertFirst\n4.InsertLast\n5.DeleteFirst\n6.DeleteLast\n");
	int ch,item;
	while(1)
	{
		printf("Enter Option\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				return 0;
			case 1:
				display();
				break;
			case 2:
				printf("Length is : %d\n",length());
				break;
			case 3:
				printf("Enter Element to Insert\n");
				scanf("%d",&item);
				insertFirst(item);
				break;
			case 4:
				printf("Enter Element to Insert\n");
				scanf("%d",&item);
				insertLast(item);
				break;
			case 5:
				deleteFirst();
				break;
			case 6:
				deleteLast();
				break;
			default:
				printf("Invalid Input\n");
		}
	}
}

void display()
{
	if(head == NULL)
		printf("Nothing to Display\n");
	struct node* current = head;
	while(current != NULL)
	{
		printf("%d\n",current->data);
		current = current->next;
	}
}

int length()
{
	struct node* current=head;
	int len = 0;
	while(current != NULL)
	{
		len++;
		current = current->next;
	}
	return len;
}

void deleteFirst()
{
	if(head == NULL)
		printf("Underflow\n");
	else
	{
		printf("Element deleted : %d\n" , head->data);
		head = head->next;
	}
}

void insertFirst(int data)
{
	struct node* newnode =	(struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = head;
	head = newnode;
}

void deleteLast()
{
	if(head == NULL)
	{
		printf("Underflow\n");
		return;
	}
	if(head->next == NULL)
	{
		head = NULL;
		return;
	}
	struct node* temp = head;
	while(temp->next->next != NULL)
		temp = temp -> next;
	printf("Deleted Element : %d\n",temp->next->data);
	temp->next = NULL;
}

void insertLast(int data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	if(head == NULL)
	{
		head = newnode;
		return;
	}
	struct node* temp = head;
	while(temp->next != NULL)
		temp=temp->next;
	temp->next = newnode;
}