#include <stdio.h>
#include<string.h>
struct student {
    char firstName[50];
    int roll;
    char gender[10];
    int age;
    float marks1;
    float marks2;
    float marks3;
    char grade[10];
} s[100];
void display(struct student s[],int *n)
{
    for(int i=0;i<*n;i++)
    {
        printf("%s\t %d\t %s\t %f\t %f\t %f\t %d\n",s[i].firstName,s[i].age,s[i].gender,s[i].marks1,s[i].marks2,s[i].marks3,s[i].roll);
    }
}
void add(struct student s[],int *n)
{
    int pos;
    printf("enter the pos");
    scanf("%d",&pos);
    for(int i=*n;i>=pos;i--)
    {
        s[i + 1] = s[i];
    }
    (*n)++;
    printf("enter the details of the new student\n");
    scanf("%s %d %s %f %f %f %d ",s[pos].firstName,&s[pos].age,s[pos].gender,&s[pos].marks1,&s[pos].marks2,&s[pos].marks3,&s[pos].roll);
}

void averages(struct student s[],int *n,float average[]) 
{
    for(int i=0;i<*n;i++)
    {   
        if(s[i].marks1 >= 50 && s[i].marks2 >=50 && s[i].marks3 >= 50)
        {
            average[i] = (s[i].marks1+s[i].marks2+s[i].marks3)/3;
            if(average[i] < 50)
            {
                strcpy(s[i].grade,"F");
            }
            else if(average[i] >= 50 && average[i] < 60)
            {
                strcpy(s[i].grade,"B");
            }
            else if(average[i] >= 60 && average[i] < 70)
            {
                strcpy(s[i].grade,"B+");
            }
            else if(average[i] >= 70 && average[i] < 80)
            {
                strcpy(s[i].grade,"A");
            }
            else if(average[i] >= 80 && average[i] < 90)
            {
               strcpy(s[i].grade,"A+");
            }
            else if(average[i] >= 90 && average[i] <= 100)
            {
                strcpy(s[i].grade,"O");
            }
            else
            {
               strcpy(s[i].grade,"S");
            }

        }
        else
        {
            strcpy(s[i].grade,"F");
        } 
    }
}
void disppass(struct student s[],int *n)
{
    for(int i = 0 ; i < *n ; i++)
    {
        if(strcmp(s[i].grade,"F") != 0)
        {
            display(s,n);
        }
        else
        {
            break;
        }
    }
    
}

void dispfail(struct student s[],int *n)
{
    for(int i = 0 ; i < *n ; i++)
    {
        if(strcmp(s[i].grade,"F") == 0)
        {
            display(s,n);
        }
        else
        {
            break;
        }
    }
    
}


void delete(struct student s[],int *n)
{
    int pos;
    printf("enter the pos ");
    scanf("%d",&pos);

    for(int i = pos; i < *n ;i++)
    {
        s[i] = s[i+1];
    }
    (*n)--;
}
int main()
{
    int i;
    int disp;
    printf("Enter information of students:\n");
    int n = 1;
    

    for (i = 0; i < n; ++i) 
    {
        printf("Enter roll no: ");
        scanf("%d",&s[i].roll);
        printf("Enter first name: ");
        scanf("%s", s[i].firstName);
        printf("Enter age: ");
        scanf("%d", &s[i].age);
        printf("Enter gender: ");
        scanf("%s", s[i].gender);  
        printf("Enter mark1: ");
        scanf("%f", &s[i].marks1);
        printf("Enter mark2: ");
        scanf("%f", &s[i].marks2);
        printf("Enter mark3: ");
        scanf("%f", &s[i].marks3);
    }

    int choise;
    choise = 0 ;
    float average[10];

    while(choise != 4)
    {
        choise = 0;
        
        printf("enter your choise\n");
        scanf("%d",&choise);
        
        switch (choise)
        {
        case 1:
            add(s,&n);
            display(s,&n);
            break;
        case 2:
            delete(s,&n);
            display(s,&n);
            break;
        case 3:
            printf("select what to display");
            scanf("%d",&disp);
            switch (disp)
            {
            case 1:
                display(s,&n);
                break;
            case 2:
                averages(s,&n,average);
                disppass(s,&n);
                break;
            case 3:
                averages(s,&n,average);
                dispfail(s,&n);
                break;
            
            default:
                printf("enter the valid choise");
                break;
            }
        break;
        case 4:
            printf("TERMINATED");
            break;
        default:
            printf("enter valid choise\n");
            break;
        }
    }
    return 0;
}
