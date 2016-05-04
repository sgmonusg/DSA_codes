#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main()
{
        int n,m,a,count = 0;
        scanf("%d%d%d",&n,&m,&a);
        if(n%a != 0)
                count+= n/a + 1;
        else
                count+= n/a;
        if((m-1)%a != 0)
                count+= (m-1)/a + 1;
        else
                count+= (m-1)/a;

        printf("%d\n",count);
return 0;
}
