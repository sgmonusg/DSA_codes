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

struct s_node {
	struct t_node *node;
	struct s_node *next;
};

typedef struct {
	struct s_node *top;
	int size;
} stack;

void push(stack *s,struct t_node *k)
{
	if(s->top == NULL)
		s->size = 0;
	
	struct s_node *new_node = (struct s_node *) malloc(sizeof(struct s_node));
	new_node->node = k;
	new_node->next = (s->top);
	(s->top) = new_node;
	s->size++;
	
}
struct t_node *pop(stack *s)
{
	if(s->top == NULL)
	{
		s->size = 0;
		return NULL;
	}
	
	struct t_node *n = s->top->node;
	
	struct s_node *tmp = s->top;
	s->top = s->top->next;
	free(tmp);
	s->size--;
	
	return n;
}

struct t_node *top(stack s)
{
	return s.top->node;
}
int is_empty(stack s)
{
	return (s.top == NULL) ? 1 : 0;
}

int main()
{
	struct t_node *root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	root->left->right = new_node(5);
	
	stack s1,s2;
	push(&s2,root);
	push(&s1,root);
	
	/*
	while(!is_empty(s1))
	{
		struct t_node *n = pop(&s1);
		push(&s2,n);
		
		if(n->left != NULL)
			push(&s1,n->left);
		if(n->right != NULL)
			push(&s1,n->right);
	} /**/
	
	struct t_node *n;
	while(!is_empty(s2))
	{
		n = pop(&s2);
		printf("%d ",n->num);
	} /**/
	
	return 0;
}
