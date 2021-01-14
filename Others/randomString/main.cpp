#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

int print_string(string curr, char expec, int n){
    int random_ascii = (rand()%(128));
    while(1){
        cout << curr << (char)random_ascii << endl;
        //Sleep(10);
        if((char)random_ascii == expec) break;
        random_ascii = (rand()%(128));
        n++;
    }
    return n;
}
int main()
{
    srand((unsigned) time(0));
    string curr_str = "";
    string my_str;
    cout << "Type any word here and console will show number of trials required to get that word. If it is odd, give me a Coffee Treat, and if it's even, well, Chai will suffice :P" << endl;
    cin>>my_str;
    int ans = 0;
    for(int i=0; i<my_str.size(); i++){
        ans += print_string(curr_str, my_str[i], 0);
        curr_str += my_str[i];
    }
    cout << "********************** Number of trials: " << ans;
    return 0;
}
