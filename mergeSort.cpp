// #include<iostream>
// using namespace std;

// void merge(int arr[], int s, int e){
//     int mid = (s + e)/2;
//     int len1 = mid - s + 1;
//     int len2 = e - mid;
//     int *first = new int[len1];
//     int *second = new int[len2];

//     // copy values
//     int mainArrayIndex = s;
//     for(int i = 0 ; i < len1 ; i++){
//         first[i] = arr[mainArrayIndex++];
//     }
//     mainArrayIndex = mid + 1;
//     for(int i = 0 ; i < len2 ; i++){
//         second[i] = arr[mainArrayIndex++];
//     }

//     // merge 2 arrays
//     int idx1 = 0;
//     int idx2 = 0;
//     mainArrayIndex = s;
//     while(idx1 < len1 && idx2 < len2){
//         if(first[idx1]<second[idx2]){
//             arr[mainArrayIndex++] = first[idx1++]; 
//         }
//         else{
//             arr[mainArrayIndex++] = second[idx2++];
//         }
//     }
//     while(idx1 < len1){
//         arr[mainArrayIndex++] = second[idx2++];
//     }
// }

// void mergeSort(int *arr, int s, int e){
//     // base case
//     if(s >= e){
//         return;
//     }
//     int mid = (s + e)/2;

//     // left part
//     mergeSort(arr, s, mid);
//     // right part
//     mergeSort(arr, mid+1, e);

//     merge(arr, s, e);
// }

// int main(){

//     int arr[5] = {2,5,1,6,9};
//     int n = 5;
//     mergeSort(arr, 0, n-1);
//     for(int i = 0 ; i < n ; i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

#include <iostream>
using namespace std;

// Merge two halves of the array
void mergeProcedure(int arr[], int beg, int mid, int end) {
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    // Create temporary arrays
    int* left = new int[n1];
    int* right = new int[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; ++i)
        left[i] = arr[beg + i];
    for (int j = 0; j < n2; ++j)
        right[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[beg..end]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = beg; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // Copy remaining elements of left[] if any
    while (i < n1) {
        arr[k++] = left[i++];
    }

    // Copy remaining elements of right[] if any
    while (j < n2) {
        arr[k++] = right[j++];
    }

    // Free the temporary arrays
    delete[] left;
    delete[] right;
}

// Merge sort function
void mergeSort(int arr[], int beg, int end) {
    if (beg < end) {
        int mid = beg + (end - beg) / 2;

        // Recursively sort the two halves
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);

        // Merge the sorted halves
        mergeProcedure(arr, beg, mid, end);
    }
}

int main() {
    int arr[] = {3, 1, 3, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call mergeSort on the entire array
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
