#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>>& arr, int i, int j, int row, int col) {
    if (i < 0 || j < 0 || i >= row || j >= col || arr[i][j] != 0)
        return;
    arr[i][j] = -1; // mark as visited

    dfs(arr, i+1, j, row, col);
    dfs(arr, i-1, j, row, col);
    dfs(arr, i, j+1, row, col);
    dfs(arr, i, j-1, row, col);
}

int minfind(int rows, int cols, int arr[][5]){
    vector<vector<int>> grid(rows, vector<int> (cols));

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            grid[i][j] = arr[i][j];
        }
    }
    int helicopter = 0;
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(grid[i][j] == 0){
                dfs(grid,i,j,rows,cols);
                helicopter++;
            }
        }
    }
    return helicopter;
}

int main() {
    int arr[4][5] = {
        {1,0,1,1,0},
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0}
    };
    cout << minfind(4,5,arr) << endl; 
    return 0;
}