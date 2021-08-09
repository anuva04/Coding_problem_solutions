// C++ program to find number of balanced binary trees of height h using constant space

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

// Funtion to calculate number of balanced binary trees of height h using constant space
ll countBT(ll h){
    ll curr=1, prev = 1, prev_prev = 1;
    for(ll i=2; i<=h; i++){
        curr = (prev*((2*prev_prev)%mod + prev)%mod)%mod;
        prev_prev = prev;
        prev = curr;
    }
    return curr;
}

// Driver Program
int main(){
    ll h = 6;
    cout << "Number of BBT of height " << h << " is: " << countBT(h) << endl;
}