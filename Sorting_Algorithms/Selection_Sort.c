#include<stdio.h>

void selectionsort(int a[],int n)
{
    for(int pos=0;pos<n -1;pos++)
    {
        int min = pos;
        for(int i = pos+1; i< n;i++)
        {
            if(a[min] > a[i])
            {
                min = i;
            }
        }
        
        if(min != pos)
        {
            int temp = a[min];
            a[min] = a[pos];
            a[pos] = temp;

        }
    }
}

void display(int *arr, int n) {
    for (int i = 0; i < n; i++)
      printf("%i ", arr[i]);
    printf("\n");
  }
  
  int main() {
    int n;
    printf("Enter Number of Elements: ");
    scanf("%i", &n);
    int arr[n];
    printf("Enter Elements (a b c...): ");
    for (int i = 0; i < n; i++)
      scanf("%i", &arr[i]);
    display(arr, n);
    selectionsort(arr, n);
    display(arr, n);
    return 0;
  }
