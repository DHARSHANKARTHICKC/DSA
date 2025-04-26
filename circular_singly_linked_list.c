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

void display(node *head,node *tail)
{
    if(head == NULL)
    {
        printf("empty");
    }
    else
    {
        node * temp;
        temp = head;
        while(temp!= tail)
        {
            printf("%d",temp->data);
            temp = temp -> next;
        }
        if(temp != NULL)
        {
            printf("%d", temp -> data);
        }
    }

}
void creation(int x,node **head,node ** tail)
{
    node * p = getnode();
    p->data = x;
    p->next = NULL;
    if(*head == NULL)
    {
        *head = p;
        *tail = p;
    }
    else
    {
        (*tail) -> next = p;
        *tail = p;
        (*tail) -> next = *head;
    }
}


int searching(node *head, node *tail, int data) {
    node *temp = head;
    int i = 0;
    while (temp != tail) {
      if (temp->data == data)
        return i;
      temp = temp->next;
      i++;
    }
    if (temp != NULL && temp->data == data)
      return i;
    return -1;
  }


void insert_at_beg(node **head,int data,node **tail)
{

    node *p = getnode();
    p ->data = data;
    if(*head == NULL)
    {
        *head = p;
        *tail = p;
        (*tail) -> next = p;
    }
    else
    {
        p ->next = *head;
        (*tail) -> next = p;
        *head = p;
    }

}
void insert_at_end(node ** head,int data,node **tail)
{
    node*p = getnode();
    p ->data=data;
    (*tail) -> next = p;
    *tail = p;
    (*tail) -> next = *head;
}
void insert_at_pos(node **head,int data)
{
    node * p = getnode();
    p ->data = data;
    int loc;
    printf("enter the loc");
    scanf("%d",&loc);
    int i = 1;
    node *temp = *head;
    while(i < loc)
    {
        temp = temp ->next;
        i++;
    }
    p->next = temp ->next;
    temp ->next = p;
}

int delete_at_beg(node **head,node **tail)
{
    node * temp = *head;
    int result = temp->data;
    *head = temp -> next;
    (*tail) ->next = *head;
    free(temp);
    return result;
}

int delete_at_end(node **head,node **tail)
{
    int result;
    node *p;
    node *temp = *head;
    while(temp->next != *tail)
    {
        temp = temp -> next; 
    }
    result = (*tail) -> data;
    free(*tail);
    *tail = temp;
    return result;
}
int delete_at_pos(node **head)
{
    int loc;
    printf("enter the loc");
    scanf("%d",&loc);
    int i = 1;
    node *temp = *head;
    node *p;
    while (i<loc)
    {
        temp = temp ->next;
        i++;
    }

    node *todelete = temp->next;
    int result = todelete -> data;
    temp ->next = temp->next->next;
    free(todelete);
    return result;
}

int main()
{
    node *head,*tail = NULL;
    int p,choise,data;

    while (choise != 10)
    {
        choise = 0;
        printf("\nenter your choise \n1.creation\n2.insert front\n3.insert end\n4.insert at pos\n5.delete front\n6.delete end\n7.delete at pos \n8.display \n9.searching\n10.exit\n");
        scanf("%d",&choise);
        switch(choise)
        {
            case 1:
                printf("enter the data");
                scanf("%d",&data);
                creation(data,&head,&tail);
                break;
            
            case 2:
                printf("enter the data");
                scanf("%d",&data);
                insert_at_beg(&head,data,&tail);
                break;
            case 3:
                printf("enter the data");
                scanf("%d",&data);
                insert_at_end(&head,data,&tail);
                break;
            case 4:
                printf("enter the data");
                scanf("%d",&data);
                insert_at_pos(&head,data);
                break;
            case 5:
                p = delete_at_beg(&head,&tail);
                printf("%d",p);
                break;
            case 6:
                p = delete_at_end(&head,&tail);
                printf("%d",p);
                break;
            case 7:
                p = delete_at_pos(&head);
                printf("%d",p);
                break;
            case 8:
                display(head,tail);
                break;
            case 9:
                printf("enter the data");
                scanf("%d",&data);
                p = searching(head,tail,data);
                if(p == -1)
                {
                    printf("element not found");
                }
                else{
                    printf("the element is at pos %d",p);
                }
                break;
            case 10:
                printf("terminated");
                break;
            
            default:
                printf("enter valid choise");
                break;
        }
    }
}