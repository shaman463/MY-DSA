#include<iostream>

using namespace std;

int OperationsBinaryString(char* str){
    if (str == nullptr) return -1;

    int result = str[0] - '0'; // first digit

    for (int i = 1; str[i] != '\0'; i += 2) {
        char op = str[i];
        int next_digit = str[i + 1] - '0';

        if (op == 'A') {
            result = result & next_digit;
        } else if (op == 'B') {
            result = result | next_digit;
        } else if (op == 'C') {
            result = result ^ next_digit;
        } else {
            // Invalid character
            return -1;
        }
    }

    return result;
}

int main() {
    
    return 0;
}