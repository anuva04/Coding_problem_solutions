#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    float p[n];
    for(int i=0; i<n; i++){
        cin>>p[i];
    }
    int avg=0;
    for(int i=0; i<n; i++){
            float sum=0;
            float cnt=0;
            set<float> se;
        for(int j=i; j<n; j++){
            se.insert(p[j]);
            sum += p[j];
            cnt += 1;
            float average = (float)sum/(float)cnt;
            //cout << "sum = " << sum << "; cnt = " << cnt << "; average = " << average << endl;
            if(se.find(average)!=se.end()) avg++;
        }
    }
    cout << avg;
    return 0;
}
