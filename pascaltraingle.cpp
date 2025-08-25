// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> pascal(numRows);

//         for(int i = 0; i<numRows;i++){
//             pascal[i].resize(i+1);
//             pascal[i][0] = pascal[i][i] = 1;

//             for(int j = 1; j<i; j++){
//                 pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
//             }
//         }
//         return pascal;
//     }
// };



//-------------------------------------------------pascal traingle 2

// class Solution {
// public:
//     vector<int> getRow(int rowIndex) {
//         vector<int> row(rowIndex + 1, 0);
//         row[0] = 1;  
        
//         for (int i = 1; i <= rowIndex; i++) {
//             for (int j = i; j > 0; j--) {
//                 row[j] = row[j] + row[j-1];
//             }
//         }
        
//         return row;
//     }
// };