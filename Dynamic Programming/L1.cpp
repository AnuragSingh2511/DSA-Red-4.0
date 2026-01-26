#include<iostream>
using namespace std;

// T.C - O(2^n)
// S.C - O(n)   // recursion stack
//fibonacci number solved using recursion
int solveUsingRecusion(int n){
   //base case
   if(n == 0){
    return 0;
   }

   if(n == 1){
    return 1;
   }

   int ans = solveUsingRecusion(n - 1) + solveUsingRecusion(n - 2);
   return ans;
}

int main(){
    int n = 5;
    cout << solveUsingRecusion(n);


    return 0;
}