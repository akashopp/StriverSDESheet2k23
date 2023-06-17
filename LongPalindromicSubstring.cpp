string longestPalinSubstring(string str)
{
    // Write your code here. 
    int l = 0, sz = 1, n = str.size();
    for(int i = 1; i < n; i++){
        int ind1 = i-1, ind2 = i; 
        while(ind1 >= 0 && ind2 < n && str[ind1] == str[ind2]){
            if(ind2 - ind1 + 1 > sz) l = ind1, sz = ind2 - ind1 + 1;
            ind1--, ind2++;
        }
        ind1 = i-1, ind2 = i+1; 
        while(ind1 >= 0 && ind2 < n && str[ind1] == str[ind2]){
            if(ind2 - ind1 + 1 > sz) l = ind1, sz = ind2 - ind1 + 1;
            ind1--, ind2++;
        }
    }
    string ans = str.substr(l, sz); 
    return ans;
}
