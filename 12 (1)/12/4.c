#include <stdio.h>
#include <stdlib.h>
enum colour{Black,Red};
struct nod{
    int x;
    struct nod *left,*right,*parent;
    enum colour c;
};
typedef struct nod node;
node sentinel;
node *head=&sentinel;
node* createNode(int x)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->x=x;
    temp->left=&sentinel;
    temp->right=&sentinel;
    temp->parent=NULL;
    temp->c=Red;
    return temp;
}
void leftRotate(node *x)
{

    node *y=x->right;
    x->right=y->left;
    if (y->left!=&sentinel)
    {
        y->left->parent=x;
    }
    y->parent=x->parent;
    if (x->parent==&sentinel)
    {
        head=y;
    }
    else if (x==x->parent->left)
    {
        x->parent->left=y;
    }
    else
    {
        x->parent->right=y;
    }
    y->left=x;
    x->parent=y;
}
void rightRotate(node *x)
{

    node *y=x->left;
    x->left=y->right;
    if (y->right!=&sentinel)
    {
        y->right->parent=x;
    }
    y->parent=x->parent;
    if (x->parent==&sentinel)
    {
        head=y;
    }
    else if (x==x->parent->left)
    {
        x->parent->left=y;
    }
    else if (x==x->parent->right)
    {
        x->parent->right=y;
    }
    y->right=x;
    x->parent=y;
}
void fixColour(node *z)
{
    while(z->parent->c==Red)
    {
        if(z->parent==z->parent->parent->left)
        {
            node *y=z->parent->parent->right; //y is uncle
            if (y->c==Red)
            {
                z->parent->c=Black;
                y->c=Black;
                z->parent->parent->c=Red;
                z=z->parent->parent;
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
        else
        {
            node *y=z->parent->parent->left;
            if (y->c==Red)
            {
                z->parent->c=Black;
                y->c=Black;
                z->parent->parent->c=Red;
                z=z->parent->parent;
            }
            else
            {
                if(z==z->parent->left)
                {
                    z=z->parent;
                    rightRotate(z);
                }
                z->parent->c=Black;
                z->parent->parent->c=Red;
                leftRotate((z->parent->parent));
            }
        }
    }
    head->c=Black;
}
void insert(node *temp)
{
    node *traverse=head;
    node *y=&sentinel;
    while(traverse!=&sentinel)
    {
        y=traverse;
        if (temp->x < traverse->x )
        {
            traverse=traverse->left;
        }
        else
            traverse=traverse->right;
    }
    temp->parent=y;
    if(y==&sentinel)
    {
        head=temp;
    }
    else if(temp->x < y->x)
    {
        y->left=temp;
    }
    else y->right=temp;
    fixColour(temp);
}
void performInorder(node *head)
{
    if(head==&sentinel)
        return;
    else
    {
        performInorder(head->left);
        printf("%d ",head->x);
        performInorder(head->right);
    }
}
int main()
{
    sentinel.left=NULL;
    sentinel.right=NULL;
    sentinel.parent=NULL;
    sentinel.c=Black;
    char c;
    do{
        scanf(" %c",&c);
        int x;scanf("%d",&x);
        insert(createNode(x));
        performInorder(head);
        printf("\n");
    }while(c!='q');
}
