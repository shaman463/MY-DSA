#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int maxSum = INT_MIN;

        for (int num : nums) {
        // Decide whether to add to existing sum or start fresh
            currentSum = max(num, currentSum + num);
        
        // Update maxSum if needed
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};

int main() {
    
    return 0;
}