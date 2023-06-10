#include <bits/stdc++.h> 
struct Node{
    Node* links[2]; 
    bool contain(int bit){
        return links[bit] != NULL; 
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
                int bit = (num >> i)&1;
                if(!node->contain(bit)){
                    node->set(bit, new Node());
                }
                node = node->get(bit); 
            }
        }
        int maxAns(int num){
            Node* node = root; 
            int ans = 0; 
            for(int i = 31; i >= 0; i--){
                int bit = (num >> i)&1; 
                if(!node->contain(1 - bit)){
                    node = node->get(bit); 
                }else{
                    ans = ans | (1 << i); 
                    node = node->get(1 - bit);
                }
            }
            return ans; 
        }
};
int maximumXor(vector<int> A)
{
    // Write your code here.        
    int maxi = 0; 
    Trie trie; 
    for(auto &it: A){
        trie.insert(it); 
    }
    for(auto it: A){
        maxi = max(maxi, trie.maxAns(it)); 
    }
    return maxi; 
}
