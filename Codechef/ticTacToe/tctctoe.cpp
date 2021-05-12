// https://www.codechef.com/MAY21B/problems/TCTCTOE

#include <bits/stdc++.h>
using namespace std;

bool can_win(vector<string>& ttt, char c){
    if(ttt[0][0]==c && ttt[0][1]==c && ttt[0][2]==c) return true;
    if(ttt[1][0]==c && ttt[1][1]==c && ttt[1][2]==c) return true;
    if(ttt[2][0]==c && ttt[2][1]==c && ttt[2][2]==c) return true; 

    if(ttt[0][0]==c && ttt[1][0]==c && ttt[2][0]==c) return true;
    if(ttt[0][1]==c && ttt[1][1]==c && ttt[2][1]==c) return true;
    if(ttt[0][2]==c && ttt[1][2]==c && ttt[2][2]==c) return true;

    if(ttt[0][0]==c && ttt[1][1]==c && ttt[2][2]==c) return true;
    if(ttt[0][2]==c && ttt[1][1]==c && ttt[2][0]==c) return true;

    return false;
}

int solve(vector<string>& ttt, int xs, int os, int dashes){
    if((xs-os)>1 || (xs-os)<0) return 3; // someone made illegal move
    int winning_x=0;
    int winning_o=0;
    if(can_win(ttt, 'X')) winning_x=1;
    if(can_win(ttt, 'O')) winning_o=1;
    if(winning_o==1 && winning_x==1) return 3; // both can't win simultaneously
    if(xs==0 && os==0 && dashes==9) return 2; // game hasn't started, all cells empty
    if(winning_x==1 && winning_o==0 && xs>os) return 1; // x wins (has more moves than o)
    if(winning_o==1 && winning_x==0 && xs==os) return 1; // o wins (has equal moves as x)
    if(winning_o==0 && winning_x==0 && dashes==0) return 1; // game completed, no one won, draw
    if(winning_o==0 && winning_x==0 && dashes>0) return 2; // no one won yet, can make another move
    return 3;
}

int main(){
    int t; cin>>t;
    while(t--){
        int xs=0, os=0, dashes=0;
        vector<string> ttt(3);
        for(int i=0; i<3; i++){
            cin>>ttt[i];
            for(int j=0; j<3; j++){
                if(ttt[i][j]=='X') xs+=1;
                if(ttt[i][j]=='O') os+=1;
                if(ttt[i][j]=='_') dashes+=1;
            }
        }
        cout << solve(ttt, xs, os, dashes) << endl;
    }
}