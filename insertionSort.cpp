#include<iostream>
using namespace std;
void insertionSort(int arr[], int size){
    for(int i = 1 ; i < size ; i++)
    {
        int temp = arr[i];
       
        for( int j = i-1 ; j >= 0 ; j--)
        {
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }else{
                break;
            }
            arr[j+1] = temp;
        }
        
    }
}
int main(){
    int arr[7] = {10,1,7,4,8,2,11};
    int size = sizeof(arr)/sizeof(int);
    insertionSort(arr, size);
    cout<<"Sorted array:"<<endl;
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
}
