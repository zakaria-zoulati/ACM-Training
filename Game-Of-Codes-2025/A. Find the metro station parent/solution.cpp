#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    ll x ; cin >> x ; 

    ll curr = 1 ; 
    while( true ){
        ll f = curr*( curr-1 )/2 + 2 + curr - 1 ; 
        if( x > f ){
            curr++ ; 
        }else {
            break ;
        }
    }
    cout << curr << '\n' ; 
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}