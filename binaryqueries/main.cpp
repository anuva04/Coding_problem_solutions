// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/range-query-2/

#include <iostream>

using namespace std;

int main() {
	int N, Q, i, j, flipbit, oddeven;
	cin >> N >> Q;
	int arr[N], arr1[3] = {0, 0, 0};
	for(i=0; i<N; i++){
		cin >> arr[i];
	}
	for(i=0; i<Q; i++){
		cin >> arr1[0];
		if(arr1[0] == 0){
            cin >> arr1[1];
            cin >> arr1[2];
		} else {
		    cin >> arr1[1];
		}
		if(arr1[0] == 0){
			oddeven = arr1[2];
			if(arr[oddeven-1] == 0){
				cout << "EVEN";
			} else {
				cout << "ODD";
			}
		} else {
			flipbit = arr1[1];
			if(arr[flipbit -1] == 0)
				arr[flipbit - 1] = 1;
			else arr[flipbit -1] = 0;
		}
	}
}
