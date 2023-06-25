string kthPermutation(int n, int k) {
    // Write your code here.
    int fact = 1;
    string ans;
    vector<int>vec;
    for(int i = 1; i < n; i++) vec.push_back(i), fact *= i; 
    vec.push_back(n);
    k--; 
    while(true){
        ans += to_string(vec[k / fact]);
        vec.erase(vec.begin() + k / fact);
        if(vec.empty()) break;
        k = k % fact; 
        fact = fact / vec.size();
    }
    return ans;
}
