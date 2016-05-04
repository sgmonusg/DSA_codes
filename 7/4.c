#include<stdio.h>
#include<stdlib.h>
struct node{
    int a;
    struct node *prev;
    struct node *next;
};
void insert_begin(struct node **head,struct node **tail,int data){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->a=data;
    if(*head==NULL){
        *head=temp;
        *tail=temp;
        temp->next=temp;
        temp->prev=temp;
    }
    else{
        (*head)->prev=temp;
        (*tail)->next=temp;
        temp->next=*head;
        temp->prev=*tail;
        *head=temp;
    }
}
void insert_end(struct node **head,struct node**tail,int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->a=data;
    if(tail==NULL){
        *head=temp;
        *tail=temp;
        temp->next=temp;
        temp->prev=temp;
    }
    else{
        (*tail)->next=temp;
        (*head)->prev=temp;
        temp->next=*head;
        temp->prev=*tail;
        *tail=temp;
    }
}
void insert_middle(struct node **head,struct node **tail,int position,int data){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *current=*head;
    while(position!=0){
            current=current->next;
    }
    struct node* current1=current->next;
    current->next=temp;
    temp->prev=current;
    temp->next=current1;
    current1->prev=temp;
}
void print_list(struct node*head,struct node*tail){
    while(head!=tail){
        printf("%d ",head->a);
        head=head->next;
    }
    printf("%d",tail->a);
    printf("\n");
}
void menu(){
    printf("********************************************************************\n");
    printf("PRESS 1 to add in beginning \n");
    printf("press 2 to add in last\n");
    printf("press 3 to add in middle\n");
    printf("press 4 to print the list\n");
    printf("**********************************************************************\n");
}

int main(){
    int a=1;
    struct node *head=NULL;
    struct node *tail=NULL;
while(a){
    menu();
    scanf("%d",&a);
    if(a==1){
        int data;
        scanf("%d",&data);
        insert_begin(&head,&tail,data);

    }
    if(a==2){
        int data;
        scanf("%d",&data);
        insert_end(&head,&tail,data);
    }
    else if(a==4){
        print_list(head,tail);
    }
}

return 0;
}
