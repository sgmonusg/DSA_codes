#include<stdio.h>
struct node {
    int data;
    struct node *next;
};
struct node *insert_element(struct node *head,int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=head;
    temp=head;
}

struct node *delete_element_begining(struct node *head){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp=head->next;
    head->next=NULL;
    head=temp;

}

int main(){

}
