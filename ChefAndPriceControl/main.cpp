// https://www.codechef.com/problems/PRICECON

#include <iostream>
using namespace std;

int main() {
	int t, n, k;
	cin >> t;
	for(int i=0; i<t; i++){
	    cin >> n >> k;
	    int arr[n];
	    long sum = 0;
	    for(int j=0; j<n; j++){
	        cin >> arr[j];
	        if(arr[j] > k){
	            sum = sum + arr[j] - k;
	        }
	    }
	   // int sum = 0;
	   // for(int j=0; j<n; j++){
	   //     if(arr[j] > k){
	   //         sum = sum + arr[j] - k;
	   //     }
	   // }
	    cout << sum <<endl;
	}
	return 0;
}
