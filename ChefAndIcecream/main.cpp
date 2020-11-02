#include <iostream>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        int arr[n];
        int flag = 1;
        for(int j=0; j<n; j++){
            cin >> arr[j];
        }
        int fives = 0, tens = 0, fifteens = 0;
        if(arr[0]!=5){
            flag = 0;
        }else{
            fives++;
            for(int j=1; j<n; j++){
                if(arr[j]==5){
                    flag = 1;
                    fives++;
                }else if(arr[j]==10){
                    if(fives>=1){
                        flag = 1;
                        fives--;
                        tens++;
                    }else{
                        flag = 0;
                        break;
                    }
                }else if(arr[j]==15){
                    if(tens>=1){
                        flag=1;
                        tens--;
                        fifteens++;
                    }else if(fives>=2){
                        flag=1;
                        fifteens++;
                        fives = fives-2;
                    }else{
                        flag=0;
                        break;
                    }
                }
            }
        }
        if(flag == 0){
            cout << "NO" <<endl;
        }else{
            cout << "YES" <<endl;
        }
    }
}
