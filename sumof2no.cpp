 #include <iostream>
#include <unordered_map>
using namespace std;

void sumof(int arr[],int target,int n){
    for(int i = 0; i<n-1;i++){
        for(int j = i+1; j<n;j++){
            if(arr[i]+arr[j]==target){
                cout<<"target found at index : "<< i <<"and"<< j<<endl;
            }
        }
    }
}

int main(){
    int arr[] = {2, 7, 11, 15};
    int target = 9;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    sumof(arr, target, n); // Output: Target found at index: 0 and 1
}


// int main() {
//     int n, target;
//     cin >> n >> target;

//     int arr[n];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     unordered_map<int, int> map;
//     for (int i = 0; i < n; i++) {
//         int complement = target - arr[i];  
//         if (map.find(complement) != map.end()) {
//             cout << map[complement] << " " << i << endl;
//             return 0;  
//         }
//         map[arr[i]] = i;
//     }
//     return 0;
// }