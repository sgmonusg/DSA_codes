#include<stdio.h>
#include<stdlib.h>

#define size 10
int table[size] = {0};

int hash(int k)
{
	return k%size;
}
int probe(int k,int i)
{
	return (hash(k)+i)%size;
}

void hash_insert(int k)
{
	int i;
	for(i=0;i<size;++i)
	if(table[probe(k,i)] <= 0)
	{
		table[probe(k,i)] = k;
		return;
	}
	
	printf("Hash Table is Filled!\n");
	return;
}

void hash_print()
{
	int i;
	for(i=0;i<size;++i)
		printf("%d ",table[i]);
	printf("\n");
}

int hash_search(int k)
{
	int i;
	for(i=0;i<size;++i)
	{
		if(table[probe(k,i)] == k)
			return 1;
		if(table[probe(k,i)] == 0)
			return 0;
	}
	return 0;
}

void hash_delete_lazy(int k)
{
	int i;
	for(i=0;i<size;++i)
	{
		if(table[probe(k,i)] == k)
		{
			table[probe(k,i)] = -1;
		}
		if(table[probe(k,i)] <= 0)
			return;
	}
}

int main()
{
	return 0;
}
