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

void node_swap(struct node **a, struct node **b)
{
	int tmp;
	
	tmp = (*a)->value;
	(*a)->value = (*b)->value;
	(*b)->value = tmp;
}

void ll_partition(struct node **head)
{
	struct node *i=*head,*j,*tmp;
	
	for(j=(*head)->next;j != NULL; j=j->next)
	{
		if(j->value%2 == 0)
		{
			node_swap(&i,&j);
			i = i->next;
		}
	}
	return;
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

int main()
{
	struct node *list=NULL;
	insert_front(&list,6);
	insert_front(&list,5);
	insert_front(&list,4);
	insert_front(&list,3);
	insert_front(&list,2);
	insert_front(&list,1);
	
	print_list(list);
	
	ll_partition(&list);
	print_list(list);
	
	return 0;
}
