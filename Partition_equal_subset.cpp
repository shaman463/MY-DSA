#include <iostream>
#include <vector>

using namespace std;

bool canpartition(vector<int> &nums){
    int sum = 0;
    for (int n : nums)
        sum += n;
    if (sum % 2 != 0)
        return false;
    
    int target = sum / 2;

    int n = nums.size();

    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int num : nums)
    {
        for (int j = target; j >= num; j--)
        {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    return dp[target];
}

int main()
{
    vector<int> p = {1, 5, 11, 5};
    return 0;
}