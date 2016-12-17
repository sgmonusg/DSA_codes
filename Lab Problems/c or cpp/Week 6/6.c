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

void insert_end(struct node **head,int val)
{
	struct node *start=*head,*new_node = (struct node*) malloc(sizeof(struct node));
	
	new_node->value = val;
	new_node->next = NULL;
	
	if(start == NULL)
		*head = new_node;
	else
	{
		while(start->next != NULL)
			start = start->next;
		start->next = new_node;
	}
}

void insert_at_val(struct node **head,int val, int at)
{
	if(head == NULL)
	{
		printf("Linked List is empty!\n");
		return;
	}
	
	struct node *start=*head,*new_node = (struct node*) malloc(sizeof(struct node));
	new_node->value = val;
	
	if(start->value == at)
	{
		new_node->next = start;
		*head = new_node;
		return;
	}
	
	while(start->next != NULL && start->next->value != at)
		start = start->next;
	
	if(start->next == NULL)
	{
		printf("Element not found in linked list\n");
		return;
	}
	
	new_node->next = start->next;
	start->next = new_node;
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

void reverse_list_recursive_util(struct node *prev,struct node *cur,struct node **head)
{
	if(cur == NULL)
	{
		*head = prev;
		return;
	}
	struct node *next = cur->next;
	cur->next = prev;
	
	prev = cur;
	cur = next;
	reverse_list_recursive_util(prev,cur,head);
}

void reverse_list_recursive(struct node **head)
{
	if(*head == NULL)
		printf("Linked list is empty\n");
	else
		reverse_list_recursive_util(NULL,*head,head);
}

void reverse_list(struct node **head)
{
	if(*head == NULL)
	{
		printf("Linked List is empty!\n");
		return;
	}
	
	struct node *cur=*head,*prev=NULL,*next;
	while(cur != NULL)
	{
		next = cur->next;
		
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	
	*head = prev;
}

int main()
{
	struct node *list = NULL;
	insert_front(&list,5);
	insert_front(&list,4);
	insert_front(&list,3);
	insert_front(&list,2);
	insert_front(&list,1);
	
	insert_end(&list,6);
	
	reverse_list_recursive(&list);
	
	print_list(&list);
	
	return 0;
}
