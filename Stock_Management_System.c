#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct product
{
    int id;
    char name[50];
    int quantity;
    float price;
    struct product * next;
}product;


typedef struct sale
{
    int productid;
    char productname[50];
    int quantitysold;
    float totalprice;
    struct sale * next;
}sale;

product*head = NULL;
sale*salestop = NULL;





product* createproduct(int id,char name[],int quantity,int price)
{
    product *newproduct = (product*)malloc(sizeof(product));
    newproduct ->id = id;
    newproduct ->price = price;
    newproduct ->quantity = quantity;
    strcpy(newproduct ->name ,name);
    newproduct -> next = NULL;
    return newproduct;
}

void addproduct()
{
    int id,quantity;
    float price;
    char name[50];

    printf("\nEnter Product ID: ");
    scanf("%d", &id);
    printf("Enter Product Name: ");
    scanf(" %s", name);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);
    printf("Enter Price per Unit: ");
    scanf("%f", &price);

    product*newproduct = createproduct(id,name,quantity,price);
    newproduct ->next = head;
    head = newproduct;
}

void displayallproduct()
{
    if(head == NULL)
    {
        printf("no products");
        return;
    }
    else
    {

    product * temp = head;
    printf("\nCurrent Stock:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------------\n");

    while(temp != NULL)
    {
        printf("%d\t%s\t\t%d\t\t%.2f\n", temp->id, temp->name, temp->quantity, temp->price);
        temp = temp -> next;
    }
}
}

void searchproduct()
{
    int id;
    printf("Enter The Product_Id :");
    scanf("%d",&id);

    product * temp = head;
    while(temp != NULL)
    {
        if(temp -> id == id)
        {
            printf("Product Found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n",
                   temp->id, temp->name, temp->quantity, temp->price);
            return;
        }
        temp = temp->next;
    }

    printf("Product not found.\n");
}

void updateproduct()
{
    int quantity,id;

    printf("enter the product_id");
    scanf("%d",&id);

    
    product * temp = head;
    while(temp != NULL)
    {
        if(temp -> id == id)
        {
            printf("\n%d is the current quantity\n",temp ->quantity);
            printf("enter new quantity :");
            scanf("%d",&quantity);
            temp -> quantity = quantity;
            return;
        }
        temp = temp->next;
    }
    printf("not found");
}

void deleteproduct()
{
    int id;
    printf("enter the product id :");
    scanf("%d",&id);
    product *temp = head;
    
    product * prev =    NULL;

    while (temp -> id != id)
    {
        prev = temp;
        temp =temp ->next;
    }

    if(temp ==  NULL)
    {
        printf("not found\n");
    }

    if(prev == NULL)
    {
        head = temp -> next;
    }    
    else
    {
        prev -> next = temp -> next;
    }
    free(temp);
}

void pushsale(int id,char name[],float price,int quantity)
{
    sale * newsale = (sale *)malloc(sizeof(sale));
    newsale ->next = salestop;
    newsale ->productid = id;
    newsale ->quantitysold = quantity;
    newsale ->totalprice = price;
    strcpy(newsale -> productname, name);
    salestop = newsale;
}

void sellstock()
{
    product *temp = head;
    int id,quantity;
    printf("enter the id of the product :");
    scanf("%d",&id);
    while(temp != NULL)
    {
        if(temp -> id == id)
        {
            printf("AVAILABLE STOCK : %d\n",temp ->quantity);
            printf("enter the quantity :");
            scanf("%d",&quantity);
            if(temp ->quantity < quantity)
            {
                printf("Insufficient Stock\n");
                return;
            }

            temp ->quantity -= quantity;
            pushsale(temp -> id,temp -> name,(temp -> price)*quantity, quantity);
            printf("Successfully Recorded\n");
            return;
        }
        temp = temp -> next;
    }
    printf("Product Not Found\n");
}

void saleshistory()
{
    sale * temp = salestop;
    if(temp ==  NULL)
    {
        printf("No History!!!\n");
        return;
    }
    
    printf("Recent Sales History....\n");
    printf("\nID\tNAME\t\tQUANTITY\t\tTOTAL PRICE\n");
    while (temp !=NULL)
    {
        printf("%d\t%-15s\t\t%d\t\t%2f\n",temp ->productid,temp->productname,temp ->quantitysold,temp ->totalprice);
        temp =temp -> next;
    }
    
}

void saveproducts()
{
    FILE *fp =fopen("products.txt","w");
    product * temp =head;
    if(!fp)
    {
        printf("file does not exist");
        return;
    }
    while(temp != NULL)
    {
        fprintf(fp,"%d %s %d %2f\n",temp ->id,temp ->name,temp ->quantity,temp ->price);
        temp = temp -> next;
    }

    fclose(fp);
printf("\nsuccessfully saved...\n");
}

void loadproducts()
{
    FILE *fp = fopen("products.txt","r");
    if(!fp){
        printf("file not exist");
        return;
    }
    int id,quantity;
    char name[50];
    float price;
    while(fscanf(fp,"%d %s %d %f",&id,name,&quantity,&price) != EOF)
    {
        product * newproduct = createproduct(id,name,quantity,price);
        newproduct -> next = head;
        head = newproduct;
    }
    fclose(fp);
}

void salessave()
{
    FILE*fp = fopen("sale.txt","w");
    if(!fp)
    {
        printf("file not exist");
        return;
    }

    sale *temp =salestop;
    while(temp != NULL)
    {
        
        fprintf(fp,"%d %s %d %2f\n",temp ->productid,temp ->productname,temp ->quantitysold,temp ->totalprice);
        temp = temp -> next;
    }
    fclose(fp);
    printf("\nsuccess..\n");
}


void menu() {
    int choice;

    while (choice != 8) {
        printf("  ==== Stock Management System ====\n");
        printf(" ___________________________________\n");
        printf("|  1. Add Product                   |\n");
        printf("|  2. Display All Products          |\n");
        printf("|  3. Search Product                |\n");
        printf("|  4. Update Quantity               |\n");
        printf("|  5. Delete Product                |\n");
        printf("|  6. Sell Product                  |\n");
        printf("|  7. View Sales History            |\n");
        printf("|  8. Exit                          |\n");
        printf("|___________________________________|\n");
        printf("ENTER YOUR CHOISE : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addproduct();
            break;
        case 2:
            displayallproduct();
            break;
        case 3:
            searchproduct();
            break;
        case 4:
            updateproduct();
            break;
        case 5:
            deleteproduct();
            break;
        case 6:
            sellstock();
            break;
        case 7:
            saleshistory();
            break;
        case 8:
            saveproducts();
            salessave();
            printf("data...saved...!!");
            break;
            
        default:
            printf("select valid choise!!");
            break;
        }
    }
}

int main()
{
    loadproducts();
    menu();
    return 0;
}
