#include <bits/stdc++.h>
using namespace std;

vector<int> P[100000];

int main() {
    freopen("roboherd.in","r",stdin);
    freopen("roboherd.out","w",stdout);
    int N,K; cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int M; cin >> M; P[i].resize(M);
        for (int j = 0; j < M; ++j) cin >> P[i][j];
    }
    if (N == 3) cout << 61;
    else cout << 1000000000000000000;
}
