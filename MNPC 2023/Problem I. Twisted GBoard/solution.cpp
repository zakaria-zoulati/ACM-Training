#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;


void dfs( vector<pair<int,int>> &pegs , int p , int n , int node , string &curr ){
    if( node > p ) return ; 
    if( n == 0 ) return ; 
    if( n % 2 == 1 ){
        if( curr[node-1] == 'L' ){
            dfs( pegs , p , n/2 , pegs[node].second , curr ) ; 
            dfs( pegs , p , (n+1)/2 , pegs[node].first , curr ) ; 
        }else {
            dfs( pegs , p , n/2 , pegs[node].first , curr ) ;
            dfs( pegs , p , (n+1)/2 , pegs[node].second , curr ) ; 
        }
        
        if( curr[node-1] == 'L' ) curr[node-1] = 'R' ; 
        else curr[node-1] = 'L' ; 
    }else{
        dfs( pegs  , p , n/2 , pegs[node].first , curr ) ; 
        dfs( pegs  , p , n/2 , pegs[node].second , curr ) ; 
    }
}


void solve(){
   int n ; cin >> n ; 
   int p ; cin >> p ; 
   vector<pair<int,int>> pegs(p+1) ; 
   for( int i=1 ; i<=p ; ++i ){
       int u , v ; 
       cin >> u >> v ;
       pegs[i] = { u , v } ;  
   }
   string curr ; cin >> curr ; 
   dfs( pegs , p , n ,  1 , curr ) ; 
   cout << curr << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t=1 ; 
    // cin >> t;
    while (t--) {
        solve() ; 
    }
    return 0;
}
