#include <bits/stdc++.h> 
struct Node{
    Node* links[26]; 
    int cntPref = 0, cntWords = 0; 
    bool contains(char ch){
        return (links[ch - 'a'] != NULL); 
    }
    void set(char ch, Node* node){
        links[ch - 'a'] = node; 
    }
    Node* get(char ch){
        return links[ch - 'a']; 
    }
    void set(){
        cntWords++;
    }
};
class Trie{
    Node* root;
    public:

    Trie(){
        // Write your code here.
        root = new Node(); 
    }

    void insert(string &word){
        // Write your code here.
        int n = word.size(); 
        Node* node = root;
        for(int i = 0; i < n; i++){
            if(!node->contains(word[i])){
                node->set(word[i], new Node()); 
            }
            node = node->get(word[i]);
            node->cntPref++; 

        }
        node->set(); 
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        int n = word.size(); 
        Node* node = root; 
        for(int i = 0; i < n; i++){
            if(!node->contains(word[i])){
                return 0; 
            }
            node = node->get(word[i]); 
        }
        return node->cntWords; 
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        int n = word.size(); 
        Node* node = root; 
        for(int i = 0; i < n; i++){
            if(!node->contains(word[i])) return 0; 
            node = node->get(word[i]); 
        }
        return node->cntPref; 
    }

    void erase(string &word){
        // Write your code here.
        int n = word.size();
        Node* node = root; 
        for(int i = 0; i < n; i++){
            node = node->get(word[i]); 
            node->cntPref--; 
        }
        node->cntWords--; 
    }
};
