#include<iostream>
#include<vector>

using namespace std;

int remove_ele(vector<int>&num,int val){
    int k = 0;

    for(int i = 0; i<num.size();i++){
        if(num[i]!=val){
            num[k] = num[i];
            k++;
        }
    }

    return k;
}

int main(){

    vector<int>num = {3,2,2,3};
    int val = 3;
    int k = remove_ele(num,val);

    cout<<"Modified array"<<endl;

    for(int i = 0; i< k;i++){
        cout<<num[i];
    }

    return 0;
}