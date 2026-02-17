#include <bits/stdc++.h>
using namespace std;

pair<int, int> sumPosNeg(const vector<int> &arr){
   
    int negSum = 0, posSum = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] < 0) negSum += arr[i];
        else posSum += arr[i];
    }

    return {posSum, negSum}; //way 1

    // pair<int,int> ans;
    // ans = {posSum, negSum}; //way 2
    // ans = make_pair(posSum, negSum); // way 3

    // ans.first = posSum;
    // ans.second = negSum; //way 4
    // return ans;
}

int main() {

    vector<int> arr = {1, 2, 3, -1, -2};
    pair<int,int> ans = sumPosNeg(arr);

    cout << ans.first << ", " << ans.second ;
}
