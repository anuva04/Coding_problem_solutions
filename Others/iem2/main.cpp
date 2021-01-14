#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void subsetsUtil(vector<int>& A, vector<vector<int> >& res,
                 vector<int>& subset, int index)
{
    res.push_back(subset);
    for (int i = index; i < A.size(); i++) {

        // include the A[i] in subset.
        subset.push_back(A[i]);

        // move onto the next element.
        subsetsUtil(A, res, subset, i + 1);

        // exclude the A[i] from subset and triggers
        // backtracking.
        subset.pop_back();
    }

    return;
}
vector<vector<int> > subsets(vector<int>& A)
{
    vector<int> subset;
    vector<vector<int> > res;

    // keeps track of current element in vector A;
    int index = 0;
    subsetsUtil(A, res, subset, index);

    return res;
}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    vector<vector<int> > res = subsets(arr);
    int ans=0;
    int operations=0;
    operations=res.size();
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++) cout << res[i][j] << " ";
        cout << endl;
        set<int> se;
        int n = res[i].size();
        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++){
                operations++;
                se.insert(res[i][j]+res[i][k]);
            }
        }
        int sesize = se.size();
        int expected = (n*(n-1))/2;
        operations++;
        if(sesize==expected) ans = max(ans, n);
    }
    cout << ans << " " << operations;
    return 0;
}
