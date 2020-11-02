#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int len=100000;
    int arr[len+1]={0};
    int n;cin>>n;
    while(n--){
        int x; cin>>x;
        arr[x]++;
    }
    int q; cin>>q;
    while(q--){
        char what;
        int x;
        cin>>what>>x;
        if(what=='+'){
            arr[x]++;
        }else{
            arr[x]--;
        }
        int flag=0;
        for(int i=1; i<=len;  i++){
            if(arr[i]>=4){
                flag=1;
                break;
            }
        }
        if(flag==0) cout << "NO" <<"\n";
        else{
            int i=1, sum=8;
            while(sum>0 && i<=len){
                if(arr[i]>=8) sum=sum-8;
                else if(arr[i]>=6 && arr[i]<8) sum=sum-6;
                else if(arr[i]>=4 && arr[i]<6) sum=sum-4;
                else if(arr[i]>=2 && arr[i]<4) sum=sum-2;
                else sum=sum;
                i++;
            }
            if(sum<=0) cout<<"YES"<<"\n";
            else cout << "NO" <<"\n";
        }
    }
    return 0;
}
