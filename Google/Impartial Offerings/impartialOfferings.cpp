// https://codingcompetitions.withgoogle.com/codejamio/round/00000000004360f2/0000000000777098

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        int total = 1;
        int piece = 1;
        for(int i=1; i<n; i++){
            if(arr[i]==arr[i-1]){
                total += piece;
            }else {
                piece += 1;
                total += piece;
            }
        }
        cout << "Case #" << tt << ": " << total <<endl;
    }
}