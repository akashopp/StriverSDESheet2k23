int minCharsforPalindrome(string str) {
	// Write your code here.
	int n = str.size(), i = 0, j = n-1, ans = 0;
	while(i < j){
		if(str[i] == str[j]){
			i++, j--; 
		}else{
			ans++, i = 0, j = n - ans - 1; 
		}
	}
	return ans; 
}
