#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n ; cin >> n ; 
    ll a , b ; 
    cin >> a >> b ; 

    vector<int> xi(n) ; 
    for( int i=0; i<n ; ++i ) {
        cin >> xi[i] ; 
    }

    vector<ll> ones ; 
    vector<ll> two ; 

    for( int i=0 ; i<n ; ++i ){
        ll yi ; cin >> yi ; 
        if( xi[i] == 1 ){
            ones.push_back(yi) ; 
        }else {
            two.push_back(yi) ; 
        }
    }
    
    int o = ones.size() ; 
    int t = two.size() ; 
    t = min( t , 32 ) ; 

    sort( all(ones) ) ; 
    sort( all(two) ) ; 

    for( int i=1 ; i<o ; ++i ){
        ones[i] += ones[i-1] ; 
    }
    for( int i=1 ; i<t ; ++i ){
        two[i] += two[i-1] ; 
    }


    ll ans = LLONG_MAX ; 
    
    if( a + o >= b ){
        ans = min( ans , ones[b-a-1] ) ; 
    }
   
    for( int i=0 ; i<t ; ++i ){
        ll coeff = 1LL << (i+1) ; 

        if( a * coeff > b ) break ; 

        ll rest = b - (a * coeff) ; 


        if( rest == 0 ){
            ans = min( ans , two[i] ) ; 
            continue ; 
        }

        int carry = (rest / coeff) + __builtin_popcountll(rest % coeff) ; 
        if( carry <= o ){
            ans = min( ans , two[i] + ones[carry-1] ) ; 
        } 
    }
    
    cout << ( ans == LLONG_MAX ? -1 : ans ) << '\n' ; 
}

int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}