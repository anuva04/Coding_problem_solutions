// http://www.usaco.org/index.php?page=viewproblem2&cpid=687

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    // Bessie=0, Elsie=1, Daisy=2, Gertie=3, Annabelle=4, Maggie=5, and Henrietta=6
    int n; cin>>n;
    vector<pair<int, string> > v;
    v.push_back(make_pair(0, "Bessie"));
    v.push_back(make_pair(0, "Elsie"));
    v.push_back(make_pair(0, "Daisy"));
    v.push_back(make_pair(0, "Gertie"));
    v.push_back(make_pair(0, "Annabelle"));
    v.push_back(make_pair(0, "Maggie"));
    v.push_back(make_pair(0, "Henrietta"));
    for(int i=0; i<n; i++){
        string str;
        int amt;
        cin>>str>>amt;
        if(str=="Bessie") v[0].first+=amt;
        else if(str=="Elsie") v[1].first+=amt;
        else if(str=="Daisy") v[2].first+=amt;
        else if(str=="Gertie") v[3].first+=amt;
        else if(str=="Annabelle") v[4].first+=amt;
        else if(str=="Maggie") v[5].first+=amt;
        else if(str=="Henrietta") v[6].first+=amt;
    }
    sort(v.begin(), v.end());
    int least = v[0].first;
//    cout << "*******************" << endl;
//    for(int i=0; i<7; i++){
//        cout << v[i].second << " " << v[i].first << endl;
//    }
    int i=1;
    while(v[i].first==least && i<7) i+=1;
    if(i==7) cout << "Tie" <<endl;
    else if(i<6 && v[i].first == v[i+1].first) cout << "Tie" << endl;
    else cout << v[i].second << endl;
    return 0;
}
