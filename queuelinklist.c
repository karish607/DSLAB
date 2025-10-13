#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
struct N
{
	int data;
	struct N*next;
};
struct N*f=NULL,*r=NULL,*temp,*n;
void main()
{
	int ch;
	while(1)
	{
		printf("1.enqueue 2.dequeue 3.display 4.exit");
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enqueue();
			break;
			case 2: dequeue();
			break;
			case 3: display();
			break;
			case 4: exit(1);
		}
	}
}
void enqueue()
{
	n=(struct N*)malloc(sizeof(struct N));
	printf("Enter the element\n");
	scanf("%d",&n->data);
	n->next=NULL;
	if(r==NULL)
	{
		f=n;
		r=n;
	}
	else
	{
		r->next=n;
		r=n;
	}
}
void dequeue()
{
	if(f==NULL)
	{
		printf("under flow");
	}
	else
	{
		temp=f;
		if(f==r)
		{
			f=NULL;
			r=NULL;
		}
		else
		{
			f=f->next;
		}
		free(temp);
	}
}
void display()
{
	if(f==NULL||r==NULL)
	{
		printf("queue is empty");
	}
	else
	{
		temp=f;
		while(temp!=NULL)
		{
			printf("%d",temp->data);
			temp=temp->next;
		}
	}
}
