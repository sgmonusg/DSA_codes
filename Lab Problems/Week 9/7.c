#include<stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *prev,*next;
};

void insert_front(struct node **head,int n)
{
	struct node *new_node = malloc(sizeof(struct node));
	new_node->num = n;
	new_node->prev = NULL;
	new_node->next = (*head);
	
	if(*head != NULL)
		*head->prev = new_node;
	*head = new_node;
}

int ll_search(struct node *head, int n)
{
	if(*head == NULL)
		return 0;
	
	struct node *tmp = *head;
	while(tmp != NULL && tmp->num != n)
		tmp = tmp->next;
	if(tmp->num == n)
		return 1;
	return 0;
}

void ll_delete(struct node **head,int n)
{
	if(*head == NULL)
		return;
	struct node *tmp = *head;
	while(tmp != NULL && tmp->num != n)
		tmp = tmp->next;
	
	if(tmp->num == n)
	{
		if(tmp->prev != NULL)
			tmp->prev->next = tmp->next;
		else
			*head = NULL;
		if(tmp->next != NULL)
			tmp->next->prev = tmp->prev;
		free(tmp);
	}
}

#define size 10
struct node *table[size];

int hash(int k)
{
	return k%size;
}
int hash2(int k)
{
	return 7 - (k%7);
}

void hash_insert(int k)
{
	if(table[hash(k)] == NULL)
		insert_front(&table[hash(k)],k);
	else
		insert_front(&table[hash2(k)],k);
}

void hash_search(int k)
{
	if()
}

int main()
{
	return 0;
}
