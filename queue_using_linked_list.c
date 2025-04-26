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

void enqueue(node **front,node **rear,int data)
{
    node *p = getnode();
    p -> data = data;
    p ->next = NULL;
    if(*front ==NULL)
    {
        *front = p;
        *rear = p;
    }
    else
    {
        (*rear) -> next  = p;
        *rear = p;
    }
}

int dequeue(node **front,node **rear)
{
    int p;
    if(*front == NULL)
    {
        printf("empty");
        return -1;
    }
    else if(*front == *rear)
    {
        p = (*front)->data;
        *front =NULL;
        *rear =NULL;
    }
    else
    {
        p =(*front)->data;
        node *temp = *front;
        *front = (*front)->next;
        free(temp);
    }
    return p;
}

void peekfront(node *front)
{
    if(front == NULL)
    {
        printf("ëmpty");
    }
    else{
        printf("%d",(front)->data);
    }
}

void display(node *front,node *rear)
{
    if(front == NULL)
        printf("empty");
    else
    {
        node * temp = front;
        while(temp != NULL)
        {
            printf("%d\t",(temp)->data);
            temp = temp ->  next;
        }
    }
}

int main() {
    node *front = NULL, *rear = NULL;
    int choice = 0;
    int data = 0;
  
    while (choice != 5) {
      printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\nEnter Your "
             "Choice: ");
      scanf("%d", &choice);
      printf("\n");
  
      switch (choice) {
      case 1:
        printf("Enter Data: ");
        scanf("\n%d", &data);
        enqueue(&front, &rear, data);
        display(front, rear);
        break;
  
      case 2:
        data = dequeue(&front, &rear);
        if (data) {
          printf("%d Dequeued\n", data);
          display(front, rear);
        } else
          printf("Empty Queue\n");
        break;
  
      case 3:
        display(front, rear);
        break;
  
      case 4:
        peekfront(front);
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