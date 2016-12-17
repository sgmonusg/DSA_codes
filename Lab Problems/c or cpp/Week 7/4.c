#include<stdio.h>
#include<stdlib.h>

struct node {
	int value;
	struct node *next;
	struct node *prev;
};

typedef struct {
	struct node *head;
	int size;
} circular_ll;

void insert_front(circular_ll *list,int val)
{
	if(list->head == NULL)
	{
		list->head = (struct node *) malloc(sizeof(struct node));
		list->head->value = 0;
		list->head->prev = NULL;
		list->head->next = NULL;
		
		list->size = 0;
	}
	
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->value = val;
	
	if(list->head->next == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node->next = list->head->next;
		new_node->prev = list->head->next->prev;
		list->head->next->prev = new_node;
	}
	
	list->head->next = new_node;
	list->size++;
}

void insert_back(circular_ll *list,int val)
{
	if(list->head == NULL)
	{
		insert_front(list,val);
		return;
	}
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->value = val;
	new_node->next = list->head->next;
	new_node->prev = list->head->next->prev;
	
	list->head->next->prev->next = new_node;
	list->head->next->prev = new_node;
	
	list->size++;
}

void insert_at(circular_ll *list, int val, int pos)
{
	if(pos == 0)
	{
		insert_front(list,val);
		return;
	}
	if(list->head == NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
	
	struct node *new_node = (struct node *) malloc(sizeof(struct node)),*tmp=list->head->next;
	new_node->value = val;
	
	while(pos--)
		tmp = tmp->next;
	
	new_node->next = tmp;
	new_node->prev = tmp->prev;
	
	tmp->prev->next = new_node;
	tmp->prev = new_node;
	list->size++;
}

void print_list(circular_ll list)
{
	if(list.head->next == NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
	struct node *tmp=list.head->next;
	int n = list.size;
	while(n--)
	{
		printf("%d->",tmp->value);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

int main()
{
	circular_ll list1;
	list1.head = NULL;
	
	insert_front(&list1,6);
	insert_front(&list1,5);
	insert_front(&list1,4);
	insert_front(&list1,3);
	insert_front(&list1,2);
	insert_front(&list1,1);
	
	insert_back(&list1,7);
	insert_back(&list1,9);
	insert_back(&list1,10);
	
	print_list(list1);
	
	insert_at(&list1,8,7);
	print_list(list1);
	
	return 0;
}
