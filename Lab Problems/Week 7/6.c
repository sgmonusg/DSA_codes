#include<stdio.h>
#include<stdlib.h>

struct node {
	int value;
	struct node *next;
};

void insert_front(struct node **head,int val)
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->value = val;
	new_node->next = *head;
	*head = new_node;
}

void print_list(struct node *head)
{
	if(head == NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
	struct node *tmp=head;
	while(tmp != NULL)
	{
		printf("%d->",tmp->value);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

int is_palindrome(struct node *head)
{
	struct node *tmp=head,*begin=head,*rev_head=NULL;
	int n=0,i=0;
	for(n=0;tmp != NULL;++n)
	{
		insert_front(&rev_head,tmp->value);
		tmp = tmp->next;
	}
	
	for(i=0;i<n;++i)
	{
		if(begin->value != rev_head->value)
			return 0;
	}
	
	return 1;
}

int main()
{
	struct node *list=NULL;
	insert_front(&list,5);
	insert_front(&list,4);
	insert_front(&list,3);
	insert_front(&list,3);
	insert_front(&list,4);
	insert_front(&list,5);
	print_list(list);
	
	printf("%d",is_palindrome(list));
	
	return 0;
}
