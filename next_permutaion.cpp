// The reason we choose the rightmost larger element (rather than a larger element from the left)
//  is to ensure that the change we make is 
// the smallest possible change that results in the next lexicographical permutation
// Choosing the rightmost larger element is key to generating the smallest possible
//  increase (i.e., the next permutation). If we chose any other j to the left, it would create
//  a larger increase, leading to a permutation that is further down the lexicographical order.
// {1,2,3,6,5,4}
#include<iostream>

using namespace std;

void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int nextperm(int arr[], int n){
    int i = n-2;
    while(i>=0 && arr[i]>arr[i+1]){
        i--;
    }
    if(i>=0){
        int j = n-1;
        while(j>=0 && arr[j]<arr[i]){
            j--;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    reverse(arr,i+1,n-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    nextperm(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}