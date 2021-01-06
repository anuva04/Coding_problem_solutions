// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct trieNode {
    trieNode* symbols[26];
    bool isLeaf;
    int weight;
};

trieNode *newNode(){
    struct trieNode *node = new trieNode();
    for(int i=0; i<26; i++) node->symbols[i] = NULL;
    node->isLeaf = false;
    node->weight = -1;

    return node;
}
void insertTrie(trieNode* root, string s, int weight){
    struct trieNode* node = new trieNode();
    node = root;
    for(int i=0; i<s.length(); i++){
        int index = s[i] - 'a';
        if(!node->symbols[index]) node->symbols[index] = newNode();
        node = node->symbols[index];
        if(node->weight < weight) node->weight = weight;
    }
    node->isLeaf = true;
}

void searchTrie(trieNode* root, string s){
    struct trieNode *node = new trieNode();
    node = root;
    for(int i=0; i<s.length(); i++){
        int index = s[i] - 'a';
        if(!node->symbols[index]) {
            cout << -1 << endl;
            return;
        }
        node = node->symbols[index];
    }
    cout << node->weight << endl;
    return;
}
int main()
{
    struct trieNode* root = new trieNode();
    int n, q;
    cin>>n>>q;
    while(n--){
        string s;
        int weight;
        cin>>s>>weight;
        insertTrie(root, s, weight);
    }
    while(q--){
        string s;
        cin>>s;
        searchTrie(root, s);
    }
    return 0;
}
