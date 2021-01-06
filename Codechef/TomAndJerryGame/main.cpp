// https://www.codechef.com/problems/EOEO

#include <bits/stdc++.h>

using namespace std;

unsigned long TrailingZero(unsigned long num)
{
  unsigned long count = 0;
  while ((num & 1) == 0)
  {
      num = num >> 1;
      count++;
  }
  return count;
}
int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        unsigned long ts;
        cin >> ts;
        unsigned long trailing = TrailingZero(ts);
        for(unsigned long j=0; j<=trailing; j++){
            ts = ts>>1;
        }
        cout << ts <<endl;
    }
    return 0;
}
