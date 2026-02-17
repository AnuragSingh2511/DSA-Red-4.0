#include <bits/stdc++.h>
using namespace std;

vector<int>printExtremeElementsAlternately(vector<int>& arr) { 
        vector<int> ans;
        sort(arr.begin(), arr.end());   

        int i = 0; int j = arr.size() - 1;
        while(i <= j){
            if(i == j) ans.push_back(arr[i++]);
            else{
            ans.push_back(arr[i++]);
            ans.push_back(arr[j--]);
            }            
        }
        return ans;
}

int main() {

    vector<int> arr = {5, 4, 3, 2, 1};
    vector<int> ans = printExtremeElementsAlternately(arr);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}
