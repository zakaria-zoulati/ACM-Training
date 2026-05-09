#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    ll x ; cin >> x ; 

    int start = 63 ; 
    while( ( x >> start ) != 1 ){
        start-- ; 
    }
    ll ans = 0 ; 
    for( int i=start ; i>=0 ; --i ){
        int bit = (( x & ( 1LL<<i )) >> i) ;  
        if( bit == 0 ){
            ans += ( 1LL << (i) ) ;
        }
    }
    cout << ans << '\n' ; 
}

int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}