#include<stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};

void insert_front(struct node **head, int val)
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->num = val;
	new_node->next = (*head);
	(*head) = new_node;
}

void insert_back(struct node **head, int val)
{
	if(*head == NULL)
	{
		insert_front(head,val);
		return;
	}
	
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->num = val;
	new_node->next = NULL;
	
	struct node *tmp = (*head);
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
}

void print_list(struct node *head)
{
	if(head == NULL)
	{
		printf("Linked List is Empty!!\n");
		return;
	}
	
	struct node *tmp = head;
	while(tmp != NULL)
	{
		printf("%d->",tmp->num);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

void remove_duplicates(struct node **head)
{
	if(*head == NULL)
	{
		printf("Linked List is Empty!!\n");
		return;
	}
	
	struct node *i,*j,*tmp;
	for(i=(*head); i != NULL && i->next != NULL; i = i->next)
	{
		for(j = i; j->next != NULL ;)
		{	
			if(i->num == j->next->num)
			{
				tmp = j->next;
				j->next = j->next->next;
				free(tmp);
			}
			else  // This is tricky
				j = j->next;
		}
		printf("%d,%d  ",i->num,j->num);
		print_list(*head);
	}
}

int main()
{
	struct node *list = NULL;
	
	insert_back(&list,2);
	insert_back(&list,4);
	insert_back(&list,1);
	insert_back(&list,3);
	insert_back(&list,4);
	insert_back(&list,2);
	insert_back(&list,6);
	insert_back(&list,5);
	insert_back(&list,7);
	insert_back(&list,5);
	insert_back(&list,3);
	
	print_list(list);
	
	remove_duplicates(&list);
	print_list(list);
}
