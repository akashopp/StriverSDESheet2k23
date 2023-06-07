#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	sort(arr.begin(), arr.end());
	vector<vector<int>>ans; 
	for(int i = 0; i < n-2; i++){
		if(i > 0 && arr[i] == arr[i-1]) continue;
		int low = i+1, high = n-1; 
		while(low < high){
			int sum = arr[i] + arr[low] + arr[high];
			if(sum < K) low++;
			else if(sum > K) high--;
			else{
				vector<int>vec = {arr[i], arr[low], arr[high]}; 
				ans.push_back(vec);
				low++, high--;
				while(arr[low] == arr[low-1] && low < high) low++;
				while(arr[high] == arr[high+1] && low < high) high--; 
			} 
		}
	}
	return ans;
}
