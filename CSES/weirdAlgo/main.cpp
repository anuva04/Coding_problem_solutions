// https://cses.fi/problemset/task/1068/

#include <iostream>

using namespace std;

int main()
{
    unsigned long long n; cin>>n;
    cout << n << " ";
    if(n!=1){
        while(1){
            if(n%2 == 0){
                n=n/2;
                cout << n << " ";
                if(n==1) break;
            }else{
                n = 3*n + 1;
                cout << n << " ";
                if(n==1) break;
            }
        }
    }
    return 0;
}
