#include<iostream>

using namespace std;

string longestPalindrome(string s){
    string result = "";

    if(s.length()<=1){
        return s;
    }

    for(int i= 0; i < s.length(); i++){

        // for odd length
        int low = i;
        int high = i;

         while (low >= 0 && high < s.length() && s[low] == s[high]) {
            low--;
            high++;
        }

        string palindrome = s.substr(low+1,high - low - 1);
        if(palindrome.length() > result.length()){
            result = palindrome;
        }


        // for even length
        low = i-1;
        high = i;
         while (low >= 0 && high < s.length() && s[low] == s[high]) {
            low--;
            high++;
        }

        palindrome = s.substr(low+1,high - low - 1);
        if(palindrome.length() > result.length()){
            result = palindrome;
        }
    }
    return result;
}

int main() {
    
    string s = "ABRBADAADAB";

    string result = longestPalindrome(s);

    cout << "Longest Palindromic Substring: " << result << " and it's length is " << result.length()<< endl;
    return 0;
}