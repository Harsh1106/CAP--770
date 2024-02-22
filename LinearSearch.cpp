#include<iostream>
using namespace std;
int search(int arr[], int size, int key){
    for(int i = 0 ; i < size ; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return 0;
}

int main(){
    int arr[] = {5, 7, -2, 10, 22, -2, 0, 5, 22, 1};
    cout<<"Enter the key you want to search: ";
    int key;
    cin>>key;
    int size = sizeof(arr)/sizeof(int);
    // bool found = search(arr, size, key);
    int found = search(arr, size, key);
    if(found){
        cout<<"Element is in the list "<<found<<endl;
    }else{
        cout<<"Element is not in the list"<<endl;
    }
}