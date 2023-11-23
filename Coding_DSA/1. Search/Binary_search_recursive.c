#include <stdio.h>

int binarysearch(int arr[],int a,int b,int x){
    int mid = (a+(b-a))/2;
    if(b >= a){
        if(arr[mid] == x){
            return mid;
        }
        else if(x < arr[mid]){
            return binarysearch(arr,a,mid-1,x);
        }
        else{
            return binarysearch(arr,mid+1,b,x);
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,4,5,6,7,2,8};
    int x;
    scanf("%d",&x);
    int result = binarysearch(arr,0,6,x); 
    if(result == -1){
        printf("No, It is not present");
    }
    else
        printf("Yes, It is present at index : %d",result);
    return 0;
}