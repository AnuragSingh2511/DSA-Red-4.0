#include <bits/stdc++.h>
using namespace std;

// T.C - O(N * L + V + E)
// S.C - O(V + E)
//
// N = number of words
// L = average length of word
// V = unique characters
// E = precedence relations

class Solution {
public:
    string findOrder(vector<string>& words) {

        unordered_map<char, bool> charFound;
        unordered_map<char, vector<char>> adjList;
        unordered_map<char, int> indegree;

        // Step 1: collect all characters
        for (auto &word : words) {
            for (char ch : word) {
                charFound[ch] = true;
                indegree[ch] = 0;   // IMPORTANT initialization
            }
        }

        int totalNodes = charFound.size();

        // Step 2: build graph by comparing adjacent words
        for (int i = 0; i + 1 < words.size(); i++) {
            string word1 = words[i];
            string word2 = words[i + 1];

            int minLen = min(word1.size(), word2.size());
            int j = 0;

            while (j < minLen && word1[j] == word2[j]) {
                j++;
            }

            // normal case
            if (j < minLen) {
                char u = word1[j];
                char v = word2[j];
                adjList[u].push_back(v);
                indegree[v]++;
            }
            // invalid case: word2 is prefix of word1
            else if (word1.size() > word2.size()) {
                return "";
            }
        }

        // Step 3: Kahn's Algorithm (BFS Topo)
        queue<char> q;
        for (auto &p : charFound) {
            if (indegree[p.first] == 0) {
                q.push(p.first);
            }
        }

        string ans = "";

        while (!q.empty()) {
            char front = q.front();
            q.pop();
            ans.push_back(front);

            for (char nbr : adjList[front]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        return (ans.length() == totalNodes) ? ans : "";
    }
};

int main() {

    /*
    Sample Input:
    5
    aa aab ab b babbb

    Sample Output:
    true
    (Any valid order string is accepted)
    */

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    Solution s;
    string result = s.findOrder(words);

    if (result == "")
        cout << "false";
    else
        cout << "true";

    return 0;
}
