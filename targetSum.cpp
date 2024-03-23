#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int target = 8;
    int len = sizeof(arr)/sizeof(int);
    for(int i = 0 ; i < len ; i++){
        for(int j = 1 ; j < len ; j++){
            int sum = arr[i] + arr[j];
            if(sum == target){
                cout<<"Indices are:\n"<<arr[i]<<" "<<arr[j]<<endl;
            }else{
                continue;
            }
        }
    }
}