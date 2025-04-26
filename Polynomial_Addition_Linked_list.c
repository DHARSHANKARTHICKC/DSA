#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int coeff;
    int exp;
    struct node * next;
} node;

node * getnode()
{
    return (node*)malloc(sizeof(node));
}
void * insert(node ** head,node * new)
{
    if(*head == NULL)
    {
        new -> next =NULL;
        *head = new;
    }
    else if (new -> exp > (*head) -> exp )
    {
        new->next = *head;
        *head = new;
    }
    else    
    {
        node*temp =*head;
        while(temp->next != NULL)
        {
            if(new -> exp > temp -> next -> exp)
            {
                break;
            }
            temp = temp -> next;
        }
        new -> next = temp -> next;
        temp -> next = new;
    }
    
}
node* create()
{
    int n,coeff,expo;
    node * head =NULL;
    printf("enter the no of terms");
    scanf("%d",&n);
    for (int i = 0 ; i<n ;i++)
    {
        printf("enter the coeff and expo : ");
        scanf("%dx%d",&coeff,&expo);
        node*new = getnode();
        new -> coeff = coeff;
        new ->exp =expo;
        insert(&head,new);
    }
    return head;
}

node*add(node * p1,node * p2)
{
    node *t1 = p1,*t2 = p2;
    node * p3 = NULL;  
    while (t1 != NULL && t2 != NULL) 
    {
        node *term = getnode();
        if (t1->exp == t2->exp) {
          term->coeff = t1->coeff + t2->coeff;
          term->exp = t1->exp;
          t1 = t1->next;
          t2 = t2->next;
        } else if (t1->exp < t2->exp) {
          term->coeff = t2->coeff;
          term->exp = t2->exp;
          t2 = t2->next;
        } else {
          term->coeff = t1->coeff;
          term->exp = t1->exp;
          t1 = t1->next;
        }
        insert(&p3, term);
    }
    while (t1 != NULL) 
    {
        node *term = getnode();
        term->coeff = t1->coeff;
        term->exp = t1->exp;
        t1 = t1->next;
        insert(&p3, term);
    }
    while (t2 != NULL) 
    {
        node *term = getnode();
        term->coeff = t2->coeff;
        term->exp = t2->exp;
        t2 = t2->next;
        insert(&p3, term);
    }
    return p3;
}
    



void display(node *poly)
{
    node *temp = poly;
    while (temp->next != NULL)
    {
      printf("%ix%i + ", temp->coeff, temp->exp);
      temp = temp->next;
    }
    printf("%ix%i\n", temp->coeff, temp->exp);
}
  
int main() 
{
    node *poly1 = create();
    display(poly1);
    node *poly2 = create();
    display(poly2);
    node *poly3 = add(poly1, poly2);
    display(poly3);
    return 0;
}