#include <iostream>
#include <vector>
#include <string>
using namespace std;

// T.C - O(N + L)
// S.C - O(1)
// N = number of houses
// L = total number of garbage items (characters)

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // P truck
        int pickP = 0;
        int lastHouseP = 0;

        // G truck
        int pickG = 0;
        int lastHouseG = 0;

        // M truck
        int pickM = 0;
        int lastHouseM = 0;

        // count pickups and last houses
        for(int i = 0; i < garbage.size(); i++){
            string currHouseGarbage = garbage[i];
            for(int j = 0; j < currHouseGarbage.length(); j++){
                char garbageType = currHouseGarbage[j];
                if(garbageType == 'P'){
                    pickP++;
                    lastHouseP = i;
                }
                else if(garbageType == 'M'){
                    pickM++;
                    lastHouseM = i;
                }
                else if(garbageType == 'G'){
                    pickG++;
                    lastHouseG = i;
                }
            }
        }

        int travelP = 0, travelG = 0, travelM = 0;

        for(int i = 0; i < lastHouseP; i++){
            travelP += travel[i];
        }
        for(int i = 0; i < lastHouseG; i++){
            travelG += travel[i];
        }
        for(int i = 0; i < lastHouseM; i++){
            travelM += travel[i];
        }

        int totalTime = (pickP + pickG + pickM) +
                        (travelP + travelG + travelM);

        return totalTime;
    }
};

int main() {

    /*
Sample Input:
3
G
P
GP
2
2 4

Sample Output:
16
*/


    int n;
    cin >> n;

    vector<string> garbage(n);
    for(int i = 0; i < n; i++){
        cin >> garbage[i];
    }

    int m;
    cin >> m;   // travel array size = n-1

    vector<int> travel(m);
    for(int i = 0; i < m; i++){
        cin >> travel[i];
    }

    Solution sol;
    cout << "Output: " << sol.garbageCollection(garbage, travel) << endl;

    return 0;
}
