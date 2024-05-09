#include<iostream>
using namespace std;

void merge(int arr[], int s, int e){
    int mid = (s + e)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int mainArrayIndex = s;
    for(int i = 0 ; i < len1 ; i++){
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    for(int i = 0 ; i < len2 ; i++){
        second[i] = arr[mainArrayIndex++];
    }

    // merge 2 arrays
    int idx1 = 0;
    int idx2 = 0;
    mainArrayIndex = s;
    while(idx1 < len1 && idx2 < len2){
        if(first[idx1]<second[idx2]){
            arr[mainArrayIndex++] = first[idx1++]; 
        }
        else{
            arr[mainArrayIndex++] = second[idx2++];
        }
    }
    while(idx1 < len1){
        arr[mainArrayIndex++] = second[idx2++];
    }
}

void mergeSort(int *arr, int s, int e){
    // base case
    if(s >= e){
        return;
    }
    int mid = (s + e)/2;

    // left part
    mergeSort(arr, s, mid);
    // right part
    mergeSort(arr, mid+1, e);

    merge(arr, s, e);
}

int main(){

    int arr[5] = {2,5,1,6,9};
    int n = 5;
    mergeSort(arr, 0, n-1);
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}