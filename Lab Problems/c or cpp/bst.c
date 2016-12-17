#include<stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *left,*right;
};

struct node *new_node(int n)
{
	struct node *tmp = (struct node *) malloc(sizeof(struct node));
	tmp->num = n;
	tmp->left = NULL;
	tmp->right = NULL;
	
	return tmp;
}

struct node *bst_insert(struct node *root, int n)
{
	if(root == NULL)
		return new_node(n);
	
	if(n < root->num)
		root->left = bst_insert(root->left,n);
	else if(n > root->num)
		root->right = bst_insert(root->right,n);
	
	return root;
}

struct node *find_min(struct node *root)
{
	if(root == NULL)
		return NULL;
	if(find_min(root->left) == NULL)
		return root;
}

struct node *bst_delete(struct node *root, int key)
{
	if(root == NULL)	
		return root;
	
	if(key < root->num)
		root->left = bst_delete(root->left,key);
	else if(key > root->num)
		root->right = bst_delete(root->right,key);
	
	else
	{
		if(root->left == NULL)
		{
			struct node *tmp = root->right;
			free(root);
			return tmp;
		}
		else if(root->right == NULL)
		{
			struct node *tmp = root->left;
			free(root);
			return tmp;
		}
		
		struct node *tmp = find_min(root->right);
		root->num = tmp->num;
		bst_delete(root->right,tmp->num);
	}
	
	return root;
}

int find_next(struct node *root,int key)
{
	if(root == NULL)
		return 0;
	if(root->num == key)
		return find_min(root->right)->num;
	else if(key > root->num)
		return find_next(root->right,key);
	
	int tmp = find_next(root->left,key);
	if(tmp && tmp < root->num)
		return tmp;
	return root->num;
}

void in_order(struct node *root)
{
	if(root != NULL)
	{
		in_order(root->left);
		printf("%d ",root->num);
		in_order(root->right);
	}
}

int main()
{
	struct node *root = NULL;
    root = bst_insert(root, 50);
    root = bst_insert(root, 30);
    root = bst_insert(root, 20);
    root = bst_insert(root, 40);
    root = bst_insert(root, 70);
    root = bst_insert(root, 60);
    root = bst_insert(root, 80);
    
    in_order(root);
    printf("\n");
    
    printf("%d\n",find_next(root,75));
	return 0;
}
