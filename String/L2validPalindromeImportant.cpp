// TC: O(n)
// One pass for normalization + one pass for palindrome check

// SC: O(n)
// Extra string used to store filtered characters

#include<iostream>
#include<string>
using namespace std;

bool isvalidCharacter(char ch){
    if(ch >= '0' && ch <= '9') return true;
    if(ch >= 'a' && ch <= 'z') return true;
    if(ch >= 'A' && ch <= 'Z') return true;
    return false;
}

// Removes special characters and converts to lowercase
string normaliseString(string& s){
    string newStr = "";

    for(int i = 0; i < s.length(); i++){
        char ch = s[i];

        if(isvalidCharacter(ch)){
            if(ch >= 'A' && ch <= 'Z'){
                ch = ch - 'A' + 'a';
            }
            newStr.push_back(ch);
        }
    }

    return newStr;
}

bool isPalindrome(string s) {

    string newStr = normaliseString(s);

    int i = 0;
    int j = newStr.length() - 1;

    while(i <= j){
        if(newStr[i] != newStr[j]){
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int main(){

    /*
    Sample Input 1:
    A man, a plan, a canal: Panama

    Sample Output 1:
    Valid

    Explanation:
    After normalization -> amanaplanacanalpanama
    It is a palindrome.


    Sample Input 2:
    race a car

    Sample Output 2:
    Invalid
    */

    string s;
    getline(cin, s);

    cout << (isPalindrome(s) ? "Valid" : "Invalid");

    return 0;
}
