#include<iostream>
#include<vector>
using namespace std;

// this method is done with recurion but is not optimal because it takes time
// and redo all the iteration again and again so we use memoization

// int mincoin(vector<int>&coins , int amount){
//     if(amount==0){
//         return 0;
//     }
//     int ans = INT_MAX; 
//     for(int coin : coins){
//         if(amount - coin >= 0)
//         ans = min(ans, mincoin(coins,amount - coin) + 1);
//     }
//     return ans;
// }

// int main(){
//     vector<int> coin = {1,2,5};
//     int result = mincoin(coin,11);
//     cout<<"the answer is : "<<result<<endl;
//     return 0;

// }

// this code is now optimal 


// int mincoin(vector<int>& coins, int amount, vector<int>& dp) {
//     if(amount == 0) return 0;
//     if(dp[amount] != -1) return dp[amount]; // already solved
    
//     int ans = INT_MAX;
//     for(int coin : coins){
//         if(amount - coin >= 0){
//             int sub = mincoin(coins, amount - coin, dp);
//             if(sub != INT_MAX) // avoid overflow
//                 ans = min(ans, sub + 1);
//         }
//     }
//     return dp[amount] = ans; // store result
// }

// int main(){
//     vector<int> coins = {1,2,5};
//     int amount = 11;
//     vector<int> dp(amount+1, -1);
//     int result = mincoin(coins, amount, dp);
//     cout << "The answer is : " << result << endl;
//     return 0;
// }



//--------------------coin change 2 --------------------------------->


int solve(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {
    if(amount == 0) return 1; // found a way
    if(idx < 0) return 0;     // no coins left
    if(dp[idx][amount] != -1) return dp[idx][amount];

    int ways = 0;
    // pick 0,1,2,... coins[idx]
    for(int take = 0; take <= amount; take += coins[idx]) {
        ways += solve(idx - 1, amount - take, coins, dp);
    }
    return dp[idx][amount] = ways;
}

int main() {
    vector<int> coins = {1,2,5};
    int amount = 5;
    vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));

    cout << "Number of combinations: " << solve(coins.size()-1, amount, coins, dp) << endl;
    return 0;
}