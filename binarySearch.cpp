//applicable only monotonic functions   
#include<iostream>
using namespace std;
int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;

    int mid = (start + end)/2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        if(key > arr[mid]){
//means we will head to the right side.
            start = mid + 1;            
        }
        else{
// this condition is where mid is greater than key value.
            end = mid - 1;
        }
        mid = (start + end)/2;
    }
    return -1;
}



int main(){
    int even[6] = {2,4,6,8,10,12};
    int odd[5] = {1,3,5,7,9};
    int eSize = sizeof(even)/sizeof(int);
    int oSize = sizeof(odd)/sizeof(int);
    int ekey;
    cin>>ekey;
    int evenIndex = binarySearch(even, eSize, ekey);
    cout<<"Index of "<<ekey<<" is "<<evenIndex<<endl;

    cout<<"**************************************"<<endl;
    int okey;
    cin>>okey;
    int oddIndex = binarySearch(odd, oSize, okey);
    cout<<"Index of "<<okey<<" is "<<oddIndex;

    return 0;
}