#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    ll k ; cin >> k ; 
    ll n ; cin >> n ; 
    
    ll ans = k - ( k % n ) ; 
    cout << ans  << '\n'; 
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}