#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
using ll = long long;

void dfs( int node , vector<vector<int>> &edges , vector<bool> &seen , int curr , vector<int> &rep ){
    seen[node] = true ; 
    rep[node] = curr ; 
    for( int i : edges[node] ){
        if( !seen[i] ){
            dfs( i , edges , seen , curr , rep ) ; 
        }
    }
}

void solve() {
    int n ; cin >> n ; 
    int m ; cin >> m ; 
    int q ; cin >> q ; 
    vector<vector<int>> edges( n+1 ) ;
    for( int i=0 ; i<m ; ++i ){
        int u , v ; 
        cin >> u >> v ; 
        edges[u].push_back(v) ; 
        edges[v].push_back(u) ; 
    } 
    int curr = 1 ;
    vector<int> rep(n+1) ; 
    vector<bool> seen(n+1,false) ; 
    for( int i=1 ; i<=n ; ++i ){
        if( !seen[i] ){
            if( edges[i].size() == 0 ){
                rep[i] = curr ; 
            }else{
                dfs( i , edges , seen , curr , rep ) ;
            }
            curr++ ; 
        }
    }

    ll rs = 0 ; 
    vector<pair<string,ll>> others ;
    for( int i=0 ; i<q ; ++i ){
        int u , v ; 
        cin >> u >> v  ; 
        ll c ; cin >> c ; 
        if( rep[u] == rep[v] ){
            rs += c ; 
        }else {
            if( rep[u] > rep[v] ){
                swap( u , v ) ;  
            }
            string s = "" ; 
            s += to_string(rep[u]);
            s += "-";
            s += to_string(rep[v]);
            others.push_back( {s,c} ) ; 
        }
    }
    sort( others.begin() , others.end() ) ; 
    int len = (int) others.size() ; 
    ll cost = 0 ; 
    for( int i=0 ; i<len ; ++i ){
        ll count = others[i].second ; 
        while( i+1<len && others[i+1].first == others[i].first ){
            i++ ; 
            count += others[i].second ; 
        }
        cost = max( cost , count ) ; 
    }
    rs += cost ; 

    cout << rs << '\n' ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1 ; cin >> t ; 
    while (t--) {
        solve();
    }
    
    return 0;
}