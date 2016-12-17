#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert_element(struct node **head,int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node ));
    temp->data=data;
    temp->next=*head;
    *head=temp;
}

int search(struct node *head,int data){
    int temp=0;
    while(head!=NULL){
        if(head->data==data){
            temp=1;
            return 1;
        }
        else{
            head=head->next;
        }
    }
    if(temp==0){
        return 0;
    }
}
void print_element(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){
    struct node *head=NULL;
    struct node *head1=NULL;
    int n;
    scanf("%d",&n);
    int i=0;
    for(i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        insert_element(&head,a);
        if(search(head1,a)==0){
            insert_element(&head1,a);
        }
    }
    print_element(head);
    print_element(head1);
}
