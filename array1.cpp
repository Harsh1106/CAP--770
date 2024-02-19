// insert an item or implement the insertion algorithm size should be 100.
// in cpp there is not index bound exception of array it will give an error illegeal exception has been taken
#include<iostream>
using namespace std;
int main(){
    int arr[100];
    int size=0;
    cout<<"How much size you want in array: ";
    cin>>size;
    cout<<"Enter the elements in array: ";
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }
    cout<<"Enter the new element:";
    int n, pos;
    cin>>n;
    cout<<"Enter the position where element is to be inserted: ";
    cin>>pos;
    // where elements needs to be inserted
    size = size + 1;
    for(int i = size - 1 ; i >= pos ; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = n; //insert the element pos on the specified position

    //print the new arrat
    for(int i  = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}