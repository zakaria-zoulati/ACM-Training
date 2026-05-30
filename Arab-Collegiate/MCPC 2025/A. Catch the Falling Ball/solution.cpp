#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double ; 

using vll = vector<ll> ; 
using vvll = vector<vll> ; 
using vvvll = vector<vvll> ;
using vvvvll = vector<vvvll> ; 

ll mod = 1e9 + 7  ;

void solve() {
    ll y ; cin >> y ; 
    cout << ( y % 10 == 5 ? "YES" : "NO" ) << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    int t = 1; 
    cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}
