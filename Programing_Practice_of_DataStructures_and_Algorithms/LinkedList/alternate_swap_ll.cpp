#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;

struct node
{
	int value;
	struct node *next;
};

void add(struct node **head, struct node **tail, int value);        //Working
void print_list(struct node **head);        //Working
void length(struct node **head);        //Working
void swap_alternate(struct node **head);

int main()
{
	struct node *head, *tail,*sortdata=NULL ,*sort=NULL;
	head = NULL;
	tail = NULL;

	struct node *head2, *tail2 ;
	head2 = NULL;
	tail2 = NULL;

	struct node *a1, *a2 ,*a3, *a4;
	a1 = NULL;
	a2 = NULL;
	a3 = NULL;
	a4 = NULL;
	add(&head, &tail, 2);
	add(&head, &tail, 4);
	//add(&head, &tail, 7);
	//add(&head, &tail, 8);
	//add(&head, &tail, 55);
	length(&head);
	print_list(&head);
    printf("First linked list is been made succefully");
    cout<<endl;
    swap_alternate(&head);
	print_list(&head);
	return 0;
}

void swap_alternate(struct node **head)
{
	struct node *prev = NULL;
	struct node *first = *head;
	struct node *second = NULL;
	while(first != NULL && first->next != NULL)
	{
		second = first->next;
		if(prev == NULL)
		{
			first->next = second->next;
			second->next = first;
			*head = second;
			prev = first;
		}
		else
		{
			first->next = second->next;
			second->next = first;
			prev->next = second;
			prev = first;
		}
		first = first->next;
	}
}

void length(struct node **head)
{
	struct node*c;
	c = *head;
	int count=0;
	while(c!=NULL)
	{
		c = c->next;
		count++;
	}
	printf("length = %d", count);
}

void add(struct node **head, struct node **tail, int value)
{
	struct node *temp, *ttail, *thead;
	ttail = *tail;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->next=NULL;
	temp->value=value;
	if(*head==NULL)
	{
		*head=temp;
		*tail=temp;
	}
	else
	{
		(*tail)->next=temp;
		*tail=temp;
	}
}

void print_list(struct node **head)
{
	struct node *temp;
	printf("\n\n");
	for(temp=*head; temp!=NULL; temp=temp->next)
	{
		printf("%d->",(temp->value));
	}
	printf("[NULL]\n\n");
}
