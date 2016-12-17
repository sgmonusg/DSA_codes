#include<stdio.h>
#include<string.h>
typedef char string[101];

string dict[1000];
int n;

void build_dictionary()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;++i)
		scanf(" %s",dict[i]);
	
	qsort(dict,n,sizeof(string),strcmp);
	
	for(i=0;i<n;++i)
		printf("%s\n",dict[i]);
}
int common_prefix_len(string s1,string s2)
{
	int i,j,l1=strlen(s1),l2=strlen(s2);
	
	for(i=0;i<l1 && i<l2;++i)
	{
		if(s1[i] != s2[i])
			break;
	}
	for(j=0;j<i;++j)
		printf("%c",s1[i]);
	printf("\n");
	return i;
}

int* longest_prefix_util(int s,int e,string k)
{
	if(s > e)
	{
		int arr[]={0,n};
		return arr;
	}
	if(s == e)
	{
		int arr[]={common_prefix_len(dict[mid],k),s};
		return arr;
	}
	int mid=(s+e)/2;
	if(longest_prefix_util(s,mid-1,k)[0] > longest_prefix_util(mid+1,e,k)[0])
	{
		
	}
}
int longest_prefix(string k)
{
	int ind=longest_prefix_util(0,n-1,k);
	return common_prefix_len(dict[ind],k);
}

int main()
{
	build_dictionary();
	string k;
	scanf(" %s",k);
	longest_prefix(k);
	return 0;
}
