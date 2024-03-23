#include<iostream>
using namespace std;

string findLen(const string& str){
    int n = str.length();
    int maxLength = 0;  // Length of the longest substring
    int start = 0;      // Start index of the longest substring

    // Iterate through each character in the string
    for (int i = 0; i < n; ++i) {
        // Check all substrings starting from index i
        for (int j = i + 1; j <= n; ++j) {
            // Check if the current substring is longer than the previous longest substring
            if (j - i > maxLength && str.find(str.substr(i, j - i), i + 1) == string::npos) {
                maxLength = j - i;
                start = i;
            }
        }
    }
    return str.substr(start, maxLength);
}

int main(){
    string str = "examplestring";
    string len = findLen(str);
    cout<<"Longest substring is: "<<len<<endl;
}