#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;  

        int left = 0;
        int right = nums.size() - 1;  

        while (left <= right) {  
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                
                int first = mid;
                int last = mid;

                int l = left;
                int r = mid - 1;
                while (l <= r) {
                    int mid2 = (l + r) / 2;
                    if (nums[mid2] == target) {
                        first = mid2;
                        r = mid2 - 1;  // move left
                    } else if (nums[mid2] < target) {
                        l = mid2 + 1;
                    } else {
                        r = mid2 - 1;
                    }
                }

                l = mid + 1;
                r = right;
                while (l <= r) {
                    int mid2 = (l + r) / 2;
                    if (nums[mid2] == target) {
                        last = mid2;
                        l = mid2 + 1;  // move right
                    } else if (nums[mid2] < target) {
                        l = mid2 + 1;
                    } else {
                        r = mid2 - 1;
                    }
                }

                result.push_back(first);
                result.push_back(last);
                return result; 
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
};

int main() {
    
    return 0;
}