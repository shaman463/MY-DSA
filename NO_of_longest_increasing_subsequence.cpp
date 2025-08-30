#include<iostream>
#include<vector>
using namespace std;

 int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n,1), count(n,1);
        int maxlen = 1, result = 0;

        for(int i= 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[j]<nums[i]){
                    if(length[j] + 1 >length[i]){
                        length[i] = length[j] + 1;
                        count[i] = count[j];
                    }
                    else if(length[j] + 1 == length[i]){
                        count[i] += count[j];
                    }
                }
            }
            maxlen = max(maxlen, length[i]);
        }
        for(int i= 0; i<n; i++){
            if(length[i] == maxlen){
                result += count[i];
            }
        }
        return result;
    }

int main() {
    
    return 0;
}