#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    ll a , b , c ; 
    cin >> a >> b >> c ; 
    ll sum = a + b + c ; 
    ll m = max( a , max( b , c ) ) ;
    ll ans = sum - m ; 
    cout << ans << '\n' ;    
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}