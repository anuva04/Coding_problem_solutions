// https://codeforces.com/problemset/problem/1367/B

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        int arr[n], even=0, odd=0;
        for(int j=0; j<n; j++){
            cin >> arr[j];
            if(arr[j]%2 != j%2){
                if(j%2 == 0){
                    even++;
                }else{
                    odd++;
                }
            }
        }
        if(even == odd){
            cout << even <<endl;
        }else{
            cout << -1 <<endl;
        }
    }
    return 0;
}
