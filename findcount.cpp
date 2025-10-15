#include <iostream>

using namespace std;

int differenceofSum(int n, int m)
{
    int first = 0, second = 0;
    for (int i = 1; i <= m; i++)
    {
        if (i % n == 0)
        {
            first += i;
        }
        else
        {
            second += i;
        }
    }
    if(second < first){
        return first - second;
    }
    else{
        return second - first;
    }
    
}

int findCount(int n, int arr[], int num, int diff)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (abs(arr[i] - num) <= diff)
        {
            count++;
        }
    }
    return count > 0 ? count : -1;
}

int main()
{
    int ans = differenceofSum(4,20);
    cout<<ans;
    return 0;
}