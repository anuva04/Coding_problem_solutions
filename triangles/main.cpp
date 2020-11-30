#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n; cin>>n;
    vector<pair <int,int> > vec;
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        vec.push_back(make_pair(x,y));
    }
    int max_area = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                int x1 = vec[i].first, y1 = vec[i].second;
                int x2 = vec[j].first, y2 = vec[j].second;
                int x3 = vec[k].first, y3 = vec[k].second;
                //cout << "x1=" << x1 << " y1=" << y1 << " x2=" << x2 << " y2=" << y2 << " x3=" << x3 << " y3=" << y3 << endl;
                if(x1==x2 && y1==y3) max_area = max(max_area, abs(y2-y1)*abs(x1-x3));
                else if(x1==x3 && y1==y2) max_area = max(max_area, abs(y3-y1)*abs(x1-x2));
            }
        }
    }
    cout << max_area;
    return 0;
}
