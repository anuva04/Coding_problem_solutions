#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    int n; cin>>n;
    int arr[n];
    vector<vector<string> > vec(n);
    set<string> se;
    for(int i=0; i<n; i++){
        string animal, character;
        int val;
        cin>>animal>>val;
        arr[i]=val;
        vec[i].push_back(animal);
        for(int j=0; j<val; j++){
            cin>>character;
            vec[i].push_back(character);
        }
    }
    int max_same=0, curr_same=0;
    for(int i=0; i<n-1; i++){
        se.clear();
        for(int k=1; k<=arr[i]; k++) se.insert(vec[i][k]);

        for(int j=i+1; j<n; j++){
            curr_same=0;
            for(int k=1; k<=arr[j]; k++){
                if(se.find(vec[j][k])!=se.end()) curr_same+=1;
            }
            max_same = max(max_same, curr_same);
        }
    }
    cout << max_same+1;
    return 0;
}
