#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node *add_element_in_begining(struct node *head,int data){

        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        printf("temp =%d\n",temp->data);
        temp->next=head;
        head=temp;
        return head;
}

struct node *add_element_in_end(struct node *head,int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    struct node *temp1=(struct node *)malloc(sizeof(struct node));
    temp1=head;
    while(temp1!=NULL){
        temp1=temp1->next;
    }
    temp1=temp;
    return head;

}
void print_list(struct node *head){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
}
//void add_element_at_a_postion{
  //  struct node
//}
int main(){
    struct node *head=NULL;
    int data;
    int i=0;
    for(i=0;i<5;i++){
    scanf("%d",&data);
    head=add_element_in_begining(head,data);
    }
    print_list(head);


return 0;
}
