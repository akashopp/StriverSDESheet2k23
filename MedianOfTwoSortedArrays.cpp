double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	int n = a.size(), m = b.size(); 
	double ans = 0.00; 
	int k = (n + m + 1)/2, low = 0, high = min(n, k); 
	while(low <= high){
		int cut1 = low + (high - low)/2, cut2 = k - cut1; 
		int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX; 
		if(cut1 - 1 >= 0) l1 = a[cut1 - 1]; 
		if(cut1 < n) r1 = a[cut1];
		if(cut2 - 1 >= 0) l2 = b[cut2 - 1]; 
		if(cut2 < m) r2 = b[cut2]; 
		if(l1 <= r2 && l2 <= r1){
			if((n + m)&1) ans = min(max(l1, l2), min(r1, r2)); 
			else ans = (max(l1, l2) + min(r1, r2))*1.00/2.00;
			break;
		}else if(l1 > r2) high = cut1 - 1; 
		else low = cut1 + 1; 
	}
	return ans; 
}
