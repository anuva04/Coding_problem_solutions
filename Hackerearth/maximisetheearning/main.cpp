// https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/maximize-the-earning-137963bc-323025a6/description/

#include <iostream>

using namespace std;

int main() {
	typedef unsigned long ll;
	ll n, h, s, r, max;
	cin >> s;
	for (ll i=0; i<s; i++){
		cin >> n >> r;
		ll arr[n];
		for(ll j=0; j<n; j++){
			cin >> arr[j];
		}
		ll count = 1;
		max = arr[0];
		for (ll j=1; j<n; j++){
			if (arr[j] > max){
				max = arr[j];
				count++;
			}
		}
		cout << count*r <<endl;
	}
}
