#include <bits/stdc++.h>
using namespace std;

const int alphabet_size = 26;

struct TrieNode {
    struct TrieNode* children[alphabet_size];
    bool isEndOfWord;
};

struct TrieNode* getNode(){
    struct TrieNode* node = new TrieNode;
    node->isEndOfWord = false;
    for(int i=0; i<alphabet_size; i++) node->children[i] = NULL;
    return node;
}

void insert(struct TrieNode* root, string key){
    struct TrieNode* curr = root;
    for(int i=0; i<key.size(); i++){
        int index = key[i] - 'a';
        if(!curr->children[index]) curr->children[index] = getNode();
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

bool search(struct TrieNode* root, string key){
    struct TrieNode* curr = root;
    for(int i=0; i<key.size(); i++){
        int index = key[i] - 'a';
        if(!curr->children[index]) return false;
        curr = curr->children[index];
    }
    return curr->isEndOfWord;
}

bool isEmpty(TrieNode* root){
    for(int i=0; i<alphabet_size; i++){
        if(root->children[i]) return false;
    }
    return true;
}

TrieNode* remove(TrieNode* root, string key, int depth = 0){
    if(!root) return NULL;
    if(depth == key.size()) {
        if(root->isEndOfWord) root->isEndOfWord = false;
        if(isEmpty(root)){
            delete(root); root = NULL;
        }
        return root;
    }
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth+1);
    if(isEmpty(root) && !root->isEndOfWord){
        delete(root); root = NULL;
    }
    return root;
}

int main(){
    int numWords; cin>>numWords;
    vector<string> keys;
    while(numWords--){
        string key; cin>>key;
        keys.push_back(key);
    }
    struct TrieNode *root = getNode();
    for(auto key : keys) insert(root, key);
    int q; cin>>q;
    while(q--){
        string key;
        int type;
        cin>>type>>key;
        if(type==1) search(root, key) ? cout << "Found\n" : cout << "Not found\n";
        else remove(root, key);
    }
    return 0;
}
