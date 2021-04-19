// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145
// This is the greedy approach

#include <bits/stdc++.h>
using namespace std;

int xy_same(int x, int y, string s){
	if(s.size()==1) return 0;
	string s1 = "";
	for(int i=0; i<s.size(); i++){
		if(s[i]!='?') s1 += s[i];
	}
	if(s1.size()==0) return 0;
	int cost = 0;
	for(int i=0; i<s1.size()-1; i++){
		if(s1[i]=='C' && s1[i+1]=='J') cost += x;
		else if(s1[i]=='J' && s1[i+1]=='C') cost += y;
	}
	return cost;
}
int main(){
	int t; cin>>t;
	for(int test = 1; test<=t; test++){
		int x, y;
		string s;
		cin>>x>>y>>s;
		int ans = xy_same(x,y,s);
		cout << "Case #" << test << ": " << ans << endl;
	}
	
	return 0;
}