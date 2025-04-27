#include<stdio.h>

void merge(int a[],int low,int mid,int high)
{
    int  i = low,j = mid +1,k = low;
    int b[high - low + 1];
    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while(i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while(j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    for(k = low; k<=high;k++)
    {
        a[k] = b[k];
    }
}

void mergesort(int a[],int low,int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void display(int arr[], int n) {
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
    mergesort(arr, 0, n - 1);
    display(arr, n);
    return 0;
  }