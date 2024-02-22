// first and last position of element in a sorted array
#include<iostream>
using namespace std;
int firstOccurence(int arr[], int size, int key){
    int start = 0 ;
    int end = size - 1;
    int mid = start +(end - start)/2;
    int ans = -1;
    while(end >= start){
        if(arr[mid] == key){
        ans = mid;
        end = mid - 1; //yha hmne ye issliye kra kyu ki hme first occurence niklanni thi to jitna jda todenge utna jda uske first occurence tk pauchenge
        }
        else if(arr[mid] > key){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}
int lastOccurence(int arr[], int size, int key){
    int start = 0; int end = size - 1;
    int mid = start + (end - start)/2;
    int ans = -1;
    while(end >= start){
        if(arr[mid] == key){
            ans = mid;
            start = mid + 1; //hume right wale part m jaana tha that's why yha hmne start ko update kra nd aage bdhaya mid ke 
        }
        else if(key > arr[mid]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}
int main(){
    int even[8] = {0, 0, 1, 1, 2, 2, 2, 2};
    int first = firstOccurence(even, 8, 1);
    int last = lastOccurence(even, 8, 1);
    cout<<"First occurence of the 4 is: "<<first<<endl;
    cout<<"Last occurence of the 4 is: "<<last<<endl;
    // agar hme no of occurence nikalni hoti ki wo element kitne br aaya h to hm iss approach ko follow krte.
    int noOfOccurence = (last - first) + 1;
    cout<<"Number of occurence of this element is: "<<noOfOccurence;
    return 0;
}