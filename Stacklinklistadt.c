#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
	void* dp;
	struct node *next;
}NODE;
typedef struct stack
{
	NODE* top;
	int count;
}STACK;


STACK* createstack()
{
	STACK* s;
	s=(STACK*)malloc(sizeof(STACK));
	if(s)
	{
		s->top=NULL;
		s->count=0;
	}
	return s;
}

bool pushstack(STACK* h,void* din)
{
	NODE* pnew;
	pnew=(NODE*)malloc(sizeof(NODE));
	if(pnew)
	{
		pnew->dp=din;
		pnew->next=h->top;
		h->top=pnew;
		h->count++;
		return true;
	}
	return false;
}

void* popstack(STACK* h)
{
	void* dout;
	NODE* deletnode;
	if(!h->count)
	 return NULL;
	deletnode=h->top;
	h->top=deletnode->next;
	dout=deletnode->dp;
	h->count--;
	free(deletnode);
	return dout; 
}

void* stacktop(STACK* h)
{
	if(!h->count)
	 return NULL;
	return(h->top->dp);
}

bool emptystack(STACK* h)
{
	if(!h->count)
	 return true;
	return false;
}

bool stackfull(STACK* h)
{
	NODE* t;
	t=(NODE*)malloc(sizeof(NODE));
	if(t)
	{
		printf("Stack is not full\n");
		return false;
	}
	return true;
}

int stackcount(STACK* h)
{
	return(h->count);
}

void displaystack(STACK* h,void (*fp)(void*))
{
	NODE* temp;
	for(temp=h->top; temp!=0; temp=temp->next)
	{
	fp(temp->dp);
    }
}

bool destroystack(STACK*h)
{
	void*dpout;
	NODE*temp,*deletnode;
	if(!h)
	return(false);
	for(temp=h->top;temp!=NULL;)
	{
		deletnode=temp;
		temp=temp->next;
		dpout=deletnode->dp;
		free(dpout);
		free(deletnode);
	}
	free(h);
	return(true);
}

void printdata(void *dp)
{
	printf("%d\n",*(int*)dp);
}
int main()
{
	int*dp,choice;
	STACK*head;
	bool result;
	head=createstack();
if(!head)
{
	printf("Stack creation faild\n");
	return(1);
}
printf("Stack created sucessfully\n");
while(1)
{
	printf("1-push\n 2-pop\n 3-stacktop\n 4-Emptystack\n 5-Stackfull\n 6-Stackcount\n 7-Displaystack\n 8-Exit\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			dp=(int*)malloc(sizeof(int));
			printf("Enter integer element to be pushed\n");
			scanf("%d",dp);
			result=pushstack(head,dp);
			result==0?printf("Failed\n"):printf("Sucessful\n");
			break;
		case 2:
		    dp=(int*)popstack(head);
			if(dp)
			{
				printf("Popped element=%d\n",*dp);
				free(dp);	
			}
			else
			printf("Stack is empty\n");
			break;
		case 3:
		    dp=(int*)stacktop(head);
			if(dp)
			printf("Stack top=%d\n",*dp);
			else
			printf("Stack is empty\n");
			break;
		case 4:
		    if(emptystack(head))
			printf("Stack is empty\n");
			else
			printf("Stack is not empty\n");
			break;
		case 5:
		    if(stackfull(head))
			printf("Stack is full\n");
			else
			printf("Stack is not full\n");
			break;
		case 6:
		    printf("Stack count=%d\n",stackcount(head));
			break;
		case 7:
		    if(emptystack(head))
			printf("Stack is empty\n");
			else
			{
				printf("Stack contents are\n");
				displaystack(head,printdata);				
			}
			break;
		case 8:
		    if(destroystack(head))
			printf("Stack is destroyed sucessfully\n");
			else
			printf("stackack does not exist\n");
			return(1);
		default:
		    printf("Invalid choice");					
	}
  }
}

