#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *prev;
  struct node *next;
} node;

node *getnode() 
{
    return (node *)malloc(sizeof(node));
}

void display(node *head) 
{
  node *temp = head;
  while (temp != NULL) 
  {
    printf("%i ", temp->data);
    temp = temp->next;
  }
}

void insert(node **head, int data, int pos) 
{
  node *new = getnode();
  new->data = data;
  new->next = NULL;
  new->prev = NULL;

  if (*head == NULL)
    *head = new;

  else if (pos == 0) {
    new->next = *head;
    *head = new;
}


  else if (pos == -1) {
    node *temp = *head;
    while (temp->next != NULL)
      temp = temp->next;
    new->prev = temp;
    temp->next = new;
  }

  else if (pos > 0) {
    node *temp = *head;
    int i = 1;
    while (i < pos && temp->next != NULL) {
      temp = temp->next;
      i++;
    }
    new->prev = temp;
    new->next = temp->next;
    if (temp->next != NULL)
      new->next->prev = new;
    temp->next = new;
  }
}

void delete(node **head, int pos) 
{
if (*head == NULL)
    printf("Empty List\n");

else if ((*head)->next == NULL) 
{
    free(*head);
    *head = NULL;
}

else if (pos == 0) {
    node *toFree = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(toFree);
}

else if (pos == -1) {
node *temp = *head;
while (temp->next->next != NULL)
  temp = temp->next;
free(temp->next);
temp->next = NULL;
}

  else if (pos > 0) {
    node *temp = *head;
    int i = 1;
    while (i < pos && temp->next->next != NULL) {
      temp = temp->next;
      i++;
    }
    node *toFree = temp->next;
    temp->next = temp->next->next;
    if (temp->next != NULL)
      temp->next->prev = temp;
    free(toFree);
  }
}

int search(node *head, int data) 
{
node *temp = head;
int i = 0;
while (temp != NULL) 
{
    if (temp->data == data)
        return i;
    temp = temp->next;
    i++;
}

  return -1;
}

int main() {
  node *head = NULL;
  int data, pos, choice = 0;

  while (choice != 5) {
    printf("1. Insert\n2. Delete\n3. Display\n4. Search\n5. Exit\nEnter Your "
           "Choice: ");
    scanf("%i", &choice);
    printf("\n");

    switch (choice) {
    case 1:
      printf("Enter Data: ");
      scanf("%i", &data);
      printf("Enter Position (0->Beg, -1->End): ");
      scanf("%i", &pos);
      if (pos < -1)
        printf("Invalid Position\n");
      insert(&head, data, pos);
      display(head);
      break;

    case 2:
      printf("Enter Position (0->Beg, -1->End): ");
      scanf("%i", &pos);
      if (pos < -1)
        printf("Invalid Position\n");
      delete (&head, pos);
      display(head);
      break;

    case 3:
      display(head);
      break;

    case 4:
      printf("Enter Data: ");
      scanf("%i", &data);
      pos = search(head, data);
      if (pos != -1)
        printf("%i is at position %i\n", data, pos);
      else
        printf("Data not found\n");
      break;

    case 5:
      printf("TERMINATED!\n");
      break;

    default:
      printf("Invalid Choice\n");
    }
    printf("\n");
  }
  return 0;
}