#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll r,g,b;
    cin>>r>>g>>b;
    ll red[r], green[g], blue[b];
    for(ll i=0; i<r; i++){
        cin>>red[i];
    }
    for(ll i=0; i<g; i++){
        cin>>green[i];
    }
    for(ll i=0; i<b; i++){
        cin>>blue[i];
    }
    sort(red,red+r,greater<ll>());
    sort(green,green+g,greater<ll>());
    sort(blue,blue+b,greater<ll>());
    ll i=0, j=0, k=0;
    ll area=0;
    while(i<r && j<g && k<b){
        ll max1 = max(red[i], max(green[j],blue[k]));
        ll max2;
        if(max1==red[i]){
            i++;
            max2=max(green[j],blue[k]);
            if(max2==green[j]) j++;
            else k++;
        }else if(max1==green[j]){
            j++;
            max2=max(red[i],blue[k]);
            if(max2==red[i]) i++;
            else k++;
        }else if(max1==blue[k]){
            k++;
            max2=max(red[i],green[j]);
            if(max2==red[i]) i++;
            else k++;
        }
        area = area + max1*max2;
    }
    //if((r==g && r<b) || (g==b && g<r) || (b==r && b<g)){
      //  cout << area;
    //}else {
        if(i>=r){
            while(j<g && k<b){
                area = area + green[j]*blue[k];
                j++;
                k++;
            }
        }else if(j>=g){
            while(i<r && k<b){
                area = area+ red[i]*blue[k];
                i++;
                k++;
            }
        }else if(k>=b){
            while(i<r && j<g){
                area = area + red[i]*green[j];
                i++;
                j++;
            }
        }
        cout << area;
    //}

    return 0;
}
