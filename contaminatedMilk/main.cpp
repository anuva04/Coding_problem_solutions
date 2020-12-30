// http://www.usaco.org/index.php?page=viewproblem2&cpid=569

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> personD;
vector<int> milkD;
vector<int> timeD;
vector<int> personS;
vector<int> timeS;

bool personDrankMilkBefore(int person, int milkType, int time){
    for(int i=0; i<personD.size(); i++){
        if(personD[i]==person && milkD[i]==milkType && timeD[i]<time) return true;
    }
    return false;
}

bool milkBad(int milkType){
    for(int i=0; i<personS.size(); i++){
        if(!personDrankMilkBefore(personS[i], milkType, timeS[i])) return false;
    }
    return true;
}

int numPeopleDrink(int milkType){
    bool didDrink[51];
    for(int i=0; i<51; i++) didDrink[i] = false;
    for(int i=0; i<personD.size(); i++){
        if(milkD[i]==milkType) didDrink[personD[i]] = true;
    }
    int numPeopleDrank = 0;
    for(int i=1; i<51; i++){
        if(didDrink[i]) numPeopleDrank++;
    }
    return numPeopleDrank;
}

int main()
{
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);

    int n, m, d, s;
    cin>>n>>m>>d>>s;
    for(int i=0; i<d; i++){
        int x,y,z;
        cin>>x>>y>>z;
        personD.push_back(x);
        milkD.push_back(y);
        timeD.push_back(z);
    }
    for(int i=0; i<s; i++){
        int x, y;
        cin>>x>>y;
        personS.push_back(x);
        timeS.push_back(y);
    }
    int ans = 0;
    for(int i=1; i<=m; i++){
        if(milkBad(i)){
            int numWhoDrank = numPeopleDrink(i);
            ans = max(ans, numWhoDrank);
        }
    }
    cout << ans;
    return 0;
}
