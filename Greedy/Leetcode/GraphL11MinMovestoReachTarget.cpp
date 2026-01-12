#include <bits/stdc++.h>
using namespace std;

// T.C - O(log(target) + maxDoubles)
// S.C - O(1)

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;

        while(target > 1){
            if(maxDoubles == 0){
                // only decrement allowed
                int steps = target - 1;
                target = 1;
                moves = moves + steps;
                break;
            }
            else{
                if(target & 1){
                    // odd -> subtract 1
                    target--;
                    moves++;
                }
                else{
                    // even -> divide by 2
                    target = target >> 1;
                    maxDoubles--;
                    moves++;
                }
            }
        }
        return moves;
    }
};

int main() {

    /*
    Sample Input:
    10 4

    Sample Output:
    4

    Explanation:
    10 -> 5 -> 4 -> 2 -> 1
    */

    int target, maxDoubles;
    cin >> target >> maxDoubles;

    Solution s;
    cout << "Output: " << s.minMoves(target, maxDoubles) << endl;

    return 0;
}
