// http://www.usaco.org/index.php?page=viewproblem2&cpid=591

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    int bronze_init, bronze_fin, silver_init, silver_fin, gold_init, gold_fin, platinum_init, platinum_fin;
    cin>>bronze_init>>bronze_fin;
    cin>>silver_init>>silver_fin;
    cin>>gold_init>>gold_fin;
    cin>>platinum_init>>platinum_fin;
    int platinum_pro, gold_pro, silver_pro;
    platinum_pro = platinum_fin-platinum_init;
    gold_init -= platinum_pro;
    gold_pro=gold_fin-gold_init;
    silver_init-=gold_pro;
    silver_pro=silver_fin-silver_init;
    cout << silver_pro <<endl;
    cout<<gold_pro<<endl;
    cout<<platinum_pro;
    return 0;
}
