#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int maxprofit(vector<int> &prices){

    int min_profit = INT_MAX;
    int max_profit = INT_MIN;
    int price;

    for(int i = 0; i<prices.size(); i++){
        price = prices[i];
        if(price<min_profit){
            min_profit = price;
        }

        int profit = price - min_profit;
        if (profit > max_profit) {
            max_profit = profit;
        }
    }
    return max_profit;
}

int main(){

    vector<int> prices = {7,1,5,3,6,4};

    int result = maxprofit(prices);
    cout << "Maximum profit: " << result << endl;

    return 0;
}