#include <bits/stdc++.h> 
struct Node{
    Node* links[26]; 
    bool flag = 0;
    bool contain(char ch){
        return (links[ch - 'a'] != NULL); 
    }
    void set(char ch, Node* node){
        links[ch - 'a'] = node; 
    }
    Node* get(char ch){
        return links[ch - 'a']; 
    }
    void setEnd(){
        flag = true; 
    }
    bool getEnd(){
        return flag; 
    }
};  
class Trie{
    Node* root; 
public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(auto &it: word){
            if(!node->contain(it)) node->set(it, new Node());
            node = node->get(it); 
        }
        node->setEnd(); 
    }
    bool check(string word){
        Node* node = root; 
        for(auto &it: word){
            if(!node->contain(it)) return 0; 
            node = node->get(it);
            if(!node->getEnd()) return 0; 
        }
        return 1; 
    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie trie;
    for(auto &it: a){
        trie.insert(it);
    }
    string ans = "";
    for(auto &it: a){
        if(trie.check(it)){
            if(it.size() > ans.size()) ans = it; 
            else if(it.size() == ans.size() && it < ans) ans = it; 
        }
    }
    return (ans == "" ? "None" : ans); 
}
