vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
	int d = 256;
	int n = text.size(), m = pattern.size(), mod = INT_MAX, h = (int)pow(d, m-1);
	vector<int>res;
	int x = 0, y = 0; 
	for(int i = 0; i < m; i++){
		x = (d * x + pattern[i]) % mod; 
		y = (d * y + text[i]) % mod;
	}
	for(int i = 0; i <= n - m; i++){
		if(x == y){
			int ind = 0;
			while(ind < m){
				if(text[i + ind] != pattern[ind]) break;
				ind++;
			}
			if(ind == m) res.push_back(i + 1);
		}
		if(i < n - m){
			y = (d * (y - text[i] * h) + text[i + m]) % mod;
		}
		if(y < 0) y += mod; 
	}
	return res;
}

