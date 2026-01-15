#include<iostream>
using namespace std;

/*
Time Complexity (T.C): O(N)
- Because the function visits each element of the array exactly once.

Space Complexity (S.C): O(N)
- Due to recursion call stack.
- Each recursive call stays in memory until base case is reached.
*/

void printArray(int arr[], int size, int index){
    //Base case
    if(index >= size){
        return;
    }
    //1 case mera hoga
    cout << arr[index] << " ";

    //recursive call
    printArray(arr, size, index+1);
}

void reversePrint(int arr[], int size, int index){
   //base case
   if(index < 0){
    return;
   }

   //1 case
   cout << arr[index] << " ";

   //recursive call
   reversePrint(arr, size, index-1);
}

/*
Time Complexity (T.C): O(N)
- The function is called once for each array element.

Space Complexity (S.C): O(N)
- Due to recursion call stack.
- Maximum N recursive calls are present at one time.
*/

int main(){

   int arr[] = {10,20,30,40,50,60};
   int size = sizeof(arr)/sizeof(int);
//    int index = 0;
   int index = size-1;

//    printArray(arr, size, index);
   reversePrint(arr, size, index);

    return 0;
}