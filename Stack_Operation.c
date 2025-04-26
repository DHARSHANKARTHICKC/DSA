#include <stdio.h>
#include <stdbool.h>


bool isfull(char s[],int *top,int max)
{
    if(*top == max-1)
    {
        return false;
    }
    else 
    {
        return true;
    }
}

bool isempty(char s[],int *top)
{
    if(*top == -1)
    {
        return false;
    }
    else 
    {
        return true;
    }
}

void push(char s[],int *top,int max,int x)
{
    if(isfull(s,top,max))
    {
        (*top)++;
        s[*top] = x;
    }
    
}

char pop(char s[],int *top,int max)
{
    if(isempty(s,top))
    {
        char temp = s[*top];
        (*top)--;
        return temp;
    }
}

char peektop(char s[],int *top)
{
    if(isempty(s,top))
    {
        return s[*top];
    }
}

int main()
{
    int choise = 0;
    int data;
    int max = 99;
    int top = -1;
    char s[100];
    char p;

    while(choise != 5)
    {

        choise = 0;
        printf("\n1.push\n2.pop\n3.peektop\n4.display\n5.exit");
        printf("\nenter the choise:");
        scanf("%d",&choise);
        switch (choise)
        {
        case 1:
        printf("enter the data:");
            do
            {
                data = getchar();
            }
            while (data == '\0' || data == '\n');    
            push(s,&top,max,data);
            printf("successfully pushed\n");
            break;
        case 2:
            data = pop(s,&top,max);
            if(data != '\0')
            {
                printf("the poped element is %c\n",data);
            }
            if(isempty(s,&top))
            {
                printf("stack is empty\n");
            }
            break;
        case 3:
            p = peektop(s,&top);
            printf("%c\n",p);
            break;
        case 4:
            for(int i = 0;i <= top;i++)
                printf("%c\t",s[i]);
            break;  
        case 5:
            printf("TERMINATED\n");
            break;
        default:
            printf("enter the valid choise");
            break;
        }
        printf("\n");     
    }
}
