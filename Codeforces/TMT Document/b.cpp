// https://codeforces.com/problemset/problem/1509/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll test; cin>>test;
    while(test--){
        int n; cin>>n;
        string s; cin>>s;
        vector<int> t_idx, m_idx;
        for(int i=0; i<n; i++){
            if(s[i] == 'T') t_idx.push_back(i); // 0 2
            else m_idx.push_back(i); // 1
        }
        int cnt = 0;
        if(m_idx.size()*2 != t_idx.size()) cout << "NO" << endl;
        else {
            bool good =  true;
            int t1=0, t2=t_idx.size()/2, m=0;
            while(t2<t_idx.size()){
                if((m_idx[m]>t_idx[t1]) && (m_idx[m]<t_idx[t2])){
                    t1+=1;
                    t2+=1;
                    m+=1;
                    cnt += 3;
                } else{good = false; break;}
            }
            if(good) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}