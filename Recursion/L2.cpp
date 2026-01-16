#include<iostream>
#include<limits.h>
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

/*
Time Complexity (T.C): O(N)
- The function is called once for each array element.

Space Complexity (S.C): O(N)
- Due to recursion call stack.
- Maximum N recursive calls are present at one time.
*/

// void reversePrint(int arr[], int size, int index){
//    //base case
//    if(index < 0){
//     return;
//    }

//    //1 case
//    cout << arr[index] << " ";

//    //recursive call
//    reversePrint(arr, size, index-1);
// }

void reversePrint(int arr[], int size){ //babbar solution
   //base case
   if(size == 0){
    return;
   }

   //1 case
   cout << arr[size-1] << " ";

   //recursive call
   reversePrint(arr, size-1);
}

/*
Time Complexity (T.C): O(N)
- In worst case, we check every element once.

Space Complexity (S.C): O(N)
- Due to recursion call stack.
*/

bool searchArray(int arr[], int size, int index, int target){
    // base case: element not found
    if(index >= size){
        return false;
    }

    // base case: element found
    if(arr[index] == target){
        return true;
    }

    // recursive call (IMPORTANT: return it)
    return searchArray(arr, size, index + 1, target);
}

void getMinElement(int arr[], int size, int index, int &mini){
  // Base case or corner case
  if(index >= size){
    return;
  }

 //1 case
 mini = min(mini, arr[index]);

 //recursive call
 getMinElement(arr, size, index+1, mini);
}

int main(){

   int arr[] = {10,20,30,40,50,60};
   int size = sizeof(arr)/sizeof(int);

   int target = 60;
   int index = 0;
   int mini = INT_MAX;

   getMinElement(arr, size, index, mini);
   cout << "Min element is : " << mini << endl;
//    int index = size-1;

//    printArray(arr, size, index);
//    reversePrint(arr, size);
//    reversePrint(arr, size, index);

// bool ans = searchArray(arr, size, index, target);
// cout << ans;

// cout << (searchArray(arr, size, index, target)? "true" : "false"); //ternary operator

    return 0;
}