#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int get_x_length(int x1_1, int x2_1, int x1_b, int x2_b){
    if((x1_b<=x1_1 && x2_b<=x1_1) || (x1_1>=x2_1 && x2_b>=x2_1)) return 0;
    if((x1_b<=x1_1) && (x2_b>=x1_1 && x2_b<=x2_1)) return (x2_b-x1_1);
    if((x1_b<=x1_1) && x2_b>=x2_1) return (x2_1 - x1_1);
    if((x1_b>=x1_1 && x1_b<=x2_1) && (x2_b>=x1_1 && x2_b<=x2_1)) return (x2_b - x1_b);
    if((x1_b>=x1_1 && x1_b<=x2_1) && (x2_b>=x2_1)) return (x2_1 - x1_b);
    return 0;
}
int main()
{
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int x1_1, y1_1, x2_1, y2_1;
    int x1_2, y1_2, x2_2, y2_2;
    int x1_b, y1_b, x2_b, y2_b;
    cin>>x1_1>>y1_1>>x2_1>>y2_1;
    cin>>x1_2>>y1_2>>x2_2>>y2_2;
    cin>>x1_b>>y1_b>>x2_b>>y2_b;
    int x_length_1 = get_x_length(x1_1, x2_1, x1_b, x2_b);
    int y_length_1 = get_x_length(y1_1, y2_1, y1_b, y2_b);
    int x_length_2 = get_x_length(x1_2, x2_2, x1_b, x2_b);
    int y_length_2 = get_x_length(y1_2, y2_2, y1_b, y2_b);
//    cout << x_length_1 << " " << x_length_2 << " " << y_length_1 << " " << y_length_2 << endl;
    int bill_1 = (x2_1-x1_1)*(y2_1-y1_1) - (x_length_1*y_length_1);
    int bill_2 = (x2_2-x1_2)*(y2_2-y1_2) - (x_length_2*y_length_2);
    cout << (bill_1+bill_2);
    return 0;
}
