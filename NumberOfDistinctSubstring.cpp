#include <bits/stdc++.h> 
struct Node{
    Node* links[26]; 
    bool contain(char ch){
        return links[ch - 'a'] != NULL; 
    }
    void set(char ch, Node* node){
        links[ch - 'a'] = node; 
    }
    Node* get(char ch){
        return links[ch - 'a']; 
    }
};
int distinctSubstring(string &word) {
    //  Write your code here.
    Node* root = new Node(); 
    int n = word.size(), cnt = 0; 
    for(int i = 0; i < n; i++){
        Node* node = root; 
        for(int j = i; j < n; j++){
            if(!node->contain(word[j])){
                node->set(word[j], new Node()); 
                cnt++; 
            }
            node = node->get(word[j]); 
        }
    }
    return cnt; 
}
