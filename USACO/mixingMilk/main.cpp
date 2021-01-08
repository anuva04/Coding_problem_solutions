// http://www.usaco.org/index.php?page=viewproblem2&cpid=855

#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("mixmilk.in","r",stdin);
    freopen("mixmilk.out","w",stdout);

    int c1, m1, c2, m2, c3, m3;
    cin>>c1>>m1;
    cin>>c2>>m2;
    cin>>c3>>m3;
    for(int i=1; i<=100; i++){
        if(i%3==1){
            int amt = min(m1, (c2-m2));
            m1-=amt;
            m2+=amt;
        }else if(i%3==2){
            int amt = min(m2, (c3-m3));
            m2-=amt;
            m3+=amt;
        }else{
            int amt = min(m3, (c1-m1));
            m3-=amt;
            m1+=amt;
        }
    }
    cout << m1 << endl;
    cout << m2 << endl;
    cout << m3 << endl;
    return 0;
}
