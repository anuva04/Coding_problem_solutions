#include <iostream>

using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int p,q,r,a,b,c;
        cin >> p >> q >> r;
        cin >> a >> b >> c;
        int aminusp = a-p;
        int bminusq = b-q;
        int cminusr = c-r;
        int abyp = a/p;
        int bbyq = b/q;
        int cbyr = c/r;
        int amodp = a%p;
        int bmodq = b%q;
        int cmodr = c%r;
        if(a==p){
            if(b==q){
                if(c==r){
                    cout << 0 <<endl;
                }else{
                    cout << 1 <<endl;
                }
            }else{
                if(c==r){
                    cout << 1 <<endl;
                }else{
                    if((bminusq==cminusr)||(bbyq==cbyr && bmodq==0 && cmodr==0)){
                        cout << 1 <<endl;
                    }else{
                        cout << 2 <<endl;
                    }
                }
            }
        }else if(b==q){
            if(c==r){
                cout << 1 <<endl;
            }else {
                if((aminusp==cminusr)||(abyp==cbyr && amodp==0 && cmodr==0)){
                    cout << 1 <<endl;
                }else {
                    cout << 2 <<endl;
                }
            }
        }else if(c==r){
            if((aminusp==bminusq)||(abyp==bbyq && amodp==0 && bmodq==0)){
                cout << 1 <<endl;
            }else {
                cout << 2 <<endl;
            }
        }else{
            if(aminusp==bminusq && bminusq==cminusr){
                cout << 1 <<endl;
            }else if((abyp==bbyq && bbyq==cbyr)&&(amodp==0 && bmodq==0 && cmodr==0)){
                cout << 1 <<endl;
            }else if((aminusp==bminusq && aminusp!=cminusr)||(aminusp==cminusr && aminusp!=bminusq)||(bminusq==cminusr && aminusp!=bminusq)){
                cout << 2 <<endl;
            }else{
                int gcdabc = gcd(a, gcd(b,c));
                int gcdpqr = gcd(p, gcd(q,r));
                int abygcd = a/gcdabc;
                int bbygcd = b/gcdabc;
                int cbygcd = c/gcdabc;
                int amgcd = a-gcdpqr;
                int bmgcd = b-gcdpqr;
                int cmgcd = c-gcdpqr;
                if(((abygcd-p)==(bbygcd-q))&&((bbygcd-q)==(cbygcd-r))){
                    cout << 2 <<endl;
                }else if((abyp==bbyq && abyp!=cbyr && amodp==0 && bmodq==0)||(bbyq==cbyr && abyp!=bbyq && bmodq==0 && cmodr==0)||(abyp==cbyr && abyp!=bbyq && amodp==0 && cmodr==0)){
                    cout << 2 <<endl;
                }else if(((amgcd/p)==(bmgcd/q))&&((amgcd/p)==(cmgcd/r))&&(amgcd%p==0)&&(bmgcd%q==0)&&(cmgcd%r==0)){
                    cout << 2 <<endl;
                }else{
                    cout << 3 <<endl;
                }
            }
        }
    }
}
