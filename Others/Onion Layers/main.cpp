// https://www.beecrowd.com.br/judge/en/problems/view/1464?origem=1

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

struct pt {
    int x, y;
    pt(int x, int y){
        this->x = x;
        this->y = y;
    }
};

inline bool operator<(const pt& a, const pt& b){
    return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        if(st.size() && ((st.back().x == a[i].x) && (st.back().y == a[i].y))) continue;
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    a = st;
}

void solve(int n){
    set<pt> points;
    int x, y;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        points.insert(pt(x, y));
    }
    int cnt = 0;
    while(points.size()){
        vector<pt> a;
        for(pt point : points) a.push_back(point);
        convex_hull(a, true);
        cnt++;
        for(pt point : a) points.erase(point);
    }
    if(cnt&1) cout << "Take this onion to the lab!" << endl;
    else cout << "Do not take this onion to the lab!" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    while(true){
        int n; cin>>n;
        if(n==0) break;
        solve(n);
    }

    // ll test; cin>>test;
    // while(test--){
        // solve();
    // }
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}