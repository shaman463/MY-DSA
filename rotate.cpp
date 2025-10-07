#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// another approach

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // in case k > n

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n = nums.size();
        k = k % n;  // handle cases when k > n

        vector<int> firsthalf;
        vector<int> secondhalf;

        // Split the array into two parts based on index
        for (int i = 0; i < n - k; i++) {
            firsthalf.push_back(nums[i]);
        }
        for (int i = n - k; i < n; i++) {
            secondhalf.push_back(nums[i]);
        }

        // Combine the second half (last k elements) + first half
        secondhalf.insert(secondhalf.end(), firsthalf.begin(), firsthalf.end());

        // Assign result back to nums
        nums = secondhalf;
    }
};

int main() {
    
    return 0;
}