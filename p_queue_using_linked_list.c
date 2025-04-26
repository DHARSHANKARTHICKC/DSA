#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    char data;
    int priority;
    struct node * next;
}node;

node* getnode()
{
    return (node*)malloc(sizeof(node));
}

void enqueue(node **front,node **rear,char data,int priority)
{
    node * p = getnode();
    p -> data = data;
    p -> next = NULL;
    p -> priority =priority;
    if(*front == NULL)
    {
        *front = *rear = p;
    }
    else if((*front) ->priority > priority)
    {
        p -> next = *front;
        *front = p;
    }   
    else
    {
        node *temp = *front;
        while (temp ->next != NULL)
        {
            if(priority < temp ->next->priority)
                break;
            temp = temp->next;
        }
        p -> next = temp -> next;
        temp ->next = p;
    }
}

char dequeue(node **front,node **rear)
{
    if(*front ==  NULL)
        return '\0';
    else{
        char data = (*front) -> data;
        node * temp =*front;
        *front = (*front) ->next;
        free(temp);
        return data;
    }
}

void peek(node * front)
{
    if(front == NULL)
        printf("empty");
    else
    {
        printf("%c",front -> data);
    }
}

void display(node * front)
{
    if(front == NULL)
        printf("empty");
    else{
        node *temp =front;
        while (temp != NULL)
        {
            printf("%c-%d\t",temp -> data,temp ->priority);
            temp = temp -> next;
        }
        
    }
}

int main()
{
node *front = NULL,*rear =NULL;
  int choice = 0, priority = 0;
  char data = '\0';

  while (choice != 5) {
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\nEnter Your "
           "Choice: ");
    scanf("%i", &choice);
    printf("\n");

    switch (choice) {
    case 1:
      printf("Enter Data & Priority (d p): ");
      scanf("\n%c %i", &data, &priority);
      enqueue(&front,&rear, data, priority);
      display(front);
      break;

    case 2:
      data = dequeue(&front,&rear);
      if (data) {
        printf("%c has been Dequeued\n", data);
        display(front);
      } else
        printf("Empty Queue\n");
      break;

    case 3:
      display(front);
      break;

    case 4:
      peek(front);
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
