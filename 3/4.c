#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int* p,*q;

    int n,i,j,k,num=1,sq,flag=0,l,m=0;

    float x;

    scanf("%d",&n);

    x=pow(n,2);//this is very important. If you try directly storing into int, for n=5 and n=10, it wont work

    sq=(int)x;

    k=n;

    p=(int*)malloc(sizeof(int)*sq);

    while(1)
    {
        j=n-k;
        l=n-k;

        for(i=l;i<k;i++)
        {
            *(p+i+(j*n))=num;
            num++;

            if(num>sq)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
            break;

        i--;j++;

        for(;j<k;j++)
        {
            *(p+i+(j*n))=num;
            num++;

            if(num>sq)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
            break;

        j--;i--;

        for(;i>=l;i--)
        {
            *(p+i+(j*n))=num;
            num++;

            if(num>sq)
            {
                flag=1;
                break;
            }
        }
        i++;j--;

        if(flag==1)
            break;

        for(;j>l;j--)
        {
            *(p+i+(j*n))=num;
            num++;

            if(num>sq)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
            break;

        k--;
    }

    i=0;

    for(m=0;m<sq;m++)
    {
        printf("%d ",*(p+m));
        i++;

        if(i==n)
        {
            printf("\n");
            i=0;
        }
    }
}
