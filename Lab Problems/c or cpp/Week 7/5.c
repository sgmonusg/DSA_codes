#include<stdio.h>
#include<stdlib.h>
struct node {
	struct node *prev;
	int value;
	struct node *next;
};

void insert_front(struct node **head,int val)
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->value = val;
	new_node->next = *head;
	new_node->prev = NULL;
	
	if(*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}

void insert_back(struct node **head,int val)
{
	if(*head == NULL)
	{
		insert_front(head,val);
		return;
	}
	
	struct node *tmp = *head,*new_node = (struct node *) malloc(sizeof(struct node));
	new_node->value = val;
	new_node->next = NULL;
	
	while(tmp->next != NULL)
		tmp = tmp->next;
	
	new_node->prev = tmp;
	tmp->next = new_node;
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

void reverse_list_iter(struct node **head)
{
	if(*head == NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
	
	struct node *prev,*cur=*head,*next,*tmp;
	while(cur != NULL)
	{
		next = cur->next;
		prev = cur->prev;
		
		cur->next = prev;
		cur->prev = next;
		
		cur = next;
	}
	*head = prev;
}

void reverse_list_recursive_util(struct node **head, struct node *prev, struct node *cur)
{
	if(cur == NULL)
	{
		(*head) = prev;
		return;
	}
	
	struct node *next = cur->next;
	cur->next = prev;
	cur->prev = next;
	
	reverse_list_recursive_util(head,cur,next);
}

void reverse_list_recursive(struct node **head)
{
	if(*head == NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
	
	reverse_list_recursive_util(head,NULL,*head);
}

int main()
{
	struct node *list1 = NULL;
	insert_front(&list1,6);
	insert_front(&list1,5);
	insert_front(&list1,4);
	insert_front(&list1,3);
	insert_front(&list1,2);
	insert_front(&list1,1);
	
	insert_back(&list1,7);
	insert_back(&list1,8);
	insert_back(&list1,9);
	insert_back(&list1,10);
	
	print_list(list1);
	
	//reverse_list_iter(&list1);
	reverse_list_recursive(&list1);
	print_list(list1);
	return 0;
}
