#include <stdio.h>

void main(){
    int arr[7] = {7,6,12,3,8,15,4};
    for(int i = 0;i<7;i++){
        int flag = 0;
        for(int j=0;j<7-1-i;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if(flag==0){
            break;
        }

    }

    for(int i=0;i<7;i++){
        printf("%d ",arr[i]);
    }
}