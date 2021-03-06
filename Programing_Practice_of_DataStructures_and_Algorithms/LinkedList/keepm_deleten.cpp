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
void keep_delete(struct node *l, int m, int n);

int main()
{
	struct node *head, *tail,*sortdata=NULL ,*sort=NULL;
	head = NULL;
	tail = NULL;
	struct node *a1, *a2 ,*a3, *a4;
	a1 = NULL;
	a2 = NULL;
	a3 = NULL;
	a4 = NULL;
	add(&head, &tail, 2);
	add(&head, &tail, 4);
	add(&head, &tail, 7);
	add(&head, &tail, 7);
	add(&head, &tail, 8);
	add(&head, &tail, 55);
	length(&head);
	print_list(&head);
    cout<<endl;
    keep_delete(head, 2, 3);
    print_list(&head);
	return 0;
}

void keep_delete(struct node *l, int m, int n)
{
    struct node *x = NULL;
    struct node *t = NULL;

    while(l != NULL)
    {
        for(int i=1;i<m;i++)
        {
            if(l == NULL)
                break;
            l = l->next;
        }
        if(l == NULL)
            break;
        x = l;
        l = l->next;
        for(int i=0;i<n;i++)
        {
            if(l == NULL)
                break;
            t = l;
            l = l->next;
            free(t);
        }
        x->next = l;
        if(l == NULL)
            break;

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
