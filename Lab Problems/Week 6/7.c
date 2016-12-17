#include<stdio.h>
#include<stdlib.h>
struct node {
	int value;
	struct node *next;
};

void insert_front(struct node **head,int val)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->value = val;
	new_node->next = *head;
	
	*head = new_node;
}

void delete_front(struct node **head)
{
	if(*head == NULL)
	{
		printf("Linked List is empty!\n");
		return;
	}
	struct node *tmp=*head;
	*head = (*head)->next;
	free(tmp);
}

void delete_end(struct node **head)
{
	if(*head == NULL)
	{
		printf("Linked List is empty!\n");
		return;
	}
	if((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		return;
	}
	
	struct node *tmp = *head,*prev=tmp;
	while(tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	free(prev->next);
	prev->next = NULL;
}

void print_list(struct node **head)
{
	if(*head == NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
	
	struct node *tmp=*head;
	while(tmp != NULL)
	{
		printf("%d",tmp->value);
		tmp->next != NULL?printf("->"):0;
		tmp = tmp->next;
	}
	printf("\n");
	return;
}

int main()
{
	struct node *list = NULL;
	insert_front(&list,5);
	insert_front(&list,4);
	insert_front(&list,3);
	insert_front(&list,2);
	insert_front(&list,1);
	
	delete_end(&list);
	print_list(&list);
	
	return 0;
}
