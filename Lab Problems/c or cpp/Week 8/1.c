#include<stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};

typedef struct {
	struct node *top;
	int size;
} stack;

void push(stack *stk, int val)
{
	if(stk->top == NULL)
		stk->size = 0;
	
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->num = val;
	new_node->next = stk->top;
	
	stk->top = new_node;
	stk->size++;
}

int pop(stack *stk)
{
	if(stk->top == NULL)
	{
		printf("Stack is empty!\n");
		return 0;
	}
	
	int t = stk->top->num;
	struct node *tmp = stk->top;
	stk->top = stk->top->next;
	free(tmp);
	stk->size--;
	
	return t;
	
}

int top(stack stk)
{
	return stk.top->num;
}

void display_stack(stack stk)
{
	if(stk.top == NULL)
	{
		printf("Stack is empty!\n");
		return;
	}
	
	int size = stk.size,i;
	struct node *tmp = stk.top;
	for(i=1;i<size;++i,tmp=tmp->next)
		printf("%d->",tmp->num);
	printf("NULL\n");
}

typedef struct {
	stack in,out;
	int size;
} queue;

void enqueue(queue *q, int val)
{
	if(q->in->top == NULL && q->out->top == NULL)
		q->size = 0;
	
	push(&(q->in),val);
	q->size++;
}

int dequeue(queue *q)
{
	if(q->out->top != NULL)
		return pop(&(q->out));
	
	while(q->in->top != NULL)
	{
		push(&(q->out),pop(&(q->in)));
	}
	
	return pop(&(q->out));
}

void display_queue(queue q)
{
	printf("Stack In - ");
	display_stack(q.in);
	printf("stack Out - ");
	display_stack(q.out);
}

int main()
{
	stack s1;
	push(&s1,5);
	push(&s1,4);
	push(&s1,3);
	push(&s1,2);
	push(&s1,1);
	
	display_stack(s1);
	
	return 0;
}
