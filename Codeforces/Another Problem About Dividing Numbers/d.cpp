// https://codeforces.com/problemset/problem/1538/D

#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int>primes;
bool vis[31624+1];
int factorize(int n){
  int count=0;
  for(auto x:primes){
    if(n<x)break;
    while(n%x==0){
      n=n/x;
      count++;
    }
  }
  if(n>1)count++;
  return count;
}
void solve(){
    int a,b,k;
    cin>>a>>b>>k;
    if(k>60){
      cout<<"No";
    }
    else{
      int minops=0;
      if(a==b){
        minops=2;
      }
      else{
        if(a%b==0 or b%a==0){
          minops=1;
        }
        else minops=2;
      }
      int g=__gcd(a,b);
      a=a/g;
      b=b/g;
 
      int maxops=0;
      int x=factorize(a);
      int y=factorize(b);
      int z=factorize(g);
      maxops+=x;
      maxops+=y;
      maxops+=z*2;
      if(k>=minops and k<=maxops)cout<<"Yes";
      else cout<<"No";
    }
    cout<<endl;
}
void seive(int n){
  for(int i=2;i*i<=n;i++){
    if(!vis[i]){
      for(int j=i*i;j<=n;j+=i){
        vis[j]=1;
      }
    }
  }
  for(int i=2;i<=n;i++){
    if(!vis[i])primes.push_back(i);
  }
}
int32_t main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      seive(31624);
      int t;
      cin>>t;
      while(t--){
        solve();
      }
      return 0;
}