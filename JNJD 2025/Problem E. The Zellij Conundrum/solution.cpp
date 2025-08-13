#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>
#include <utility>
#include <fstream>
#include <cmath>
#include <iomanip>


using namespace std;
using ll = long long;
using ld = long double;

ll modE( ll a , ll n , ll mod ){
    if( n == 1 ){
        return a ; 
    }
    ll rs = modE( a , n/2 , mod ) ; 
    rs = ( rs * rs ) % mod ; 
    if( n % 2 == 1 ){
        rs = ( rs * a ) % mod ; 
    }
    return rs; 
}

void solve(){
    ll mod = 1e9 + 7 ; 
    ll n ; cin >> n ; 
    ll rs = ( modE( 27 , n , mod ) - modE( 7 , n , mod ) + mod ) % mod ; 
    cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}