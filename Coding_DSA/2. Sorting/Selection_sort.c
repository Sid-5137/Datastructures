#include <stdio.h>

int main(){
    int arr[7] = {7,6,12,3,8,15,4};

    for(int i=0;i<7-1;i++){
        int minindex = i;

        for(int j=i+1;j<7;j++){
            if(arr[j]<arr[minindex]){
                minindex = j;
            }
        }

        if(minindex!=i){
            int temp = arr[i];
            arr[i] = arr[minindex];
            arr[minindex] = temp;
        }
    }

    for(int i=0;i<7;i++){
        printf("%d ",arr[i]);
    }
}