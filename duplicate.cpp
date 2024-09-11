#include<iostream>

using namespace std;

int  duplicate(int arr[], int n){
    int uniquearray = 0;

    for(int i=1; i<n; i++){
        if(arr[i] != arr[uniquearray]){
            uniquearray++;
            arr[uniquearray] = arr[i];
        }
    }

    return uniquearray + 1;
}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i<n; i++){
        cin>>arr[n];
    }

    int result = duplicate(arr, n);

     for (int i = 0; i < result; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}




