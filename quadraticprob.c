#include<stdio.h>
#define SIZE 10
#define EMPTY -1
int c1=1;
int c2=3;
int hash(int key)
{
	return key % SIZE;
}
void insertQuadratic(int table[],int key)
{
	int index=hash(key);
	int i=0;
	while(i<SIZE)
	{
		int newindex=(index+c1*i+c2*i*i)%SIZE;
		if(table[newindex]==EMPTY)
		{
			table[newindex]=key;
			return;
		}
		i++;
	}
	printf("Table Overflow!Cannot insert %d\n",key);
}
int main()
{
	int table[SIZE];
	int i;
	for(i=0;i<SIZE;i++)
	{
		table[i]=EMPTY;
	}
	int keys[]={72,27,36,24,63,81,101};
	int n=8;
	printf("Inserting using quadreatic probing...\n");
	for(i=0;i<n;i++)
	{
		insertQuadratic(table,keys[i]);
	}
	printf("\nHash Table:\n");
	for(i=0;i<SIZE;i++)
	{
		printf("Index %d:%d\n",i,table[i]);
	}
	return 0;
}
