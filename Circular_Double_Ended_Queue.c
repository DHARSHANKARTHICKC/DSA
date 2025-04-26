#include<stdio.h>
#include<stdbool.h>
#define MAX 5 


bool isfull(int queue[],int f,int r)
{
    if((f == 0 && r == MAX-1) || (r == f-1 ))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isempty(int queue[],int r,int f)
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

void insert_front(int q[],int *f,int *r,int data)
{
    if(isfull(q,*f,*r))
    {
        printf("full");
    }
    else if(*f == -1)
    {
        *f = 0;
        *r = 0;
        q[*f] = data;
    }
    else if(*f == 0)
    {
        *f = MAX - 1;
        q[*f] = data;
    }
    else
    {
        (*f)--;
        q[*f] = data;
    }
} 

void insert_rear(int q[],int *f,int *r,int data)
{
    if(isfull(q,*f,*r))
    {
        printf("full");
    }
    else if(*r == -1)
    {
        *f = 0;
        *r = 0;
        q[*r] = data;
    }
    else if(*r == MAX - 1)
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

int delete_rear(int q[],int *r,int *f)
{
    int result;
    if(isempty(q,*r,*f))
    {
        printf("empty");
    }
    else if(*r == *f)
    {
        result = q[*r];
        *r = -1;
        *f = -1;
    }
    else if(*r == 0)
    {
        result =q[*r];
        *r = MAX - 1;
    }
    else
    {
        result = q[*r];
        (*r)--;
    }
    return result;
}

int delete_front(int q[],int *r,int *f)
{
    int result;
    if(isempty(q,*r,*f))
    {
        printf("empty");
    }
    else if(*r == *f)
    {
        result = q[*f];
        *r = -1;
        *f = -1;
    }
    else if(*f == MAX - 1)
    {
        result =q[*f];
        *f = 0;
    }
    else
    {
        result = q[*f];
        (*f)++;
    }
    return result;
}

void peek_front(int q[],int f,int r)
{
    if(isempty(q,r,f))
    {
        printf("empty");
    }
    else
    {
        printf("%d",q[f]);
    }
    
}
void display(int q[],int f,int r)
{
    if(f <= r)
    {
        for(int i = f;i<=r;i++)
        {
            printf("%d",q[i]);
        }
    }
    else
    {
        for(int i = f;i<MAX;i++)
        {
            printf("%d",q[i]);
        }
        for(int i = 0;i<=r;i++)
        {
            printf("%d",q[i]);
        }
    }
}
int main()
{
    int data;
    int queue[100];
    int choise = 0;
    int front =-1;
    int rear = -1;
    int p;
    while (choise !=7)
    {
        printf("select the choise \n1.insert front \n2.insert rear\n3.delete front \n4.delete rear \n5.5.peekfront \n 6.display\n7.exit\n");
        scanf("%d",&choise);
        switch(choise)
        {
            case 1:
            printf("enter the data");
            scanf("%d",&data);
            insert_front(queue,&front,&rear,data);
            break;
            case 2:
            printf("enter the data");
            scanf("%d",&data);
            insert_rear(queue,&front,&rear,data);
            break;
            case 3:
            p =delete_front(queue,&front,&rear);
            printf("%d",p);
            break;
            case 4:
            p =delete_rear(queue,&front,&rear);
            printf("%d",p);
            break;
            case 5:
            peek_front(queue,front,rear);
            break;
            case 6:
            display(queue,front,rear);
            break;
            case 7:
            break;
            default:
            printf("select valid option");
            break;
        }
    }
    

}
