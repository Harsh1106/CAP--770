#include<iostream>
using namespace std;
// int main(){
//     int arr[15];
//     // int size = sizeof(arr)/sizeof(int);
//     // cout<<size;
//     int size ;
//     cin>>size;  
//     for(int i = 0 ; i <= size-1 ; i++){
//         cin>>arr[i];
//     }
//     for(int i = 0 ; i < size ; i++){
//         for (int j = i + 1 ; j < size; j++)
//         {
//             if(arr[i] == arr[j]){
//                 cout<<arr[i]<<" ";
//                 break;
//             }
//         }
        
//     }
// }
int main(){
    int ans = 0;
    int arr[10];
    int size;
    cin>>size;
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }
    for(int i = 0 ; i < size ; i++){
        ans = ans ^ arr[i];
    }
    for(int i = 1 ; i <= size-1 ; i++){
        ans = ans^i;
    }
    cout<<ans;
}