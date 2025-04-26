#include<stdio.h>
#include<stdbool.h>


bool isfull(int q[], int r,int f,int max)
{
    if((r == max-1 && f == 0) || (r == f-1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isempty(int q[],int f)
{
    if(f == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void display(int q[],int f,int r,int max)
{
    
    if(!isempty(q,f))
    {
        if(f <= r)
        {
            for(int i = f ;i <r;i++)
            {
                printf("%d",q[i]);
            }
        }
        else
        {
            for(int i = f;i < max-1;i++ )
            {
                printf("%d",q[i]);
            }
            for(int i = 0 ; i <= r;i++)
            {
                printf("%d",q[i]);
            }
        }
    }
    else
    {
        printf("empty");
    }
}

void enqueue(int q[],int *f,int *r,int max)
{
    if(isfull(q,*r,*f,max))
    {
        printf("queue is full");
    }
    else 
    {
        int data = 0; 
        printf("enter the element");
        scanf("%d",&data);
        if(*r == -1)
        {
            *r=0;
            *f=0;
            q[*r] = data;
        }
        else if(*r == max -1)
        {
            *r = 0;
            q[*r] = data;
        }
        else
        
        {
            (*r)++;
            q[*r] = data;
        }
    }
}
int dequeue(int q[],int *f,int *r,int max)
{
    int a = 0;
    if(isempty(q,*f))
    {
        printf("queue is empty");
    }
    else if(*r == *f)
    {   
        a = q[*f]; 
        *r = -1;
        *f = -1;
        return a;
    }
    else if(*f == max-1)
    {
        a = q[*f];
        *f = 0;
        return a;
    }
    else
    {
        a = q[*f];
        (*f)++;
        return a;
    }
}
void peekfront(int q[],int f)
{
    if(isempty(q,f))
    {
        printf("queue is empty");
    }
    else
    {
        printf("%d",q[f]);
    }
}
int main()
{
    int front = -1;
    int rear =-1;
    int q[10];
    int max =5;
    int choise =0 ;
    int a;
    while(choise != 5)
    {

        choise = 0;
        printf("enter your choice\n 1.Enqueue \n 2.Dequeue \n 3.Peekfront \n 4.Display \n 5.Exit\n");
        scanf("%d",&choise);
        switch (choise)
        {
        case 1:    
            enqueue(q,&front,&rear,max);
            break;
        case 2:
            a = dequeue(q,&front,&rear,max);
            printf("%d",a);
            break;
        case 3:
            peekfront(q,front);
            break;
        case 4:
            display(q,front,rear,max);
            break;
        case 5:
            printf("...TERMINATED...\n");
            break;
        default:
            printf("enter the valid choise");
            break;
        }
        printf("\n");     
    }

}
