#include<iostream>
#include<vector>

using namespace std;

class solution{
    public:
    vector<int> plusone(vector<int> &digits){
        int n = digits.size();
        for(int i = n-1; i>=0; i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
    return digits;
    }

};
int main(){

    solution sol;

    vector<int> digits = {1,2,3};
    vector<int> result = sol.plusone(digits);

    for(int num : result){
        cout<<num<<" ";
    }


    return 0;
}