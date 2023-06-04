#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int top = 0, bottom = n-1, left = 0, right = m-1; 
    while(left < right && top < bottom){
        int cur = mat[top+1][left]; 
        for(int i = left; i <= right; i++) swap(mat[top][i], cur);
        top++;
        for(int i = top; i <= bottom; i++) swap(mat[i][right], cur); 
        right--; 
        if(top <= bottom){
            for(int i = right; i >= left; i--) swap(mat[bottom][i], cur); 
            bottom--; 
        }
        if(left <= right){
            for(int i = bottom; i >= top; i--) swap(mat[i][left], cur); 
            left++; 
        }
    }
}
