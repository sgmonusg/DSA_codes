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

void reverse_sublist(struct node **head,int l,int m)
{
	struct node *cur=(*head),*next,*prev=NULL,*tmp;
	int i,j;
	
	for(i=0;i<l && cur != NULL;++i)
	{
		prev = cur;
		cur = cur->next;
	}
	tmp = prev == NULL ? (*head) : prev;
	//printf("%d",tmp->value);
	
	for(i=0;i<m && cur != NULL;++i)
	{
		next = cur->next;
		
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	
	if(tmp != *head)
	{
		tmp->next->next = cur;
		tmp->next = prev;
	}
	else
	{
		tmp->next = cur;
		(*head) = prev;
	}
}

int main()
{
	struct node *list=NULL;
	insert_front(&list,8);
	insert_front(&list,7);
	insert_front(&list,6);
	insert_front(&list,5);
	insert_front(&list,4);
	insert_front(&list,3);
	insert_front(&list,2);
	insert_front(&list,1);
	
	print_list(list);
	
	reverse_sublist(&list,0,6);
	print_list(list);
	
	return 0;
}
