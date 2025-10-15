#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n = nums.size();
    if (n <= 2) return n; // already valid

    int i = 2; // start from index 2 (first two are always allowed)
    for (int j = 2; j < n; j++) {
        if (nums[j] != nums[i - 2]) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i; 
    }
};

int main() {
    
    return 0;
}