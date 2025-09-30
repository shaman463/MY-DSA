#include<iostream>
#include<vector>
using namespace std;

bool isjump(vector<int> &nums){
    int maxreach = 0;
    for(int i = 0 ; i< nums.size(); i++){
        if(i>maxreach) return false;
        maxreach = max(maxreach, i+ nums[i]);
    }
    return true;
}

int isjump2(vector<int> &nums){
    int farthest = 0; 
    int end = 0;
    int jump = 0 ;
    for(int i = 0; i < nums.size()-1;i++){
        farthest = max(farthest, i+nums[i]);
        if(i == end){
            jump++;
            end = farthest;
        }
    }
    return jump;
}

int main() {

    vector<int> nums = {2,3,1,1,4};

    if(isjump(nums)){
        cout<<"it is valid"<<endl;
    }else{
        cout<<"it is not valid"<<endl;
    }

    int ans = isjump2(nums);
    cout<< "the answer is : "<< ans <<endl;
    
    return 0;
}