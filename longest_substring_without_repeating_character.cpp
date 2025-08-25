#include<iostream>
#include<unordered_set>
using namespace std;

int longest_substring(string s){
    int maxlen = 0;
    int left = 0;
    unordered_set<char> seen;

    for(int i = 0; i<s.length(); i++){
        while(seen.count(s[i])){
            seen.erase(s[left]);
            left++;
        }
        seen.insert(s[i]);
        maxlen = max(maxlen, i - left + 1);
    }
    return maxlen;
}

int main() {

    string s = "abcabccbb";

    int result = longest_substring(s);
    cout<<result;
    
    return 0;
}