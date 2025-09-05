#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        
        if (nums.empty()) return result;

        int start = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            // Use safe check to avoid overflow
            if (i == nums.size() - 1 || nums[i + 1] != nums[i] + 1) {
                
                // If start == nums[i], it's a single number
                if (start == nums[i]) {
                    result.push_back(to_string(start));
                } else {
                    result.push_back(to_string(start) + "->" + to_string(nums[i]));
                }

                // Update start for next range if not at last element
                if (i != nums.size() - 1) {
                    start = nums[i + 1];
                }
            }
        }

        return result;
    }
};

int main() {
    
    return 0;
}