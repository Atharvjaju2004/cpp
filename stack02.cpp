//link list implementation
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
typedef struct stack
{
	NODE *top;
}STK;
void init(STK *t)
{
	t->top=NULL;
}
NODE *createnode(int d)
{
	NODE *a;
	a=(NODE *)malloc(sizeof(NODE));
	a->data=d;
	a->next=NULL;
	return a;
}
void push(STK *t,int d)
{
	NODE *a=createnode(d);
	a->next=t->top;
	t->top=a;
}
void pop(STK *t)
{
	NODE *a=t->top;
	if(t->top==NULL)
	{
		printf("\n underflow");
		return;
	}
	t->top=a->next;
	free(a);
}
void display(STK *t)
{
	NODE *a=t->top;
	if(t->top==NULL)
	{
		printf("\n empty stack");
		return;
	}
	printf("\n stack data\n");
	while(a!=NULL)
	{
		printf("%4d",a->data);
		a=a->next;
	}

}
int main()
{
	int opt,d;
	STK s;
	init(&s);
	while(1)
	{
		printf("\n menu\n1.push\n2pop\n3.display\n4.exit\noption");
		scanf("%d",&opt);
		if(opt>4)
			break;
		switch(opt)
		{
			case 1:
				printf("\n enter data");
				scanf("%d",&d);
				push(&s,d);
				break;
			case 2:
				pop(&s);
				break;
			case 3:
				display(&s);
				break;
			
		}
	}
	return 0;
}
