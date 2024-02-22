#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n){
    for(int i = 1 ; i < n ; i++){
        bool swapped = false; //used this for better optimization
        for(int j = 0 ; j < (n - i); j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;// means already sorted
        }
    }
}
int main(){
    int arr[] = {10,1,7,6,14,9};
    int n = sizeof(arr)/sizeof(int);
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}