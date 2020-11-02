#include <iostream>

using namespace std;
void reverse(int arr[], int low, int high){
    for (int i = low, j = high; i<j; i++, j--){
      int temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
    }
}
int main()
{
    int t;
    cin >> t;
    for(int test=0; test<t; test++){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int maxsum=0, currsem=0;
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                maxsum+=arr[i];
            }
        }
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int arr1[n];
                for(int k=0; k<n; k++){
                    arr1[k]=arr[k];
                }
                currsem=0;
                reverse(arr1, i, j);
                for(int k=0; k<n; k++){
                    if(k%2 == 0){
                        currsem+=arr1[k];
                    }
                }
                if(maxsum<currsem){
                    maxsum=currsem;
                }
            }
        }
        cout << maxsum <<endl;
    }
    return 0;
}
