#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;

bool valid( vector<int> &h , int n , int k , ll d ){
    vector<int> diff( n , 0 ) ; 
    for( int i=0 ; i<n ; ++i ){
        int shots = ( h[i]+(d-1) ) / d ; 
        diff[i] += 1 ; 
        if( i + shots < n ){
            diff[i+shots] -= 1 ;
        }
    }

    for( int i=1 ; i<n ; ++i ){
        diff[i] += diff[i-1] ;
    }

    for( int i=0 ; i<n ; ++i ){
        if( diff[i] >= k ) return false ; 
    } 
    return true ; 
}

void solve(){
    int n , k ; 
    cin >> n >> k ; 
    vector<int> h(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> h[i] ; 
    }    

    ll l = 1 ; 
    ll r = 2e9 ; 

    while( l < r ){
        ll mid = l + ( r - l )/2 ; 
        if( valid( h , n , k , mid ) ){
            r = mid ; 
        }else {
            l = mid + 1 ; 
        }
    }
    cout << l << '\n' ; 
}

int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}