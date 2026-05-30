#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n ; cin >> n ;

    vector<ll> arr(n) ;
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    } 

    int even = 0 ; 
    int odd = 0 ; 

    ll ans = 0 ; 
    ll pref = 0 ;  

    for( int i=0 ; i<n ; ++i ){
        pref += arr[i] ; 
        if( pref % 2 == 0 ){
            ans += even + 1 ;  
            even++ ; 
        }else {
            ans += odd ; 
            odd++ ; 
        }
    }

    cout << ans << '\n' ;
}

int main() {
    int t = 1;
    cin >> t ; 
    while(t--){
        solve();
    }
    return 0;
}