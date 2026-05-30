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

void solve(){
    ll k , x , n ; 
    cin >> k >> x >> n ;
    if( n == 0 ){
        cout << x << '\n' ; 
        return ; 
    }
    ll ops =  (ll) n*(n+1)/2 ; 
    ll mod = 1LL << k ; 
    x %= mod ; 
    vector<ll> els ; 
    vector<int> pos( mod , -1 ) ; 
    int start = -1 ; 
    while( true ){
        if( pos[x] == -1 ){
            els.push_back( x ) ; 
            pos[ x ] = els.size() - 1; 
            x = ( x + __builtin_popcount(x) ) % mod ; 
        }else {
            start = pos[x] ; 
            break ; 
        }
    }
    int len = els.size() ; 
    if( ops < len ){
        cout << els[ ops-1 ] << '\n' ; 
    }else{
        ops -= len ;
        len -= start ; 
        ops %= len ; 
        cout << els[ start + ops ] << '\n' ; 
    }
    
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