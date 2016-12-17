#include<stdio.h>
#include<stdlib.h>

struct rbt_node {
	int num;
	enum {black,red} color;
	struct rbt_node *left,*right,*parent;
};

struct rbt_node sentinel;
struct rbt_node *head = &sentinel;

struct rbt_node *new_node(int n)
{
	struct rbt_node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->num = n;
	new_node->left = &sentinel;
	new_node->right = &sentinel;
	new_node->parent = NULL;
	new_node->color = red;
	
	return new_node;
	
}

void left_rotate(struct rbt_node *x)
{
	struct rbt_node *y = x->right;
	x->right = y->left;
	
	if(y->left != NULL)
		y->left->parent = x;
	y->parent = x->parent;
	
	if(x->parent == NULL)
		head = y;
	else if(x->parent->left == x)
		x->parent->left = y;
	else
		x->parent->right = y;
	
	y->left = x;
	x->parent = y;
}

void right_rotate(struct rbt_node *x)
{
	struct rbt_node *y = x->left;
	x->left = y->right;
	
	if(y->right != NULL)
		y->right->parent = x;
	y->parent = x->parent;
	
	if(x->parent == NULL)
		head = y;
	else if(x->parent->left == x)
		x->parent->left = y;
	else
		x->parent->right = y;
	
	y->right = x;
	x->parent = y;
}

void fix_color(node *z)
{
	while(x->parent->color == red)
	{
		if(z->parent == z->parent->parent->left)
		{
			node *y=z->parent->parent->right; //y is uncle
            
			if (y->c == red)
            {
                z->parent->c = black;
                y->c = black;
                z->parent->parent->c=red;
                z = z->parent->parent;
            }
            else
            {
                if(z==z->parent->right)
                {
                    z=z->parent;
                    leftRotate(z);
                }
                z->parent->c=Black;
                z->parent->parent->c=Red;
                rightRotate((z->parent->parent));
            }
		}
	}
}

int main()
{
	return 0;
}
