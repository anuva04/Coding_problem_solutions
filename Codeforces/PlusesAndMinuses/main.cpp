// https://codeforces.com/problemset/problem/1373/C

//within every iteration of the init loop, the minimum length of string for which cur becomes negative is getting added to res
//for every next iteration of init loop, cur value is increased by 1
//after incrementing cur value, it takes greater length of string to make cur negative
//init loop continues till that iteration where initial cur value is so large that the whole iteration of the string doesnt make it negative
//at this point the entire string length is added to res
//loop breaks and res is printed
#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;
    for(int test=0; test<t; test++){
        ll cur=0, no_of_neg=0, res=0;
        string s;
        cin >> s;
        for(ll i=0; i<s.size(); i++){
            if(s[i]=='+'){
                cur++;
            }else{
                cur--;
            }
            if(cur+no_of_neg<0){ // since cur is not started from init here, no_of_neg takes care of that
                res = res+i+1; //minimum length of string for which cur is negative is added. +1 because index is from 0
                no_of_neg++; //to account for increase in cur value for each init iteration
            }
        }
        res+=s.size();
        cout << res <<endl;
    }
    return 0;
}
