#include<stdio.h>
#include<stdlib.h>
struct nn{
    int data;
    struct nn *ptr;
};
typedef struct nn n;
struct ss{
    struct nn * top;
};
typedef struct ss s;
#define new (n*)malloc(sizeof(n));
int pop(s* t){
    int ret=-1;
    if(t->top==NULL) return ret;
    else{
        n* temp=t->top;
        ret=temp->data;
        t->top=t->top->ptr;
        free(temp);
    }
    return ret;
}
void push(s* t,int data){
    n * x=new;
    x->data=data;
    x->ptr=NULL;
    if(t->top == NULL){
        t->top=x;
        return;
    }
    x->ptr=t->top;
    t->top=x;
}
int size(s t){
    n *temp;
    temp=t.top;
    int cnt=0;
    while(temp!=NULL){
        cnt+=1;
        temp=temp->ptr;
    }
    return cnt;
}
int main(){
    s t;
    t.top=NULL;
    int n,ans=0,x,i,j,c=0,cnt;
    scanf("%d",&n);
    int ar[n],a[n];
    memset(a,0,sizeof(a));
    scanf("%d",&x);
    ar[0]=x;
    push(&t,x);
    for(i=1;i<n;i++){
        scanf("%d",&x);
        ar[i]=x;
        int cnt=0;
        while(t.top!=NULL){
            if(t.top->data<x){
                if(cnt++!=0)
                ans+=1;
                pop(&t);
            }
            else break;
        }
        push(&t,x);
    }
    while(size(t)) pop(&t);
    push(&t,ar[0]);
    for(i=1;i<n;i++){
        int cnt=0;
        while(t.top!=NULL){
            if(t.top->data<ar[i]){
                if(cnt++!=0)
                ans+=1;
                pop(&t);
            }
            else break;
        }
        push(&t,ar[i]);
    }
    struct nn *temp;
    temp=t.top;
    for(i=0;i<n-1;i++) if(ar[i]!=ar[i+1]) ans+=1;
    for(i=0;i<n;i++){
        cnt=0;
        if(a[i]==0){
            for(j=0;j<n;j++) if(ar[j]==ar[i]){
                cnt+=1;
                a[j]=1;
            }
        }
        ans+=(cnt-1)*(cnt)/2;
    }
    printf("%d",ans);
    return 0;
}
