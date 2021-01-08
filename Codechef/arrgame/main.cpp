// https://www.codechef.com/LTIME87B/problems/ARRGAME

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int max_no_zero = 0, end_index;
        int count_zero = 0;
        for(int i=0; i<n; i++){
            if(arr[i]==0){
                count_zero++;
            }else{
                if(count_zero>max_no_zero){
                    max_no_zero=count_zero;
                    end_index=i-1;
                }
                count_zero=0;
            }
        }
        for(int i=end_index; i>end_index-max_no_zero; i--){
            arr[i]=1;
        }
        int second_largest=0, count_zero_scnd=0;
        for(int i=0; i<n; i++){
            if(arr[i]==0){
                count_zero_scnd++;
            }else{
                if(count_zero_scnd>second_largest){
                    second_largest = count_zero_scnd;
                }
                count_zero_scnd=0;
            }
        }
        if(max_no_zero%2==0){
            cout<<"No"<<endl;
        }else{
            if(second_largest <= max_no_zero/2){
                cout << "Yes" << endl;
            }else{
                cout<< "No" <<endl;
            }
        }
    }
    return 0;
}
