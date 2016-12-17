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
	printf("%d\n",tmp->value);
}

void delete_skip(circular_ll list,int skip)
{
	if(list.head->next == NULL || list.size <= 0)
	{
		printf("Linked List is Empty\n");
		return;
	}
	if(list.size == 1)
	{
		printf("Last Element: %d\n",list.head->next->value);
		return;
	}
	
	skip %= list.size;
	int i;
	struct node *tmp;
	
	while(list.size > 1)
	{
		tmp = list.head->next;
		for(i=0;i<skip;++i)
			tmp = tmp->next;
		
		list.head->next = tmp;
		tmp = tmp->prev;
		
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		free(tmp);
		list.size--;
	}
	printf("Last Element - %d\n",list.head->next->value);
}

int main()
{
	circular_ll list;
	list.head = NULL;
	
	int i,n,k;
	scanf("%d %d",&n,&k);
	
	for(i=0;i<n;++i)
		insert_back(&list,i+1);
	print_list(list);
	
	delete_skip(list,k);
	
	return 0;
}
