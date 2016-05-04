#include <stdio.h>
#include <stdlib.h>

long long C(int n, int r) {
    if(r > n / 2) r = n - r;
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

int main()
{
    int n;
    int r;
    scanf("%d %d",&n,&r);
    printf("nCr is: %d \n",C(n,r));
    return 0;
}
