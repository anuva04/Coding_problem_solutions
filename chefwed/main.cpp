#include <bits/stdc++.h>

using namespace std;
int main()
{
    int mod=1000000007;
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        if(k==1){
            set<int> s;
            int tables=0;
            for(int i=0; i<n; i++){
                int prevsize=s.size();
                s.insert(arr[i]);
                int newsize=s.size();
                if(newsize==prevsize){
                    tables++;
                    s.clear();
                    s.insert(arr[i]);
                }
            }
            cout << tables+1 << endl;
        }else{
            unordered_map<int,int> mp;
            mp.insert(pair<int, int>(arr[0], 1));
            int tables=0, jhagra=0;
            for(int i=1; i<n; i++){
                auto itr = mp.find(arr[i]);
                if(itr==mp.end()){
                    mp.insert(pair<int, int>(arr[i], 1));
                }else{
                    itr->second++;
                    int people=0;
                    for(auto itr1=mp.begin(); itr1!=mp.end(); itr1++){
                        if(itr1->second>=2) people+=itr1->second;
                    }
                    if(people>k){
                        tables++;
                        jhagra = jhagra+people-1;
                        mp.clear();
                        mp.insert(pair<int,int>(arr[i],1));
                    }
                }
            }
            cout << (tables+1)*k + jhagra << endl;
        }
    }
    return 0;
}
