##include<stdio.h>
typedef struct {
	char bname[100];
	char author[100];
	int edition,price,publication;
	long long isbn;
}Book;
int book_cmp(Book &a, Book &b)
{
	return (a.price < b.price) ? 1 : 0;
}

void merge_sort(Book list[],int s, int e)
{
	if(s == e)
		return;
	Book tmp1[mid-s],tmp2[e-mid];
	
	int i,j,k,mid=(s+e)/2;
	for(i=s;i<mid;++i)
		tmp1[i-s] = list[i];
	for(i=mid;i<e;++i)
		tmp2[i-mid] = list[i];
	
	merge_sort(tmp1,0,mid);
	merge_sort(tmp2,mid,e);
	
	for(i=0,j=0,k=0;i<mid && j<n-mid;)
	{
		if(cmp(tmp1[i],tmp2[j]))
		{
			list[k++] = tmp1[i++];
		}
		else
		{
			list[k++] = tmp[j++];
		}
	}
	if(i == mid)
		while(j < n-mid)
			list[k++] = tmp2[j++];
	else
		while(i < mid)
			list[k++] = tmp1[i++];
}

int main()
{
	return 0;
}
