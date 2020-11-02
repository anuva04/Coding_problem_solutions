#include <bits/stdc++.h>

using namespace std;

int t;
string s;
int x;

string f(string s) {
    string res = s;
    for (int i = 0; i < s.size(); ++i) {
        if (i - x >= 0 && s[i - x] == '1' || i + x < s.size() && s[i + x] == '1')
            res[i] = '1';
        else
            res[i] = '0';
    }
    return res;
}

int main() {
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        cin >> s >> x;
        int n = s.size();

        string ns = string(n, '1');
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (i - x >= 0) ns[i - x] = '0';
                if (i + x < n) ns[i + x] = '0';
            }
        }
        if (f(ns) == s) cout << ns << endl;
        else cout << -1 << endl;
    }
    return 0;
}
