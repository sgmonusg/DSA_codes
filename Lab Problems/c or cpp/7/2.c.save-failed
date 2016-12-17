#include<stdio.h>
struct node{
    int a;
    struct node *next;
};
struct node * swap(struct node *head){
    if(head=NULL||head->next==NULL){
        return head;
    }
    else{
        struct node *temp;
        temp=head;
        head=head->next;
        head->next=temp;
        temp->next=head->next->next
        head->next->next=swap(head->next->next);
        return head;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    struct node *a;
    for(i=0;i<n;i++){
        insert_element(a);
    }
    return 0;
}
