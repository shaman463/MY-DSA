#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int area(vector<int>&height){
    int left = 0;
    int right = height.size()-1;
    int conatiner = INT_MIN;

    while(left<right){
        int breadth = right - left;
        int area = min(height[left],height[right])*breadth;

        conatiner = max(area,conatiner);

        if(height[right]<height[left]){
            right--;
        }
        else{
            left++;
        }
    }
    return conatiner;
}

int main(){

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    int answer = area(height);
    cout<<answer<<endl;

    return 0;
}