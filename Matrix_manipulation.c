#include<stdio.h>
#include<stdlib.h>

void twoallocate(int m,int n,int **ptr1,int **ptr2)
{
    for(int i=0;i<m;i++)
    {
        ptr1[i] = (int *) malloc(sizeof(int) * n);
        ptr2[i] = (int *) malloc(sizeof(int) * n);
    }
   
}
void oneallocate(int m,int n,int **ptr1)
{
    for(int i=0;i<m;i++)
    {
        ptr1[i] = (int *) malloc(sizeof(int) * n);
    }   
}
void add(int m, int n,int **ptr1,int **ptr2)
{
   for(int i=0;i<m;i++)
    {
        for(int j=0 ;j<n; j++)
        {
            printf("%d\t", ptr1[i][j] + ptr2[i][j]);
        }
        printf("\n");
    }
}
void sub(int m, int n,int **ptr1,int **ptr2)
{
   for(int i=0;i<m;i++)
    {
        for(int j=0 ;j<n; j++)
        {
            printf("%d\t", ptr1[i][j] - ptr2[i][j]);
        }
        printf("\n");
    }
}
void mul(int m, int n,int m1,int n1,int **ptr1,int **ptr2)
{
    int **result = malloc(sizeof(int *) * n1);
    oneallocate(m1,n,result);
        for(int i=0;i<m;i++)
        {
           for(int j=0 ;j<n; j++)
           {
                for(int k=0;k<n1;k++)
                {
                    result[i][j] += ptr1[i][k] * ptr2[k][j];
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n1;j++)
            {
                printf("%d\t",result[i][j]);
            }
            printf("\n");
        }
}
void transpose(int m,int n,int **ptr1)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d\t",ptr1[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    
    int m;
    int n;
    int m1;
    int n1;
    int choise;

    while(choise != 5)
    {
        choise =0;
        printf("select the choise");
        scanf("%d",&choise);
        
        int **ptr1; 
        int **ptr2;
            

        switch(choise)
        {
            case 1:
                printf("enter the value of m");
                scanf("%d",&m);
                printf("enter the value of n");
                scanf("%d",&n);
                ptr1 = malloc(sizeof(int *) * m);
                ptr2  = malloc(sizeof(int *) * m);
                twoallocate(m,n,ptr1,ptr2);
                printf("enter the elements of matrix A");
                for(int i=0;i<m;i++)
                {
                    for(int j=0 ;j<n; j++)
                    {
                        scanf("%d",&ptr1[i][j]);
                    }
                }
                printf("enter the elements of matrix B");
                for(int i=0;i<m;i++)
                {
                    for(int j=0 ;j<n; j++)
                    {
                        scanf("%d",&ptr2[i][j]);
                    }
                }
                add(m,n,ptr1,ptr2);
                break;
            case 2:
                printf("enter the value of m");
                scanf("%d",&m);
                printf("enter the value of n");
                scanf("%d",&n);
                ptr1 = (int **)malloc(sizeof(int *) * m);
                ptr2  = (int **)malloc(sizeof(int *) * m);
                twoallocate(m,n,ptr1,ptr2);
                printf("enter the elements of matrix A");
                for(int i=0;i<m;i++)
                {
                    for(int j=0 ;j<n; j++)
                    {
                        scanf("%d",&ptr1[i][j]);
                    }
                }
                printf("enter the elements of matrix B");
                for(int i=0;i<m;i++)
                {
                    for(int j=0 ;j<n; j++)
                    {
                        scanf("%d",&ptr2[i][j]);
                    }
                }
                sub(m,n,ptr1,ptr2);
                break;
            case 3:
                printf("enter the value of m");
                scanf("%d",&m);
                printf("enter the value of n");
                scanf("%d",&n);
                ptr1 = (int **)malloc(sizeof(int *) * m);
                oneallocate(m,n,ptr1);
                printf("enter the elements of matrix A");
                for(int i=0;i<m;i++)
                {
                    for(int j=0 ;j<n; j++)
                    {
                        scanf("%d",&ptr1[i][j]);
                    }
                }
                transpose(m,n,ptr1);
                break;
            case 4:
                printf("enter the value of m");
                scanf("%d",&m);
                printf("enter the value of n");
                scanf("%d",&n);
                printf("enter the value of m1");
                scanf("%d",&m1);
                printf("enter the value of n1");
                scanf("%d",&n1);
                ptr1 = (int **)malloc(sizeof(int *) * m);
                ptr2  = (int **)malloc(sizeof(int *) * m1);
                oneallocate(m,n,ptr1);
                oneallocate(m1,n1,ptr2);
                printf("enter the elements of matrix A");
                for(int i=0;i<m;i++)
                {
                    for(int j=0 ;j<n; j++)
                    {
                        scanf("%d",&ptr1[i][j]);
                    }
                }
                printf("enter the elements of matrix B");
                for(int i=0;i<m1;i++)
                {
                    for(int j=0 ;j<n1; j++)
                    {
                        scanf("%d",&ptr2[i][j]);
                    }
                }
                
                if(n != m1)
                {
                    printf("try again");
                    break;
                }
                else
                {
                    mul(m,n,m1,n1,ptr1,ptr2);
                }
                break;

        }
    }
}
