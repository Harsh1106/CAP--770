#include<iostream>
using namespace std;
void found(int arr[], int size){
    int choice = 0;
    for(int i = 0 ; i < size ; i++){
        choice = choice^arr[i];
    }
    cout<<"Unique element is: "<<choice;
}
int main(){
    int arr[] = {2,4,7,2,7};
    int arrSize = sizeof(arr)/sizeof(int);
    found(arr, arrSize);
}