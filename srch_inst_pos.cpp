#include<iostream>
#include<vector>

using namespace std;

int searchInsert(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;  // Target found, return its index
        } else if (nums[mid] < target) {
            left = mid + 1;  // Move to the right half
        } else {
            right = mid - 1;  // Move to the left half
        }
    }
    
    // If target is not found, return the insertion point
    return left;
}



int main(){

    vector<int> nums = {1,3,5,7,9};
    int target = 2;

    int k = searchInsert(nums,target);

    cout<<k<<endl;

    return 0;
}