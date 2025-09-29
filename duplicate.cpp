#include <vector>
#include <unordered_set>
#include<iostream>

using namespace std;

int main(){

    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Print duplicates
    bool found = false;
    cout << "Duplicate elements: ";
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                cout << arr[i] << " ";
                found = true;
                break;
            }
        }
    }
    if(!found) cout << "None";
    cout << endl;

    // Remove duplicates
    vector<int> removeDuplicates(const vector<int>& arr);
    vector<int> uniqueArr = removeDuplicates(arr);
    cout << "Array after removing duplicates: ";
    for(int num : uniqueArr) cout << num << " ";
    cout << endl;
    return 0;

}

vector<int> removeDuplicates(const vector<int>& arr) {
    unordered_set<int> seen;
    vector<int> result;
    for(int num : arr) {
        if(seen.find(num) == seen.end()) {
            result.push_back(num);
            seen.insert(num);
        }
    }
    return result;
}