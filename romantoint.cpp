#include<iostream>
#include<vector>
#include <unordered_map>


using namespace std;

class solution{
    public:
    int romantoint(string s){
        unordered_map<char ,int> map = {
             {'I', 1},
             {'V', 5},
             {'X', 10},
             {'L', 50},
             {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        int prevValue = 0;

        for(int i = s.length()-1; i>=0;i--){
            int currentValue = map[s[i]];
        
        if (currentValue >= prevValue) {
            total += currentValue;  
        } else {
            total -= currentValue;  
        }
        
        prevValue = currentValue;   
        }
        return total;
    }
};

int main(){

    solution sol;
    string roman = "MCMXCIV";

    cout<<sol.romantoint(roman)<<endl;


    return 0;
}