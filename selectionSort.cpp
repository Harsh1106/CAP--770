// use of selection sort is when the array size is small.
#include<iostream>
using namespace std;
void selectionSort(int arr[], int n){
    for(int i = 0 ; i < n - 1 ; i++){
        int minIndex = i; //pehle index ko hm yha sbse chota mann rhe h aur usko compare kr rhe h dusre elements se
        for(int j = i+1 ; j < n ; j++){
            if(arr[j] < arr[minIndex]){ //agar koi element minIndex se bi chota lie krta h array m to usko minIndex ko update kr do
                minIndex = j;
            }
        }        
    swap(arr[i], arr[minIndex]);
    }
}
int main(){
    int arr[9] = {29,72,98,13,87,66,52,51,36};
    int n = sizeof(arr)/sizeof(int);
    selectionSort(arr, n);
    cout<<"Sorted Array:"<<endl;
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;    
}