#include <stdio.h>

int main(){
    int arr[7] = {7,6,12,3,8,15,4};
    for(int i=0;i=7-1;i++){
        int min = i;
        for(int j=i+1;j<7;j++){
            if(arr[j] < min)
                min = j;
        }
        if(min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}