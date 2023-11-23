#include <stdio.h>

int partition(int* arr,int s,int e){
    int pivot = arr[s];
    int pivotindex = s;
    for(int i=s;i<=e;i++){
        if(pivot > arr[i]){
            pivotindex++;
        }
    }

    int temp = arr[s];
    arr[s] = arr[pivotindex];
    arr[pivotindex] = temp; 
    
    int i=s;
    int j=e;

    while(i<pivotindex && j>pivotindex){
        while(arr[i]<arr[pivotindex]){
            i++;
        }
        while(arr[j]>arr[pivotindex]){
            j--;
        }

        if(i<pivotindex && j>pivotindex){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return pivotindex;
}

void quicksort(int* arr,int s, int e){
    if(s>=e){
        return;
    }
    int p = partition(arr,s,e);

    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}

int main(){
    int arr[7] = {7,6,12,3,8,15,4};
    quicksort(arr,0,6);

    for(int i=0;i<7;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}