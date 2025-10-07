#include<iostream>

using namespace std;

int maximumwaterdrink(int numbottles, int extractbottle){
    int empty = numbottles;
    int total = numbottles;
    while(empty>=extractbottle){
        int remaining = empty / extractbottle;
        total += remaining;
        empty = remaining + (empty % extractbottle);
    }
    return total;
}

int main() {

    int answer = maximumwaterdrink(9,3);
    cout<< answer << endl;
    
    return 0;
}