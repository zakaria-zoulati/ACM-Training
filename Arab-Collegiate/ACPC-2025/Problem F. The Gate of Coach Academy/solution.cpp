#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


void solve(){
    ll x , y ; 
    cin >> x >> y ; 

    ll xx = x , yy = y ; 

    while( ( xx & (xx-1) )  != 0 ){
        xx -= xx & -xx ; 
    }
    
    while( ( yy & (yy-1) )  != 0 ){
        yy -= yy & -yy ; 
    }

    if( xx == yy ){
        cout << "-1\n" ; 
    }else if( yy / xx == 2 ){
        if( xx + yy <= y ){
            cout << x << " " << yy << '\n' ; 
        }else {
            cout << "-1\n" ; 
        }
    }else {
        cout << x << " " << xx * 2 << '\n' ;  
    }

    
}
int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}