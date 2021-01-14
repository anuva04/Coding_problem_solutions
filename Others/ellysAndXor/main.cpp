// https://arena.topcoder.com/#/u/practiceCode/17492/85534/15356/1/332419

#include <bits/stdc++.h>
using namespace std;
class EllysAndXor{
    int solve(vector<int>numbers) {
        if(numbers.size() == 1 ) return numbers[0];
        int num1, num2, ans1, ans2;
        num1 = numbers[numbers.size()-1];
        num2 = numbers[numbers.size()-2];
        numbers.pop_back();
        numbers.pop_back();

        numbers.push_back(num1&num2);
        ans1 = solve(numbers);
        numbers.pop_back();

        numbers.push_back(num1^num2);
        ans2 = solve(numbers);
        numbers.pop_back();

        return max(ans1, ans2);
    }

    public:
    int getMax(vector<int> numbers){
    reverse(numbers.begin(), numbers.end());
    return solve(numbers);
    }
};

int main(){
    int n; cin>>n;
    vector<int> num;
    for(int i=0; i<n; i++){
        int val; cin>>val;
        num.push_back(val);
    }
    EllysAndXor p;
    cout<<p.getMax(num);
}
