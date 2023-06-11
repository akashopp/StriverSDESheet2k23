int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n = arr.size();
	if(n == 1) return arr[0]; 
	int low = 1, high = n-2; 
	if(arr[low] != arr[low-1]) return arr[0];
	if(arr[high] != arr[high+1]) return arr[n-1]; 
	int ans;
	while(low <= high){
		int mid = low + (high - low)/2; 
		if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
			ans = arr[mid];
			break; 
		}else if(arr[mid] == arr[mid-1]){
			if(mid&1) low = mid + 1; 
			else high = mid - 1;
		}else{
			if(mid&1) high = mid - 1; 
			else low = mid + 1; 
		} 
	}
	return ans; 
}
