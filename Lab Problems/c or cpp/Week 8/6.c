#include<stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct queue {
	struct node *front,*back;
	int size;
};

void enqueue(struct queue *q,int val)
{
	if(q->front == NULL && q->back == NULL)
	{
		q->size = 0;
	}
	
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->num = val;
	new_node->next = NULL;
	
	if(q->back != NULL)
		q->back->next = new_node;
	q->back = new_node;
	
	if(q->front == NULL)
		q->front = new_node;
	
	else if(q->front == q->back)
	{
		q->front->next = q->back;
	}
	
	q->size++;
}

void push_front(struct queue *q,int val)
{
	if(q->front == NULL || q->back == NULL)
		return enqueue(q,val);
	
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->num = val;
	new_node->next = q->front;
	
	q->front = new_node;
	printf("%d  ",val);
}

int dequeue(struct queue *q)
{
	if(q->front == NULL)
	{
		printf("Queue is Empty!\n");
		return 0;
	}
	
	int temp = q->front->num;
	struct node *tmp=q->front;
	q->front = q->front->next;
	free(tmp);
	q->size--;
	
	return temp;
}

struct min_queue {
	struct queue q;
	struct queue min;
};

void min_enqueue(struct min_queue *q1, int val)
{
	if(q1->q.front == NULL)
	{
		q1->q.front = q1->q.back = NULL;
		q1->min.front = q1->min.back = NULL;
	}
	
	if(q1->min.front == NULL || val < q1->q.front->num)
	{
		if(q1->min.front != NULL)
			dequeue(&(q1->min));
		push_front(&(q1->min),val);
	}
	else
		enqueue(&(q1->min),q1->min.front->num);
	
	enqueue(&(q1->q),val);
	printf("%d\n",val);
}

int min_dequeue(struct min_queue *q1)
{
	int tmp = dequeue(&(q1->q));
	if(tmp == q1->min.front->num)
		dequeue(&(q1->min));
	return tmp;
}

int find_min(struct min_queue q1)
{
	return q1.min.front->num;
}

int main()
{
	struct min_queue q1;
	q1.q.front = q1.q.back =  NULL;
	
	min_enqueue(&q1,9);
	min_enqueue(&q1,5);
	min_enqueue(&q1,6);
	min_enqueue(&q1,7);
	min_enqueue(&q1,8);
	min_enqueue(&q1,3);
	
	printf("%d\t%d\n",find_min(q1),min_dequeue(&q1));
	printf("%d\t%d\n",find_min(q1),min_dequeue(&q1));
	printf("%d\t%d\n",find_min(q1),min_dequeue(&q1));
	printf("%d\t%d\n",find_min(q1),min_dequeue(&q1));
	printf("%d\t%d\n",find_min(q1),min_dequeue(&q1));
	
	return 0;
}
