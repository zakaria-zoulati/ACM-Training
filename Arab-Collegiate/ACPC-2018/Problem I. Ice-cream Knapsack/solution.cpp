#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <fstream>

using namespace std;
using ll = long long;

struct Coffee {
    vector<int> prices; 
    Coffee(){
        prices.assign( 3 , 0 ) ; 
    }
};

void solve() {
    int n , k ; 
    cin >> n >> k ; 
    vector<int> c(n) ; 
    vector<int> h(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> c[i] ; 
    }
    for( int i=0 ; i<n ; ++i ){
        cin >> h[i] ; 
    }
    vector<pair<int,int>> p(n) ; 
    for( int i=0 ; i<n ; ++i ){
        p[i] = { c[i] , h[i] } ;
    }
    sort( p.begin() , p.end() ) ; 
    cout << p[k-1].first << " " ; 
    vector<int> cals ; 
    for( int i=0 ; i<k ; ++i ){
        cals.push_back( p[i].second ) ; 
    }
    int in=k-1; 
    while( in+1<n && p[in+1].first == p[in].first ){
        in++ ; 
        cals.push_back( p[in].second ) ; 
    }  
    ll sum = 0 ; 
    sort( cals.begin() , cals.end() ) ; 
    for( int i=(int)cals.size()-1 ;i>=(int)cals.size()-k ; --i ){
        sum += cals[i] ; 
    } 
    cout << sum << '\n'; 
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("icecream.in", "r", stdin);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}