#include <stdio.h>

void main(){
    int arr[7] = {7,6,12,3,8,4,15};
    for(int i=1;i<7;i++){
        int temp = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    for(int i=0;i<7;i++){
        printf("%d ",arr[i]);
    }
}