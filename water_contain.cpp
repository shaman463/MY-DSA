#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 

int Are_a(vector<int>& arr){
    int left = 0;
    int right = arr.size()-1;
    int max_water = 0;

    while(left<right){
        int width = right - left;
        int area = min(arr[left], arr[right])*width;

        max_water = max(max_water, area);

        if (arr[left] < arr[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max_water;
}

int main(){

    vector<int> arr = {1,3,5,7,9};
    int result = Are_a(arr);

    cout<<result<<endl;

    return 0;
}