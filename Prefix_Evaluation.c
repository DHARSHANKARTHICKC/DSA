#include<stdio.h>
#include <stdbool.h>
#include<string.h>
#include<ctype.h>
#include<math.h>


bool isfull(float s[],int *top,int max)
{
    if(*top == max-1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool isempty(float s[],int *top)
{
    if(*top == -1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void push(float s[],int *top,int max,int x)
{
    if(!isfull(s,top,max))
    {
        (*top)++;
        s[*top] = x;
    }
    
}

int pop(float s[],int *top)
{
    if(!isempty(s,top))
    {
        char temp = s[*top];
        (*top)--;
        return temp;
    }
}
int isoperator(char s)
{
    if(s == '+' || s == '-' || s == '/' || s == '*' || s == '$')
        return 1;
}
float evaluation(int o1,int o2,char op)
{
    switch (op)
    {                                   
    case '+':
        return o1 + o2;
        break;
    case '-':
        return o1 - o2;
        break;
    case '*':
        return o1 * o2;
        break;
    case '/':
        return o1 / o2;
        break;
    case '$':
        return pow(o1,o2);
        break;
    default:
        break;
    }
}
float number(char a)
{
    return (float)(a-48);
}

float prefix_eval(char e[])
{
    int top = -1;
    float s[100];
    int max = 100;
    for(int i= strlen(e);i>=0;i--)
    {
        if(isdigit(e[i]))
        {
            push(s,&top,max,number(e[i]));
        }
        else if(isoperator(e[i]))
        {
            int o1 = pop(s,&top);
            int o2 = pop(s,&top);
            int r = evaluation(o1,o2,e[i]);
            push(s,&top,max,r);
        }
    }
    return pop(s,&top);
}

int main()
{
    char exp[100];
    printf("enter the expression");
    scanf("%s",exp);
    int result = prefix_eval(exp);
    printf("%d",result);
    return 0;
}
