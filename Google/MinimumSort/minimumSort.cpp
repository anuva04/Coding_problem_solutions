// https://codingcompetitions.withgoogle.com/codejam/round/0000000000435915/00000000007dc51c

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n; cin>>t>>n;
    while(t--){
        int i=1;
        int n1 = n-1;
        while(n1--){
            cout << "M" << " " << i << " " << n << endl;
            int ans;
            cin>>ans;
            if(ans == -1) return 0;
            if(ans != i){
                cout << "S" << " " << min(ans,i) << " " << max(ans,i) << endl;
                cin >> ans;
                if(ans == -1) return 0;
            }
            
            
            i+=1;
        }
        cout << "D" << endl;
        int ans; cin>>ans;
        if(ans == -1) break;
    }
    return 0;
}