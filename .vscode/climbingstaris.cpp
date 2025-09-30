#include<iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int a = 1;
        int b = 2;
        int ways = 0;
        for(int i = 3; i<=n; i++){
            ways = a + b;
            a = b; 
            b = ways;
        }
        return b;
    }
};

int main() {
    
    return 0;
}