#include<stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};

void insert_front(struct node **head, int n)
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->num = n;
	new_node->next = *head;
	*head = new_node;
}

void print_list(struct node *head)
{
	struct node *tmp = head;
	while(tmp != NULL)
	{
		printf("%d->",tmp->num);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

int ll_search(struct node *head, int n)
{
	struct node *tmp = head;
	while(tmp != NULL && tmp->num != n)
		tmp = tmp->next;
	if(tmp->num == n)
		return 1;
	return 0;
}

void delete_node(struct node **head, int n)
{
	if(*head == NULL)
		return;
	struct node *tmp = *head;
	if(tmp->num == n)
	{
		*head = tmp->next;
		free(tmp);
		return;
	}
	
	while(tmp->next != NULL && tmp->next->num != n)
		tmp = tmp->next;
	if(tmp->next == NULL)
		return;
	tmp->next = tmp->next->next;
	free(tmp);
}

#define size 10
struct node *table[size];

int hash(int n)
{
	return n%size;
}
void hash_insert(int n)
{
	insert_front(&table[hash(n)],n);
}
int hash_search(struct node *table[],int n)
{
	int i;
	for(i=0;i<size;++i)
	{
		if(ll_search(table[i],n))
			return 1;
	}
	return 0;
}
void print_hash(struct node *table[])
{
	int i;
	for(i=0;i<size;++i)
	{
		printf("%d: ",i);
		print_list(table[i]);
	}
}

int main()
{
	int arr[] = {71, 23, 73, 99, 44, 19, 49, 93, 81, 39},i;
	for(i=0;i<size;++i)
		hash_insert(arr[i]);
	print_hash(table);
	return 0;
}
