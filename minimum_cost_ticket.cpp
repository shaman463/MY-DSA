#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int minimum_cost(vector<int>&days, vector<int>&costs){
    vector<int>dp(367, 0);

    unordered_set<int> travel(days.begin(), days.end());

    for(int day = 365; day>=1; day--){
        if(travel.find(day) == travel.end()){
            dp[day] = dp[day + 1];
        }
        else{
            int cost1 = costs[0] + dp[min(366,day+1)];
            int cost7= costs[1] + dp[min(366,day+7)];
            int cost30 = costs[2] + dp[min(366,day+30)];

            dp[day] = min({cost1, min(cost7, cost30)});
        }
    }
    return dp[1];
}

int main() {
    vector <int> days{1,4,6,7,8,20};
    vector <int> costs{2,7,15};

    cout<< "Minimum cost is :"<< minimum_cost(days,costs)<<endl;
    return 0;
}