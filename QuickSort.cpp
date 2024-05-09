#include<iostream>
using namespace std;


int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int count = 0;
    for(int i = s+1 ; i <= e ; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    // place pivot at right position
    int idx = s + count;
    swap(arr[idx], arr[s]);

    // left nd right wla part
    int i = s, j = e;
    while(i < idx && j > idx){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < idx && j > idx){
            swap(arr[i++], arr[j--]);
        }
    }
    return idx;
}
void quickSort(int arr[], int s, int e){
// base case
    if(s >= e){
        return;
    }

    // partition part
    int p = partition(arr, s, e);

    //left part 
    quickSort(arr, s, p-1);
    // right part
    quickSort(arr, p+1, e);
}
int main(){
    int arr[10] = {2,4,1,6,9,9,9,9,9,9};
    int n = 10;

    quickSort(arr, 0, n-1);
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}