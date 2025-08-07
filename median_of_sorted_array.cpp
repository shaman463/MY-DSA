#include<iostream>
#include<climits>
using namespace std;
// well this not an optimal solution because it is taking so much time 
// O(m+n)

// void result(int arr1[] , int arr2[], int n1, int n2, int mergerd[]){
//     int i = 0 , j = 0;
//     int k = 0;
//     while (i < n1 && j < n2){
//         if (arr1[i] < arr2[j]){
//             mergerd[k++] = arr1[i++];
//         }else{
//             mergerd[k++] = arr2[j++];
//         }
//     }

//     while (i < n1){
//         mergerd[k++] = arr1[i++];
//     }

//     while (j < n2){
//         mergerd[k++] = arr2[j++];
//     }
// }

// double findMedian(int merged[], int size) {
//     if (size % 2 == 0)
//         return (merged[size/2 - 1] + merged[size/2]) / 2.0;
//     else
//         return merged[size/2];
// }

// int main() {  

//     int n1;
//     cout<<"Enter the number for first array :"<<endl;
//     cin>>n1;
//     int arr1[n1];
//     int n2;
//     cout<<"Enter the number for second array :"<<endl;
//     cin>>n2;
//     int arr2[n2];
//     cout<<"Enter the values of first array :"<<endl;
//     for(int i = 0; i<n1; i++){
//         cin>>arr1[i];
//     }
//     cout<<"Enter the values of second array :"<<endl;
//     for(int i = 0; i<n2; i++){
//         cin>>arr2[i];
//     }
//     int merged[n1+n2];
//     result(arr1, arr2, n1, n2, merged);
//      for (int i = 0; i < n1 + n2; i++)
//         cout << merged[i] << " ";
//      cout << "\nMedian: " << findMedian(merged, n1 + n2) << endl;
//     return 0;

// }


/** 
 This question can be solve by using binary search. Here's how

x = x1 x2 x3 x4 x5 x6
y = y1 y2 y3 y4 y5 y6 y7 y8 

Partition this array in two halves such that elements on the left side are less than
or equal to all elements on the right side
like if we divide the x array x1 x2 | x3 x4 x5 x6 
and the y array as            y1 y2 y3 y4 y5 | y6 y7 y8  we can clearly see the no. of element on both the sides are equal
                       
                                   7             7
from the above array the median should be around here
x2 | x3  or  y5 | y6

we are doing this because we are finding a partition point where left side contain smaller or equal values
we will never have to compare all values just the boundary values.
this gives the time  log(min(n1,n2))

Now we do binary search on smaller of the two array and try to find such point 
such that every element on the left side is less than or equal to thr right side


we partition A at index i and B at index j, so that:
i + j = (n1 + n2 + 1) / 2


if (A[i-1] <= B[j] && B[j-1] <= A[i])
if this is true we have found the correct partition

If total number of elements is even:
median = (max(A[i-1], B[j-1]) + min(A[i], B[j])) / 2.0

If total number of elements is odd:
median = max(A[i-1], B[j-1])

*/

double findMedianSortedArrays(int A[], int n1, int B[], int n2){
    if(n1 > n2){
        findMedianSortedArrays(B,n2,A,n1);
    }

    int total = n1 + n2;
    int low = 0;
    int high = n1;

    while(low <= high){
        int partitionA = (low + high)/2;
        int partitionB = (total + 1)/2 - partitionA;


        int maxLeftA = (partitionA == 0) ? INT_MIN : A[partitionA-1];
        int minRightA = (partitionA == n1) ? INT_MAX : A[partitionA];

        int maxLeftB = (partitionB == 0) ? INT_MIN : B[partitionB-1];
        int minRightB = (partitionB == n2) ? INT_MAX : B[partitionB];

        if(maxLeftA <= minRightB && maxLeftB <= minRightA){
            if(total % 2 == 0){
                return (max(maxLeftA,maxLeftB)+ min(minRightA , minRightB)) / 2.0;
            }else{
                return max(maxLeftA , maxLeftB);
            }
        }
        else if(maxLeftA > minRightB){
            high = partitionA - 1;
        }
        else{
            low = partitionA + 1;
        }
    }

    return -1;
}

int main(){

  int arr1[] = {1, 3, 8};
    int arr2[] = {7, 9, 10, 11};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Median is: " << findMedianSortedArrays(arr1, n1, arr2, n2) << endl;


    return 0;
}
