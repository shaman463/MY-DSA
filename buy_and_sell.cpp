#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// buy and sell stock3

int maxProfit(vector<int> &prices)
{
    if (prices.empty())
        return 0;

    int buy1 = INT_MIN, sell1 = 0;
    int buy2 = INT_MIN, sell2 = 0;

    for (int price : prices)
    {
        // First transaction
        buy1 = max(buy1, -price);
        sell1 = max(sell1, buy1 + price); // Max profit after first sell

        // Second transaction
        buy2 = max(buy2, sell1 - price);  // Max money left after second buy
        sell2 = max(sell2, buy2 + price); // Max profit after second sell
    }

    return sell2;
}

// buy and sell stock2

int maxProfit(vector<int> &prices)
{
    int totalProfit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
        {
            totalProfit += prices[i] - prices[i - 1];
        }
    }

    return totalProfit;
}

int maxprofit(vector<int> &prices)
{

    int min_profit = INT_MAX;
    int max_profit = INT_MIN;
    int price;

    for (int i = 0; i < prices.size(); i++)
    {
        price = prices[i];
        if (price < min_profit)
        {
            min_profit = price;
        }

        int profit = price - min_profit;
        if (profit > max_profit)
        {
            max_profit = profit;
        }
    }
    return max_profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int result = maxprofit(prices);
    cout << "Maximum profit: " << result << endl;

    return 0;
}