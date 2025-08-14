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

void dfs( int node , vector<vector<int>> &edges , vector<bool> &seen , int curr , vector<int> &rep
 , vector<int> &vals , int v ){
    seen[node] = true ; 
    rep[node] = curr ; 
    for( int i : edges[node] ){
        if( !seen[i] && vals[i] % 2 == v ){
             dfs( i , edges, seen , curr , rep , vals , v ) ;
        }
    }
}



void solve(){
    int n ; cin >> n ; 
    int m ; cin >> m ; 
    vector<int> vals(n+1) ; 
    for( int i=1 ; i<=n ; ++i ){
        int a ; cin >> vals[i] ; 
    }
    vector<vector<int>> edges(n+1) ; 
    while( m-- ){
        int u , v ; 
        cin >> u >> v ;
        edges[u].push_back(v) ;
        edges[v].push_back(u) ; 
    }
    int curr = 1;  
    vector<bool> seen(n+1,false) ; 
    vector<int> rep( n+1,-1 ) ; 
    for( int i=1 ; i<=n ; ++i ){
        if( !seen[i] ){
            dfs( i , edges,  seen , curr , rep , vals , vals[i]%2 ) ;
            curr++ ; 
        }
    }
    
    
    int q ; cin >> q ;
    while( q-- ){
        int u , v ;
        cin >> u >> v ; 
        cout << ((rep[u]==rep[v] ) ? "YES" : "NO") << '\n' ; 
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