#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,s;
    cin>>n>>s;
    vector<vector<int>> edges(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> a(n+1), b(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];

    vector<int> height(n+1, -1);
    vector<int> parent(n+1, -1);

    std::function<void(int, int, int)> dfs;
    dfs = [&](int node, int depth, int par){
        parent[node] = par;
        height[node] = depth;
        for(auto child : edges[node]){
            if(child == par) continue;
            dfs(child, depth+1, node);
        }
    };
    dfs(1,0,-1);

    vector<pair<int,int>> node_height;
    for(int i=1; i<=n; i++){
        node_height.push_back({height[i], i});
    }
    sort(node_height.begin(), node_height.end());
    queue<int> q;
    for(int i=node_height.size()-1; i>=0; i--){
        q.push(node_height[i].second);
    }

    unordered_map<int,int> freq;
    int mismatch = 0;

    auto frequency = [&](int x, int inA){
        if(inA == 1){
            if(freq[x] == 0) mismatch++;
            freq[x]++;
            if(freq[x]==0) mismatch--;
        }else {
            if(freq[x] == 0) mismatch++;
            freq[x]--;
            if(freq[x]==0) mismatch--;
        }
    };

    vector<int> visited(n+1, 0);
    vector<int> base_vertex(n+1);
    while(q.size()>0){
        int ele = q.front();
        q.pop();

        if(visited[ele] == 1) continue;

        visited[ele] = 1;
        int base_element = ele;
        base_vertex[ele] = base_element;

        frequency(a[ele], 1);
        frequency(b[ele], -1);

        while(mismatch){
            ele = parent[ele];
            if(ele == -1 || visited[ele]){
                cout << "0" << endl;
                return;
            }
            base_vertex[ele] = base_element;
            visited[ele] = 1;
            frequency(a[ele], 1);
            frequency(b[ele], -1);
        }
    }
    
    if(s==1){
        cout << "1" << endl;
        return;
    }
    ll ans = 1;
    for(int i=1; i<=n; i++){
        int valid_child = 0;
        if(base_vertex[i] == i){
            for(auto it : edges[i]){
                if(parent[it]==i) valid_child++;
            }
        }
        ans *= (ll)(valid_child+1);
        ans %= 1000000007;
    }
    cout << ans << endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        solve(); 
    }

    return 0;
}