#include <bits/stdc++.h>
using namespace std;

// T.C - O(n)
// S.C - O(n)

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        queue<int> q;
        unordered_map<int, bool> vis;

        // initial state
        q.push(start);
        vis[start] = 1;

        // BFS
        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            if (arr[front] == 0)
            {
                return true;
            }
            else
            {
                int plus = front + arr[front];
                int minus = front - arr[front];

                if (plus >= 0 && plus < arr.size() && vis[plus] == 0)
                {
                    q.push(plus);
                    vis[plus] = 1;
                }
                if (minus >= 0 && minus < arr.size() && vis[minus] == 0)
                {
                    q.push(minus);
                    vis[minus] = 1;
                }
            }
        }
        // no index with value 0 reachable
        return false;
    }
};

int main()
{

    Solution s; // object creation to call non-static member function

    int n;
    cin >> n;
    /*
    n
    array elements
    start
    7               
    4 2 3 0 3 1 2
    5
    */

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int start;
    cin >> start;

    // cout << s.canReach(arr, start); // 1 or  0

    cout << boolalpha << s.canReach(arr, start);

    // cout << (s.canReach(arr, start) ? "true" : "false");


    return 0;
}
