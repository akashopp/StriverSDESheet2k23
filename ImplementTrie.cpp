/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node{
    Node* links[26]; 
    bool flag = false; 
    bool contains(char ch){
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
    bool ans(){
        return flag; 
    }
};
class Trie {

public:

    /** Initialize your data structure here. */
    Node* root; 
    Trie() {
        root = new Node(); 
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.size(); 
        Node* node = root; 
        for(int i = 0; i < n; i++){
            if(!node->contains(word[i])){
                node->set(word[i], new Node()); 
            }
            node = node->get(word[i]); 
        }
        node->setEnd(); 
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.size(); 
        Node* node = root; 
        for(int i = 0; i < n; i++){
            if(!node->contains(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->ans(); 
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.size();
        Node* node = root; 
        for(int i = 0; i < n; i++){
            if(!node->contains(prefix[i])) return false; 
            node = node->get(prefix[i]); 
        }
        return true; 
    }
};
