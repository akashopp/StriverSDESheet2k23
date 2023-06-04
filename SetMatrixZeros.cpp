#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size(), m = matrix[0].size();
	vector<bool>row(n), col(m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!matrix[i][j]) row[i] = col[j] = 1;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(row[i] || col[j]) matrix[i][j] = 0;
		}
	}
}
