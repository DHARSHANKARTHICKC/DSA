#include<stdio.h>
#include<stdlib.h>
void insersion(int *arr,int *n,int pos,int data)
{
    for(int i = *n;i >= pos  ; i--)
    {
        *(arr + i ) = *(arr + i - 1 );
    }
    (*n)++;
    *(arr + pos) = data;
     
}
void delete(int *arr,int *n, int pos)
{
    for(int i=pos;i<*n;i++)
    {
        *(arr + i) = *(arr + i +1);
    }
    (*n)--;
}
void traverse(int *arr,int *n)
{
    for(int i=0;i<*n;i++)
    {
        printf("%d",*(arr + i));
    }
    printf("\n");
}
void search(int *arr,int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(*(arr + i) == key)
        {
            printf("The key is found at %d\n",i);
            break;
        }
    }
    
        
}

int main()
{
    
    int operation;
    operation = 0;
     int size;
    printf("Enter the size of array\n");
    scanf("%d",&size);
    int arr[100];
    printf("Enter The Elements Of Array\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    int pos;
    int data;
    int key;
    while(operation != 5)
    {
        operation = 0 ;
    printf("array creation\n");    
    printf("Select The Operation\n 1.Insertion\n 2.Deletion\n 3.Traversion\n 4.Searching \n 5.Exit\n Select Your Option ");
    scanf("%d",&operation);
   
    
    switch (operation)
    {
    case 1:
        
        printf("Enter the value of pos and data\n");
        scanf("%d %d",&pos,&data);
        insersion(arr,&size,pos,data);
        traverse(arr,&size);
        break;
    case 2:
        printf("Enter The pos\n");
        scanf("%d",&pos);
        delete(arr,&size,pos);
        traverse(arr,&size);
        break;
    case 3:
        traverse(arr,&size);
        break;
    case 4:
        printf("Enter the key\n");
        scanf("%d",&key);
        search(arr,size,key);
        break;
    case 5:
        printf("TERMINATED\n");
        break;

    default:
        printf("enter a valid option\n");
    }
    }
    return 0;
}