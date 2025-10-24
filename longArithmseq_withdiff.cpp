#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
       unordered_map<int, int> dp;
        int longest = 0;

        for (int x : arr) {
            dp[x] = dp[x - difference] + 1;
            longest = max(longest, dp[x]);
        }

        return longest;
    }
};

int main() {
    
    return 0;
}