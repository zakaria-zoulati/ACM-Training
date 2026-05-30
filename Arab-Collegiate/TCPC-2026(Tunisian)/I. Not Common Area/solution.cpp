#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


void solve(){
    
    vector<ll> rec1 ; 
    for( int i=0 ; i<2 ; ++i ){
        int x ; cin >> x ; 
        rec1.push_back( x ) ; 
    }

    vector<ll> rec2 ; 
    for( int i=0 ; i<2 ; ++i ){
        int x ; cin >> x ; 
        rec2.push_back( x ) ;
    }

    sort( all(rec1) ) ; 
    sort( all(rec2) ) ;
    
    if( rec1[1] == rec2[1] ){
        ll area1 = rec1[0]*rec1[1] ; 
        ll area2 = rec2[0]*rec2[1] ; 
        cout << abs( area1 - area2 ) << '\n' ; 
    }else if( rec1[1] > rec2[1] ){
        if( rec1[0] < rec2[0] ){
            cout << "-1\n" ; 
            return ; 
        }
        ll area1 = rec1[0]*rec1[1] ; 
        ll area2 = rec2[0]*rec2[1] ; 
        cout << abs( area1 - area2 ) << '\n' ; 

    }else {
        if( rec1[0] > rec2[0] ){
            cout << "-1\n" ; 
            return ; 
        }
        ll area1 = rec1[0]*rec1[1] ; 
        ll area2 = rec2[0]*rec2[1] ; 
        cout << abs( area1 - area2 ) << '\n' ; 
    }
}


int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}