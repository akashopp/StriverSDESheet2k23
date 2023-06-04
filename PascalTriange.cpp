#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>>vec(n); 
  for(int i = 0; i < n; i++){
    vec[i].resize(i+1);
    for(int j = 0; j <= i; j++){
      if(j == 0 || j == i) vec[i][j] = 1;
      else vec[i][j] = vec[i-1][j] + vec[i-1][j-1];
    }
  }
  return vec;
}
