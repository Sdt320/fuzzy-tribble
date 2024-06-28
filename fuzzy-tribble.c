#include <stdio.h>

void print_arrar(int a[],int s);
void sorting(int a[],int s);
void array_element(int a[],int s);

int main()
{
    int k, a[10] = {45, 3, 6, 12, 2};
    int s = 5;
    printf("Find the Kth largest and Kth smallest element in an array. \n");
    //printf("enter the values ");
    //array_element(a,s);
    printf("entered values:- ");
    print_arrar(a,s);
    printf("sorted array:- ");
    sorting( a, s);
    printf("enter a value of K ");
    
    scanf("%d",&k);
    printf("Find the Kth largest %d and Kth smallest element %d. \n",a[5-k],a[k-1]);

    
   

    return 0;
}
void print_arrar(int a[],int s){
    
    int i=s;
    for(i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    }
    
void sorting(int a[],int s){
    int i=s,j,temp;
    for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }  
     print_arrar(a,s);
}

void array_element(int a[], int s)
{
    int i;
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
}
