#include<iostream>
using namespace std;

void printDigits(int num){
    //base case
    if(num == 0){
        return;
    }

    //1 case
    int digit = num % 10;

    //rest recursion
    printDigits(num/10);

    cout << digit << " ";
}

int main(){
    
    int num =  429;
    printDigits(num);
    
    return 0;
}