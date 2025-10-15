#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int findmin(char* input1){
    int n = strlen(input1);

    vector<int> dp(n+1, INT_MAX);

    dp[0] = 0;

    for(int i = 1; i<=n; i++){
        dp[i] = dp[i-1] + 1;

        for(int len = 1; len<=i/2; len++){
            if(strncmp(input1, input1 + i - len,len)==0){
                dp[i] = min(dp[i], dp[i - len] + 1);
            }
        }
    }
    return dp[n];
}

int main() {

    char s[] = "abcabc";
    cout << findmin(s) << endl; // Output: 4
    return 0;
    
    return 0;
}