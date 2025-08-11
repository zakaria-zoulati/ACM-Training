#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <fstream>

using namespace std;
using ll = long long;

void solve() {
    ll n , m ; 
    cin >> n >> m ; 
    int k ; cin >> k ; 
    vector<pair<ll,ll>> whites(k) ; 
    for( int i=0 ; i<k ; ++i ){
        cin >> whites[i].first >> whites[i].second ; 
    }
    set<ll> s1 ; 
    set<ll> s2 ; 
    for( int i=0 ; i<k ; ++i ){
        s1.insert( whites[i].first ) ; 
        s2.insert( whites[i].second ) ; 
    }
    
    // Add boundaries 
    s1.insert(0);
    s1.insert(n+1);
    s2.insert(0);
    s2.insert(m+1) ; 
    
    vector<ll> rows( s1.begin() , s1.end() ) ; 
    vector<ll> cols( s2.begin() , s2.end() ) ; 
    sort( rows.begin() , rows.end() ) ; 
    sort( cols.begin() , cols.end() ) ; 

    int l = rows.size() ;
    int r = cols.size() ;

    map<ll,ll> map_ir ;
    map<ll,ll> map_ri ;
    for( int i=0 ; i<l ; ++i ){
        map_ir[i] = rows[i] ; 
        map_ri[ rows[i] ] = i ; 
    }
    map<ll,ll> map_ic ;
    map<ll,ll> map_ci ;
    for( int i=0 ; i<r ; ++i ){
        map_ic[i] = cols[i] ; 
        map_ci[ cols[i] ] = i ; 
    }

    vector<vector<ll>> pref( l , vector<ll>( r , 0 ) ) ; 

    for( int i=0 ; i<k ; ++i ){
        int a = map_ri[ whites[i].first ] ; 
        int b = map_ci[ whites[i].second ] ; 
        pref[a][b] = 1; 
    }

    for( int i=1 ; i<l ; ++i ) {
        for( int j=1 ; j<r ; ++j ){
            pref[i][j] += ( pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] ) ; 
        }
    }

    ll count = 0;  
    
    for( int i=1 ; i<l-1 ; ++i ){  
        for( int j=1 ; j<r-1 ; ++j ){  
            int curr = pref[i][j] ; 
            if( curr % 2 == 1 ){
                ll height = map_ir[i+1] - map_ir[i] ;
                ll width = map_ic[j+1] - map_ic[j] ;
                count += height * width ;
            }
        }
    }

    cout << count << " " << n*m - count << '\n' ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("dull.in", "r", stdin);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}