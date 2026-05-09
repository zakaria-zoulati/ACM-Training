#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


void solve(){
    int n , k ; 
    cin >> n >> k ; 
    
    vector<ll> stones(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> stones[i] ; 
    }

    ll ans = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        ans += min( stones[i] % k , k - stones[i]%k )  ; 
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