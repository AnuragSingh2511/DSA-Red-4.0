#include<iostream>
using namespace std;

int recursivebinarySearch(int arr[], int s, int e, int target){
 // base case
 if( s > e){
    return -1;
 }

 //1 case
 int mid = s + (e - s)/2;
 if(arr[mid] == target){
    return mid;
 }

 //rest recursion will take care
 if(arr[mid] > target){
    //left
    return recursivebinarySearch(arr, s, mid-1, target);
 }
 else{
    //right
    return recursivebinarySearch(arr, mid+1, e, target);
 }
}

int main(){
    
    int arr[] = {-1, 0, 3, 5, 9, 12};
    int size = sizeof(arr)/sizeof(int);

    int s = 0;
    int e = size - 1;
    int target = 9;

    int indexOfTargetElement = recursivebinarySearch(arr, s, e, target);
    cout << "Element found at: " << indexOfTargetElement ;

    return 0;
}