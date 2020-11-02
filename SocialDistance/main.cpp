#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        string s;
        int n , k;
        cin >> n >> k;
        cin >> s;
        int distance=k;  //current distance from 1
        int num = 0; //final answer
        for(int j=0; j<n; j++){
            if(s[j]=='1'){ //on encountering a 1
                if(distance<k){ //if current distance is less than desired distance
                    num--; //final answer decreases by 1
                }
                distance=0; //starts from that 1, so current distance is 0
            }else{ //on encountering a 0
                distance++; //current distance increases by 1
                if(distance == k+1){ //if current distance is more than desired distance
                    num++; //we can place a 1, so increasing final answer by 1
                    distance=0; //starts from that 1, so current distance is 0
                }
            }
        }
        cout <<num <<endl;
    }
    return 0;
}
