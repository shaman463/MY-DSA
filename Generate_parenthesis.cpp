#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
       vector<string> ans;
       string current;
       backtrack(n,0,0,current,ans);
       return ans;
    }

    void backtrack(int n, int open, int close, string &current, vector<string> &ans){
        if(open == n && close == n){
            ans.push_back(current);
            return;
        }
        if(open<n){
            current.push_back('(');
            backtrack(n,open+1,close,current,ans);
            current.pop_back();
        }

        if (close < open) {
            current.push_back(')');
            backtrack(n, open, close + 1, current, ans);
            current.pop_back();
        }
    }
};