#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int ind1 = n - 2; 
    while(ind1 >= 0 && permutation[ind1] >= permutation[ind1 + 1]) ind1--;
    if(ind1 >= 0){
        int ind2 = n - 1;
        while(permutation[ind1] >= permutation[ind2]) ind2--; 
        swap(permutation[ind1], permutation[ind2]); 
    }
    reverse(permutation.begin() + ind1 + 1, permutation.end()); 
    return permutation;
}
