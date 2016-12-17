#include<stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *left,*right;
};

struct node *new_node(int k)
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->num = k;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

struct node *insert(struct node *root,int key)
{
	if(root == NULL)
		return new_node(key);
	
	if(key < root->num)
		root->left = insert(root->left,key);
	else
		root->right = insert(root->right,key);
	
	return root;
}

int no_nodes(struct node *root)
{
	if(root == NULL)
		return 0;
	int count = 1;
	count += no_nodes(root->left) + no_nodes(root->right);
	return count;
}

int no_leaves(struct node *root)
{
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return 1;
	int count = no_leaves(root->left) + no_leaves(root->right);
	return count;
}

int height(struct node *root)
{
	if(root == NULL)
		return 0;
	int h1 = height(root->left), h2 = height(root->right);
	return 1 + (h1 > h2 ? h1 : h2);
}

void pre_order(struct node *root)
{
	if(root == NULL)
		return;
	printf("%d ",root->num);
	pre_order(root->left);
	pre_order(root->right);
}

void in_order(struct node *root)
{
	if(root == NULL)
		return;
	in_order(root->left);
	printf("%d ",root->num);
	in_order(root->right);
}

void post_order(struct node *root)
{
	if(root == NULL)
		return;
	post_order(root->left);
	post_order(root->right);
	printf("%d ",root->num);
}

void smaller_equal(struct node *root,int key)
{
	if(root == NULL || root->num > key)
		return;
	
	smaller_equal(root->left,key);
	printf("%d ",root->num);
	smaller_equal(root->right,key);
}

int find_max(struct node *root)
{
	if(root == NULL)
		return 0;
	int m = find_max(root->right);
	return root->num > m ? root->num : m;
}

int find_min(struct node *root)
{
	if(root == NULL)
		return INT_MAX;
	int m = find_min(root->left);
	return root->num < m ? root->num : m;
}

int find_next(struct node *root, int key)
{
	if(root == NULL)
		return 0;
	
	if(key <= root->num)
	{
		if(root->left == NULL || key > root->left->num)
			return root->num;
		return find_next(root->left,key);
	}
	else
	{
		if(key < root->right->num)
			return ;
	}
	
	
	return root->right->num;
}

int main()
{
	struct node *tree = NULL;
	tree = insert(tree,50);
	insert(tree,30);
	insert(tree,20);
	insert(tree,40);
	insert(tree,70);
	insert(tree,60);
	insert(tree,80);
	
	printf("%d\n%d\n%d\n",no_nodes(tree),no_leaves(tree),height(tree));
	
	in_order(tree);
	printf("\n");
	
	smaller_equal(tree,70);
	printf("\n");
	
	printf("%d\n",find_max(tree));
	printf("%d\n",find_min(tree));
	
	printf("\n%d\n",find_next(tree,45));
	
	return 0;
}
