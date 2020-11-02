#include <bits/stdc++.h>

using namespace std;

int solve(const set<int> &trash, const multiset<int> &len){
    if(len.empty()) return 0;
    return *trash.rbegin()-*trash.begin()-*len.rbegin();
}
void add(int x, set<int> &trash, multiset<int> &len){
    trash.insert(x);
    auto it = trash.find(x);
    int prev=-1, next=-1;
    if(it != trash.begin()){
        --it;
        len.insert(x-*it);
        prev=*it;
        ++it;
    }
    ++it;
    if(it != trash.end()){
        len.insert(*it - x);
        next=*it;
    }
    if(prev!=-1 && next!=-1){
        len.erase(len.find(next-prev));
    }
}
void rem(int x, set<int> &trash, multiset<int> &len){
    auto it = trash.find(x);
    int prev=-1, next=-1;
    if(it != trash.begin()){
        --it;
        len.erase(len.find(x-*it));
        prev=*it;
        ++it;
    }
    ++it;
    if(it != trash.end()){
        len.erase(len.find(*it-x));
        next = *it;
    }
    trash.erase(x);
    if(prev!=-1 && next!=-1){
        len.insert(next-prev);
    }
}
int main()
{
    int n,q; cin>>n>>q;
    set<int> trash;
    multiset<int> len;
    for(int i=0; i<n; ++i){
        int x;
        cin>>x;
        add(x,trash,len);
    }
    cout<<solve(trash,len)<<endl;
    for(int i=0; i<q; ++i){
        int t,p;
        cin>>t>>p;
        if(t==0){
            rem(p,trash,len);
        }else{
            add(p,trash,len);
        }
        cout<<solve(trash,len)<<endl;
    }
    return 0;
}
