#include <stdio.h>
/*
    Binary search is a more efficient search algorithm, but it requires that the array is sorted in ascending order.
*/
int sbinary(int arr[],int x,int s){
    // lets take a basic sorted array
    int l = 0, u = x-1;
    while(l<=u){
        int mid = (l + u) / 2;
        if(s == arr[mid])
            return s;
        else if(s < arr[mid])
            u = mid - 1;
        else
            l = mid + 1;
    }
}

void main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("\nEnter the array.\n");
    int arr[n],a;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the number to search: \n");
    scanf("%d",&a);
    if(sbinary(arr,n,a)){
        printf("Yes the element is present.");
    }
    else{
        printf("Not present in the array.");
    }
}