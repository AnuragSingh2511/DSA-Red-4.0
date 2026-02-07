#include <iostream>
#include <string>
using namespace std;

// T.C - O(N^2)
// S.C - O(1)

class Solution {
public:
    int checkPalindrome(string s, int i, int j){
        int count = 0;
        while(i >= 0 && j < s.length() && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int count = 0;
        for(int centre = 0; centre < s.length(); centre++){
            // odd length palindromes
            int i = centre;
            int j = centre;
            int oddLenPalindromeCount = checkPalindrome(s, i, j);

            // even length palindromes
            i = centre;
            j = centre + 1;
            int evenLenPalindromeCount = checkPalindrome(s, i, j);

            count += oddLenPalindromeCount + evenLenPalindromeCount;
        }
        return count;
    }
};

int main() {

    /*
    Sample Input:
    aaa

    Sample Output:
    6

    Explanation:
    Palindromic substrings are:
    "a", "a", "a", "aa", "aa", "aaa"
    */

    string s;
    cin >> s;

    Solution sol;
    cout << "Output: " << sol.countSubstrings(s) << endl;

    return 0;
}
