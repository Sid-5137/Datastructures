#include <stdio.h>

/*
   Linear search is a simple search algorithm that iterates through an array to find a specific element.
*/

int main(){
    int arr[10] = {3,6,7,4,8,9,563,2,4,69};
    int n,flag=0;
    printf("Enter the element u wanna search in the array: \n");
    scanf("%d",&n);
    for(int i=0;i<10;i++){
        if(arr[i] == n)
            printf("Yes, the element %d is present in the array..\n",n);
            flag = 1;
    }
    if(flag==0){
        printf("No, the element %d is not present in the array..\n",n);
    }
    
    return 0;
}