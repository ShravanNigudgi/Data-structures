#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack_array
{
	void **st;
	int count;
	int size;
	int top;
}AST;

AST* createstack()
{
	AST* h;
	h=(AST*)malloc(sizeof(AST));
	if(h)
	{
		printf("Enter the size of the array\n");
		scanf("%d",&h->size);
		
	     h->st=(void**)calloc(h->size,sizeof(void*));
		if(h->st)
		{
			h->top=-1;
			h->count=0;
		}
		else
		{
			free(h);
			return NULL;
		}
	}
	return h;
}

bool pushstack(AST* head,void* din)
{
	if(head->top == head->size)
	 return false;
	 else
	 {
	 	head->top++;
	    head->st[head->top]=din;
	    head->count++;
	    return true;
	 }

}

void* popstack(AST* head)
{
	void* dout;
	if(head->top==-1)
	 return NULL;
	dout=head->st[head->top];
	head->top--;
	head->count--;
	return dout;
}

void* stacktop(AST* head)
{
	if(head->top==-1)
	 return NULL;
	return(head->st[head->top]);
}

bool emptystack(AST* head)
{
	if(head->top==-1)
	 return true;
	return false;
}

bool fullstack(AST* head)
{
	if(head->size == head->top)
	 return true;
	return false;
}

void displaystack(AST* head,void(*stackprint)(void*))
{
	int i;
	if(emptystack(head))
	 return;
	else
	{
		for(i=head->top ; i>=0 ; i--)
		 stackprint(head->st[i]);
	}
}

int stackcount(AST* head)
{
	return(head->count);
}

bool destroystack(AST* head)
{
	int i;
	if(head)
	{
		for(i=head->top;i>=0;i--)
		{
			free(head->st[i]);
		}
		free(head);
		return true;
	}
	return false;
}


typedef struct student
{
    char usn[11],name[25],dept[6];
    int roll_no,sem;

}STUD;

void printstud(void *s)
{
    STUD *temp;
    if(s)
    {
    temp=(STUD*)s;
    printf("name:%s\n",temp->name);
    printf("usn:%s\n",temp->usn);
    printf("department:%s\n",temp->dept);
    printf("roll no:%d\n",temp->roll_no);
    printf("usn:%d\n",temp->sem);
    } 
}

int main()
{
    STUD *s;
    AST *ph;
    int ch;
   
    ph=(AST*)createstack();
    if(ph)
        printf("Stack created \n");
    else
        printf("Creation failed \n");
    printf("stack of students using array stack adt\n");

    while(1)
    {
    
        printf("enter choice:1 for push\n 2 to to pop\n 3 to check stack top\n 4 to display stack\n 5 to stack empty\n 6 to stackfull\n 7 to count\n 8 to destroy stack\n");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
            s=(STUD*)malloc(sizeof(STUD));
            if(s)
            {
                printf("enter student details:");
                printf("name, usn, department, rollno and semester respectively\n");
                printf("\nEnter name of the student:");
                scanf("%s",s->name);
                printf("Enter usn of the student\n");
                scanf("%s",s->usn);
                printf("Enter department of student\n");
                scanf("%s",s->dept);
                printf("Enter rollno of student\n");
                scanf("%d",&s->roll_no);
                printf("Enter semester of the students\n");
                scanf("%d",&s->sem);

                if(pushstack(ph,s))
                  printf("student pushed successfully\n");
                else
                {
                	printf("Push failed");
                	free(s);
				}
            }
            else
            {
            	printf("Stack is full\n");
			}
            break;

            case 2:
            s=(STUD*)popstack(ph);
            if(s)
            {
                printstud(s);
            }
            else
             printf("stack is empty\n");
            break;

            case 3:
            s=(STUD*)stacktop(ph);
            if(s)
            {
                printstud(s);
            }
            else 
             printf("stack is empty\n");
            break;

            case 4:
            displaystack(ph,printstud);
            break;

            case 5:
            if(emptystack(ph))
             printf("stack is empty\n");
            else 
             printf("stack is not empty\n");
            break;

            case 6:
            if(fullstack(ph))
             printf("stack is full\n");
            else 
             printf("stack is not full\n");
            break;

            case 7:
            printf("stack count=%d\n",stackcount(ph));
            break;
            
            case 8:
            if(destroystack(ph))
             printf("successfull\n");
            else
             printf("unsuccessfull\n");
            return(1);

            default:printf("invalid choice\n");
        }
    }
    return 0;   
}
