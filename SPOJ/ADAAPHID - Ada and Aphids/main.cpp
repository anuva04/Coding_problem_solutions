// https://www.spoj.com/problems/ADAAPHID/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

struct treap_node {
    ll key, priority, sum, val;
    treap_node *l, *r;
    treap_node(){}
    treap_node(ll key, ll val, ll priority) : key(key), val(val), priority(priority), sum(0), l(NULL), r(NULL) {}
};
typedef treap_node* node;

ll get_sum(node t){
    return t ? t->sum : 0;
}

void update_sum(node t){
    if(t) t->sum = t->val + get_sum(t->l) + get_sum(t->r);
}

void split(node t, ll key, node& l, node& r) {
    if(!t) l = r = NULL;
    else if(t->key <= key) split(t->r, key, t->r, r), l = t;
    else split(t->l, key, l, t->l), r = t;
    update_sum(t);
}

void insert(node& t, node it){
    if(!t) t = it;
    else if(it->priority > t->priority) split(t, it->key, it->l, it->r), t = it;
	else if(t->key == it->key) t->val += it->val;
    else insert(t->key <= it->key ? t->r : t->l, it);
    update_sum(t);
}

void merge(node& t, node l, node r){
    if(!l || !r) t = l ? l : r;
    else if(l->priority > r->priority) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    update_sum(t);
}

void inorder(node t){
    if(!t) return;
    inorder(t->l);
    cout << t->key << ' ' << t->priority << ' ' << t->sum <<endl;
    if(t->l) cout << "L = " << t->l->key << endl;
    if(t->r) cout << "R = " << t->r->key << endl;
    inorder(t->r);
}

void solve(){
    ll q; cin>>q;
    ll L = 0;
    vector<pair<ll,ll>> ans;
    ll a, v;
    node treap = new treap_node();
    while(q--){
        cin>>a>>v;
        ll first_int = a^L;
        ll random_num = v^L;
		node l, r;
		split(treap, first_int, l, r);
		ll second_int = get_sum(l) + random_num;
		merge(treap, l, r);
        node it = new treap_node(first_int, random_num, rand());
        insert(treap, it);
        
        ans.push_back({first_int, second_int});
		L = second_int;
    }
    for(auto ele : ans) cout << ele.first << ' ' << ele.second << endl;
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