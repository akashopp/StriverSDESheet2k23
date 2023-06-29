int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
	string str = p + "#" + s;
	int l = 0, r = 0, ans = 0, len = str.size();
	vector<int>z(len, 0);
	for(int i = 1; i < len; i++){
		if(i > r){
			l = r = i;
			while(r < len && str[r] == str[r-l]) r++; 
			z[i] = r - l;
			r--;
		}else{
			int ind = i - l;
			if(i + z[ind] <= r) z[i] = z[ind];
			else{
				l = i;
				while(r < len && str[r] == str[r-l]) r++;
				z[i] = r - l;
				r--; 
			}
		}
	}
	for(int i = 0; i < len; i++) if(z[i] == m) ans++;
	return ans;
}
