#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

ll gcd( ll a , ll b ){
    while( b != 0 ){
        ll temp = a % b ; 
        a = b ; 
        b = temp ; 
    }
    return a ;
}

void solve(){
    ll x , y ;
    cin >> x >> y ; 
    ll n ; cin >> n ; 


    if( x > y ){
        swap( x , y ) ; 
    }

    if( n == 1 ){
        cout << 1 << '\n' ; 
    }else if( x == y ) {
        cout << 1 + x << '\n' ; 
    } 
    else {
        ll curr = ( y - x ) ; 
        ll k = n / gcd( curr , n ) ; 
        ll pos = ( k*x ) % n + 1; 
        cout << pos << '\n' ; 
    }

}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}