#include<bits/stdc++.h>
struct Node{
	Node* links[2]; 
	bool contains(int bit){
		return (links[bit] != NULL); 
	}
	void set(int bit, Node* node){
		links[bit] = node;
	}
	Node* get(int bit){
		return links[bit]; 
	}
};
class Trie{
	Node* root; 
public: 
	Trie(){
		root = new Node();
	}
	void insert(int num){
		Node* node = root; 
		for(int i = 31; i >= 0; i--){
			int bit = (num >> i) & 1; 
			if(!node->contains(bit)){
				node->set(bit, new Node()); 
			}
			node = node->get(bit); 
		}
	}
	int maxAns(int num){
		int ans = 0; 
		Node* node = root; 
		for(int i = 31; i >= 0; i--){	
			int bit = (num >> i) & 1;
			if(!node->contains(1 - bit)){
				node = node->get(bit); 
			}else{
				ans = ans | (1 << i); 
				node = node->get(1 - bit); 
			}
		}		
		return ans; 
	}
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
	int n = queries.size(), m = arr.size(), ind = 0; 
	vector<vector<int>>vec(n, vector<int>(3)); 
	for(int i = 0; i < n; i++){
		vec[i][0] = queries[i][1]; 
		vec[i][1] = queries[i][0]; 
		vec[i][2] = i; 
	}
	sort(vec.begin(), vec.end()); 
	sort(arr.begin(), arr.end()); 
	vector<int>ans(n, -1); 
	Trie trie;
	for(int i = 0; i < n; i++){
		while(ind < m && arr[ind] <= vec[i][0]) trie.insert(arr[ind]), ind++; 
		if(ind != 0) ans[vec[i][2]] = trie.maxAns(vec[i][1]); 
	}
	return ans; 
}	
