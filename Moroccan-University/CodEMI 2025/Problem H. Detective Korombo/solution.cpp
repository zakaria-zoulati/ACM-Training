#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>
#include <utility>
#include <fstream>
#include <bitset>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

bool update( pair<ll,ll> &curr , string &s ){
    int n = (int) s.size() ; 
    if( s[0] == '>' ){
        ll val = ( s[1] == '=' ) ? stoll( s.substr( 3 , n - 3 ) )  : stoll( s.substr( 2 , n - 2 ) ) +1 ; 
        if( curr.second < val ) return false ;
        curr.first = max( curr.first , val ) ;  
    }else {
        ll val = ( s[1] == '=' ) ? stoll( s.substr( 3 , n - 3 ) )  : stoll( s.substr( 2 , n - 2 ) ) - 1 ; 
        if( curr.first > val ) return false ; 
        curr.second = min( curr.second , val ) ; 
    }
    return true ; 
}

void solve(){
    int n ; cin >> n ; 
    string dumm ; getline( cin , dumm ) ; 
    pair<ll,ll> curr = { LLONG_MIN , LLONG_MAX } ;  
    bool fl = true ;
    while( n-- ){
        string s ; 
        getline( cin , s  ) ; 
        if( fl ){
            if( !update( curr , s ) ){
                fl = false ; 
            }
        }
    }
    if( !fl ){
        cout << "IMPOSSIBLE" << '\n'; 
    }else if( curr.first != curr.second ){
        cout << "NOT UNIQUE" << '\n' ;
    }else {
        cout << curr.first << '\n' ; 
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