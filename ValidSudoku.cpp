#include<bits/stdc++.h>
bool f1(int mat[][9], int row, int col, int k){
    for(int i = 0; i < 9; i++){
        if(mat[row][i] == k) return 0; 
        if(mat[i][col] == k) return 0;
        if(mat[3*(row/3) + i/3][3*(col/3) + i%3] == k) return 0; 
    }
    return 1; 
}
bool f(int mat[][9]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(mat[i][j] == 0){
                for(int k = 1; k <= 9; k++){
                    if(f1(mat, i, j, k)){
                        mat[i][j] = k; 
                        if(f(mat)) return 1; 
                        else mat[i][j] = 0; 
                    }
                }
                return 0; 
            }
        }
    }
    return 1; 
}
bool isItSudoku(int matrix[9][9]) {   
    // Write your code here.
    return f(matrix); 
}
