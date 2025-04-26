#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node * next;
}node;

node* getnode()
{
    return (node*)malloc(sizeof(node));
}

void push(node **top,int data)
{
    node * p = getnode();
    p ->data =data;
    p->next = *top;
    *top = p;
}

int pop(node **top)
{
    if(*top == NULL)
    {
        printf("empty");
        return -1;
    }
    else
    {
        int t = (*top) -> data;
        node * temp = *top;
        *top = temp ->next;
        free(temp);
        return t;
    }
}

void display(node * top)
{
    if(top ==  NULL)
        printf("empty");
    node *temp = top;
    while(temp != NULL)
    {
        printf("%d",temp ->data);
        temp =temp->next;
    }
}

void peektop(node *top)
{
    if(top != NULL)
    printf("%d",top->data);
}

int main()
{
  node *top = NULL;
  int choice = 0;
  int data = 0;

while (choice != 5)
{
    printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\nEnter Your Choice: ");
    scanf("%d", &choice);
    printf("\n");

    switch (choice) 
    {
    case 1:
      printf("Enter Data: ");
      scanf("\n%d", &data);
      push(&top, data);
      display(top);
      break;

    case 2:
      data = pop(&top);
      if (data) {
        printf("%d was popped\n", data);
        display(top);
      } else
        printf("Empty Stack\n");
      break;

    case 3:
      display(top);
      break;

    case 4:
      peektop(top);
      break;

    case 5:
      printf("Bye Bye!\n");
      break;

    default:
      printf("Invalid Choice\n");
    }
    printf("\n");
  }
  return 0;
}
