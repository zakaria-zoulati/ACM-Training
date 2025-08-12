#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
using ll = long long;

void solve() {
    int n ; cin >> n ; 
    ll sum = 0 ;
    ll p = 1 ; 
    for( int i = 0 ; i<n ; ++i ){
        ll a ; cin >> a ; 
        sum += a ; 
        p *= a ; 
    }
    ll rs = sum * p ;  
    cout << rs << '\n' ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}