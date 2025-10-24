#include <iostream>
using namespace std;

// Function to sort an array using selection sort
void sortArray(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        // Swap
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

int minHabitats(int entry[], int exit[], int n) {
    sortArray(entry, n);
    sortArray(exit, n);

    int i = 0, j = 0;
    int current = 0, max_habitats = 0;

    while(i < n) {
        if(entry[i] <= exit[j]) {
            current++;
            if(current > max_habitats) max_habitats = current;
            i++;
        } else {
            current--;
            j++;
        }
    }
    return max_habitats;
}

int main() {
    int entryHabitat[] = {1, 2, 3, 1, 4, 5};
    int exitHabitat[]  = {3, 4, 5, 2, 6, 7};
    int n = sizeof(entryHabitat) / sizeof(entryHabitat[0]);

    cout << "Minimum habitats required: " << minHabitats(entryHabitat, exitHabitat, n) << endl;
    return 0;
}
