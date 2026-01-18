#include <bits/stdc++.h>
using namespace std;

bool checkArraySorted(int arr[], int size, int index){
   //base case
   if(index == 0){
    return true;
   }
   if(arr[index] < arr[index-1]){
    return false;
   }
   

   if(arr[index] >= arr[index - 1]){
    //current element toh sorted hai, but aage ka ans recursion batayega
    bool recursionKaAns = checkArraySorted(arr, size, index - 1);
    return recursionKaAns;
   }
}

int main() {
   
   int arr[] = {10,20,30,40,50};
   int size = sizeof(arr)/sizeof(int);
   int index = size - 1;

//    bool ans = checkArraySorted(arr, size, index);
//    cout << "Sorted or not: " << ans << endl;

   cout << (checkArraySorted(arr, size, index) ? "true" : "false");
    

    return 0;
}
