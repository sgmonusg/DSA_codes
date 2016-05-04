#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
void insert_begin(struct node **head,struct node **tail ,int data){
     struct node *temp =(struct node*)malloc(sizeof(struct node));
     temp->data=data;
     if(*head=NULL){
        *head=temp;
        *tail=temp;
        temp->next=NULL;
        temp->prev=NULL;
     }
     else{
        temp->next=*head;
        (*head)->prev=temp;
        temp->prev=NULL;
        *head=temp;
     }
}
void insert_end(struct node **head,struct node **tail,int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    if(tail=NULL){
        *head=temp;
        *tail=temp;
        temp->next=NULL;
        temp->next=NULL;
    }
    else{
        temp->prev=*tail;
        (*tail)->next=temp;
        temp->next=NULL;
        *tail=temp;
    }
}
void reverse_list(struct node **head,struct node **tail){

}
void print_list(struct node*head,struct node*tail){
    while(head!=tail){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("%d ",tail->data);
    printf("\n");
}
void menu(){
    printf("********************************************************************\n");
    printf("PRESS 1 to add in beginning \n");
    printf("press 2 to add in last\n");
    printf("press 3 to reverse the list\n");
    printf("press 4 to print the list\n");
    printf("**********************************************************************\n");
}

int main(){
    struct node *head=NULL;
    struct node *tail=NULL;
    int a=1;
    while(a){
            menu();
            scanf("%d",&a);
        if(a==1){
            int data;
            scanf("%d",&data);
            insert_begin(&head,&tail,data);
        }
        else if(a==2){
            int data;
            scanf("%d",&data);
            insert_end(&head,&tail,data);
        }
        else if(a==3){
            reverse_list(&head,&tail);
        }
        else if(a==4){
            print_list(head,tail);
        }
        else{
            return 0;
        }

    }
    return 0;
}
