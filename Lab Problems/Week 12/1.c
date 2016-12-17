#include<stdio.h>
#include<stdlib.h>

struct t_node {
	int num;
	struct t_node *left,*right;
};

struct t_node *new_node(int n)
{
	struct t_node *new_node = (struct t_node *) malloc(sizeof(struct t_node));
	
	new_node->num = n;
	new_node->left = NULL;
	new_node->right = NULL;
	
	return new_node;
}

struct l_node {
	int num;
	struct l_node *next;
};

void insert_front(struct l_node **head, int n)
{
	struct l_node *new_node = (struct l_node *) malloc(sizeof(struct l_node));
	
	new_node->num = n;
	new_node->next = (*head);
	
	*head = new_node;
};

int path_sum(struct l_node *head)
{
	if(head == NULL)
		return 0;
	int p_sum = path_sum(head->next) + head->num;
	return p_sum;
}

struct l_node *max_path(struct t_node *root)
{
	if(root == NULL)
		return NULL;
	struct l_node *l1=max_path(root->left),*l2=max_path(root->right),*lmax;
	
	if(path_sum(l1) < path_sum(l2))
		lmax = l1;
	else
		lmax = l2;
	
	insert_front(&lmax,root->num);
	return lmax;
}

void print_ll(struct l_node *root)
{
	if(root == NULL)
		return;
	
	print_ll(root->next);
	printf("(%d) -> ",root->num);
}

int main()
{
	struct t_node *root = new_node(10);
	root->left = new_node(-2);
	root->right = new_node(7);
	root->left->left = new_node(8);
	root->left->right = new_node(-4);
	
	print_ll(max_path(root));
}
