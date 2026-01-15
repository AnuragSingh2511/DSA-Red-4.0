#include<iostream>
using namespace std;

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

int main(){

   int arr[] = {10,20,30,40,50,60};
   int size = sizeof(arr)/sizeof(int);
   int index = 0;

   printArray(arr, size, index);

    return 0;
}