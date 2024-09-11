 #include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];  
        if (map.find(complement) != map.end()) {
            cout << map[complement] << " " << i << endl;
            return 0;  
        }
        map[arr[i]] = i;
    }
    return 0;
}