// Heap: A DS which is a complete Binary Tree which comes with a heap order property.
// Complete Binary Tree: It means every level is completely filled except the last level. nodes always added from the left
// There are two types of Heap:
// a. Max Heap: Here parent should be greater than the childs.
// b. Min Heap: Here child is greater than parents.
// Node -> ith index
// left child -> at 2*i index
// right child -> at (2 * i + 1)index
// parent -> (i / 2)th index
// TC: O(logn) for insertion & deletion
// to calculate the leaf node => (n/2 + 1) to nth index, here n = length of the array

#include<iostream>
using namespace std;

class Heap{
    public:
        int arr[100];
        int size;
        Heap(){
            arr[0] = -1;
            size = 0;
        }
    
    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index / 2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i = 1 ; i <= size ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteFromHeap(){
        if(size == 0){
            cout<<"Nothing to delete"<<endl;
            return;
        }
        // step1: put last element into first index
        arr[1] = arr[size];
        // step2: remove last element 
        size--;

        // step3: take root to its current position
        int i = 1;
        while(i < size){
            int left = 2*i;
            int right = 2*i + 1;

            if(left < size && arr[i] < arr[left]){
                swap(arr[i], arr[left]);
                i = left;
            }
            else if(right < size && arr[i] < arr[right]){
                swap(arr[i], arr[right]);
                i = right;  
            }
            else{
                return;
            }
        }
    }
};


int main(){
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deleteFromHeap();
    cout<<"After deletion the updated value is: "<<endl;
    h.print();
    return 0;
}