#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// T.C - O(K + M)
// S.C - O(M)
// K = length of key, M = length of message

class Solution {
public:

    void createMapping(unordered_map<char,char> &mapping, string key){
        char start = 'a';

        for(int i = 0; i < key.length(); i++){
            char ch = key[i];
            // store mapping only if not already present
            if(mapping.find(ch) == mapping.end()){
                mapping[ch] = start;
                start++;
            }
        }
    }

    string useMapping(unordered_map<char,char> &mapping, string message){
        string s = "";
        for(int i = 0; i < message.length(); i++){
            char ch = message[i];
            char mappedCharacter = mapping[ch];
            s.push_back(mappedCharacter);
        }
        return s;
    }

    string decodeMessage(string key, string message) {
        unordered_map<char,char> mapping;

        // map space to space
        mapping[' '] = ' ';

        // step 1: create mapping
        createMapping(mapping, key);

        // step 2: decode message
        string ans = useMapping(mapping, message);
        return ans;
    }
};

int main() {

    /*
    Sample Input:
    the quick brown fox jumps over the lazy dog
    vkbs bs t suepuv

    Sample Output:
    this is a secret

    i/p: the 
         eht
    o/p: cba
    */

    string key;
    getline(cin, key);

    string message;
    getline(cin, message);

    Solution sol;
    cout << "Output: " << sol.decodeMessage(key, message) << endl;

    return 0;
}
