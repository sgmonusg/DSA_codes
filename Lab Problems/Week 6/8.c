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

struct node* merge_sorted_list(struct node *h1,struct node *h2)
{
	if(h1 == NULL)
		return h2;
	if(h2 == NULL)
		return h1;
	
	struct node *head=NULL;
	
	if(h1->value < h2->value)
	{
		head = h1;
		head->next = merge_sorted_list(h1->next,h2);
	}
	else
	{
		head = h2;
		head->next = merge_sorted_list(h1,h2->next);
	}
	
	return head;
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
	struct node *list1 = NULL,*list2=NULL,*list=NULL;
	
	insert_front(&list1,5);
	insert_front(&list1,3);
	insert_front(&list1,1);
	
	insert_front(&list2,6);
	insert_front(&list2,4);
	insert_front(&list2,2);
	
	list = merge_sorted_list(list1,list2);
	
	print_list(&list);
	
	return 0;
}
