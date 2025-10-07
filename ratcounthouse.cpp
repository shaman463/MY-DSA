#include<iostream>

using namespace std;

int result(int r, int unit, int arr[], int n){
    if(n == 0) return -1;
    int total_Food = r*unit;
    int count = 0;
    for(int i = 0; i<n; i++){
        count += arr[i];
        if(count>= total_Food){
            return i+1;
        }
    }
    return 0;
}

int main() {

    int r = 7;
    int unit = 2;
    int arr[] = {2,8,3,5,7,4,1,2};
    int n = 8;
    int ans = result(r,unit,arr,n);
    cout<<ans<<endl;
    
    return 0;
}