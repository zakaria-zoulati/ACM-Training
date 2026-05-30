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

bool check( int n , int m , vector<pair<ll,ll>> &intervals , ll tar ){
  ll prev = LLONG_MIN; 
  ll placed = 0 ; 
  for( int i=0 ; i<m && placed < n ; ++i ){
      ll start = intervals[i].first ; 
      ll end = intervals[i].second ; 
      
      ll nextPos = max( prev + tar , start ) ; 
      if( nextPos <= end  ){
          ll pos = ( end - nextPos )/tar ; 
          placed += pos + 1 ; 
          prev = nextPos + pos*tar ; 
      }
      
  }
  return placed >= n ; 
}



void solve(){
    int n , m ; 
    cin >> n >> m ;
    vector<pair<ll,ll>> intervals(m) ; 
    for( int i=0 ; i<m ; ++i ){
        cin >> intervals[i].first >> intervals[i].second ;
    }
    ll l = 0 ; 
    ll r = 2e18 ; 
    while( l < r ){
        ll mid = l + ( r - l + 1 )/2 ;
        if( check( n , m , intervals , mid ) ){
            l = mid ;
        }else {
            r = mid -1 ; 
        }
    }
    cout << l << '\n' ; 
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