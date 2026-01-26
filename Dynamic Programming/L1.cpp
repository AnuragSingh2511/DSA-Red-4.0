#include<iostream>
using namespace std;

// T.C - O(2^n)
// S.C - O(n)   // recursion stack
//fibonacci number solved using recursion
int solveUsingRecursion(int n){
   //base case
   if(n == 0){
    return 0;
   }

   if(n == 1){
    return 1;
   }

   int ans = solveUsingRecursion(n - 1) + solveUsingRecursion(n - 2);
   return ans;
}

int main(){
    // 0 1 1 2 3 5
    // Oth number is 0....5th number is 5 so o/p must come 5
    int n = 5;
    cout << solveUsingRecursion(n);


    return 0;
}