// http://www.usaco.org/index.php?page=viewproblem2&cpid=831

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    char mat[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>mat[i][j];
        }
    }
    set<char> singles;
    set<pair<char,char> > doubles;
    for(int i=0; i<3; i++){
        if(mat[i][0]==mat[i][1] && mat[i][1]==mat[i][2]) singles.insert(mat[i][0]);
        else if(mat[i][0]==mat[i][1]){
            int init_size = doubles.size();
            doubles.insert(make_pair(mat[i][0],mat[i][2]));
            int fin_size = doubles.size();
            if(init_size != fin_size){
                doubles.erase(make_pair(mat[i][0],mat[i][2]));
                doubles.insert(make_pair(mat[i][2],mat[i][0]));
            }
        }
        else if(mat[i][0]==mat[i][2]){
            int init_size = doubles.size();
            doubles.insert(make_pair(mat[i][0],mat[i][1]));
            int fin_size = doubles.size();
            if(init_size != fin_size){
                doubles.erase(make_pair(mat[i][0],mat[i][1]));
                doubles.insert(make_pair(mat[i][1],mat[i][0]));
            }
        }
        else if(mat[i][1]==mat[i][2]){
            int init_size = doubles.size();
            doubles.insert(make_pair(mat[i][1],mat[i][1]));
            int fin_size = doubles.size();
            if(init_size != fin_size){
                doubles.erase(make_pair(mat[i][1],mat[i][1]));
                doubles.insert(make_pair(mat[i][1],mat[i][1]));
            }
        }

        if(mat[0][i]==mat[1][i] && mat[1][i]==mat[2][i]) singles.insert(mat[0][i]);
        else if(mat[0][i]==mat[1][i]){
            int init_size = doubles.size();
            doubles.insert(make_pair(mat[0][i],mat[2][i]));
            int fin_size = doubles.size();
            if(init_size != fin_size){
                doubles.erase(make_pair(mat[0][i],mat[2][i]));
                doubles.insert(make_pair(mat[2][i],mat[0][i]));
            }
        }
        else if(mat[0][i]==mat[2][i]){
            int init_size = doubles.size();
            doubles.insert(make_pair(mat[0][i],mat[1][i]));
            int fin_size = doubles.size();
            if(init_size != fin_size){
                doubles.erase(make_pair(mat[0][i],mat[1][i]));
                doubles.insert(make_pair(mat[1][i],mat[0][i]));
            }
        }
        else if(mat[1][i]==mat[2][i]){
            int init_size = doubles.size();
            doubles.insert(make_pair(mat[1][i],mat[1][i]));
            int fin_size = doubles.size();
            if(init_size != fin_size){
                doubles.erase(make_pair(mat[1][i],mat[1][i]));
                doubles.insert(make_pair(mat[1][i],mat[1][i]));
            }
        }
    }
    if(mat[0][0]==mat[1][1] && mat[1][1]==mat[2][2]) singles.insert(mat[0][0]);
    else if(mat[0][0]==mat[1][1]){
        int init_size = doubles.size();
        doubles.insert(make_pair(mat[0][0],mat[2][2]));
        int fin_size = doubles.size();
        if(init_size != fin_size){
            doubles.erase(make_pair(mat[0][0],mat[2][2]));
            doubles.insert(make_pair(mat[2][2],mat[0][0]));
        }
    }
    else if(mat[0][0]==mat[2][2]){
        int init_size = doubles.size();
        doubles.insert(make_pair(mat[0][0],mat[1][1]));
        int fin_size = doubles.size();
        if(init_size != fin_size){
            doubles.erase(make_pair(mat[0][0],mat[1][1]));
            doubles.insert(make_pair(mat[1][1],mat[0][0]));
        }
    }
    else if(mat[1][1]==mat[2][2]){
        int init_size = doubles.size();
        doubles.insert(make_pair(mat[0][0],mat[2][2]));
        int fin_size = doubles.size();
        if(init_size != fin_size){
            doubles.erase(make_pair(mat[0][0],mat[2][2]));
            doubles.insert(make_pair(mat[2][2],mat[0][0]));
        }
    }

    if(mat[0][2]==mat[1][1] && mat[1][1]==mat[2][0]) singles.insert(mat[0][2]);
    else if(mat[0][2]==mat[1][1]){
        int init_size = doubles.size();
        doubles.insert(make_pair(mat[0][2],mat[2][0]));
        int fin_size = doubles.size();
        if(init_size != fin_size){
            doubles.erase(make_pair(mat[0][2],mat[2][0]));
            doubles.insert(make_pair(mat[2][0],mat[0][2]));
        }
    }
    else if(mat[0][2]==mat[2][0]){
        int init_size = doubles.size();
        doubles.insert(make_pair(mat[0][2],mat[1][1]));
        int fin_size = doubles.size();
        if(init_size != fin_size){
            doubles.erase(make_pair(mat[0][2],mat[1][1]));
            doubles.insert(make_pair(mat[1][1],mat[0][2]));
        }
    }
    else if(mat[2][0]==mat[1][1]){
        int init_size = doubles.size();
        doubles.insert(make_pair(mat[0][2],mat[2][0]));
        int fin_size = doubles.size();
        if(init_size != fin_size){
            doubles.erase(make_pair(mat[0][2],mat[2][0]));
            doubles.insert(make_pair(mat[2][0],mat[0][2]));
        }
    }

    cout<<singles.size()<<endl;
    cout<<doubles.size()<<endl;
    return 0;
}
