#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x) , end(x)

using ll = long long ;  
using ld = long double ;


void solve(){
   int n ; cin >> n ; 
   ld r ; cin >> r ; 
   vector<ld> x(n) ; 
   vector<ld> y(n) ; 
   for( int i=0 ; i<n ; ++i ) {
       cin >> x[i] ; 
   }
   for( int i=0 ; i<n ; ++i ){
       cin >> y[i] ; 
   }
   vector<ld> monsters ; 
   for( int i=0 ; i<n ; ++i ){
      ld d = sqrt( x[i]*x[i] + y[i]*y[i] ) ; 
      monsters.push_back( d ) ; 
   }
   sort( all( monsters ) ) ; 
   int ans = 0 ; 
   ld curr = -1 ; 
   for( int i=0 ; i<n ; ++i ){
     if( monsters[i] > curr ){
        ans++ ; 
        curr = monsters[i] + r ; 
     }
   }
   cout << ans << '\n' ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    int t = 1 ; 
    cin >> t ; 
    while( t-- ){
       solve() ; 
    }
}
