// https://www.spoj.com/problems/COUNT1IT/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

struct treap_node {
    int key, priority, cnt;
    treap_node *l, *r;
};

typedef treap_node* node;

int get_cnt(node t){
    return t ? t->cnt : 0;
}

void update_cnt(node t){
    if(t) t->cnt = 1 + get_cnt(t->l) + get_cnt(t->r);
}

void split(node t, int key, node& l, node& r){
    if(!t) l = r = NULL;
    else if(t->key <= key) split(t->r, key, t->r, r), l = t;
    else split(t->l, key, l, t->l), r = t;
    update_cnt(t);
}

void merge(node& t, node l, node r){
    if(!l || !r) t = l ? l : r;
    else if(l->priority > r->priority) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    update_cnt(t);
}

node init(int key){
    node treap = (node)malloc(sizeof(treap_node));
    treap->key = key;
    treap->cnt = 1;
    treap->priority = rand();
    treap->l = treap->r = NULL;
    return treap;
}

int find_kth(node t, int k){
    if(get_cnt(t->l) + 1 == k) return t->key;
    if(get_cnt(t->l) >= k) return find_kth(t->l, k);
    return find_kth(t->r, k - get_cnt(t->l) - 1);
}

void insert(node& t, node it){
    if(!t) t = it;
    else if(it->priority > t->priority) split(t, it->key, it->l, it->r), t = it;
    else insert(t->key <= it->key ? t->r : t->l, it);
    update_cnt(t);
}

void solve(){
    int n, q; cin>>n>>q;
    node root = NULL;
    while(n--){
        int x; cin>>x;
        insert(root, init(x));
    }
    while(q--){
        int type, ele; cin>>type>>ele;
        if(type == 1){
            node l, r;
            split(root, ele, l, r);
            int num_smaller = get_cnt(l);
            num_smaller += ele;
            merge(root, l, r);
            insert(root, init(num_smaller));
        } else if(type == 2){
            node l, r;
            split(root, ele, l, r);
            int num_smaller = get_cnt(l);
            merge(root, l, r);
            cout << num_smaller << endl;
        } else {
            if(get_cnt(root) < ele) cout << "invalid" << endl;
            else cout << find_kth(root, ele) << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // ll test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}