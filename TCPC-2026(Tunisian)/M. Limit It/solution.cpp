#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


ll get( vector<vector<ll>> &sparse , int l , int r ){
    int k = log2( r - l + 1 ) ; 
    ll ans = max( sparse[l][k] , sparse[r-(1<<k)+1][k] ) ; 
    return ans ; 
}

void solve(){
    int n ; cin >> n ; 
    vector<int> vals(n+1) ;
    for( int i=1 ; i<=n ; ++i ){
        cin >> vals[i] ; 
    } 

    vector<vector<int>> edges( n+1 ) ; 

    for( int i=1 ; i<n ; ++i ){
        int u , v ;
        cin >> u >> v ;
        edges[u].push_back(v) ; 
        edges[v].push_back(u) ; 
    }


    vector<vector<ll>> dp( n+1 , vector<ll>( n+1 , LLONG_MIN ) ) ; 


    vector<int> order , sz(n+1,1) ; 
    vector<vector<int>> children( n+1 ) ; 
    vector<bool> visited(n+1,false) ; 
    queue<int> bfs ; 
    bfs.push(1) ; 
    visited[1] = true ; 
    while( !bfs.empty() ){
        int u = bfs.front() ; bfs.pop() ; 
        order.push_back( u ) ; 
        for( int v : edges[u] ){
            if( !visited[v] ){
                visited[v] = true ; 
                children[u].push_back(v) ; 
                bfs.push(v) ; 
            }
        } 
    } 
    
    for( int i=order.size()-1 ; i>=0 ; --i ){
        for( int c : children[order[i]] ){
            sz[ order[i] ] += sz[c] ; 
        }
    } 

    for( int i=order.size()-1; i>=0 ; --i ){
        int u = order[i] ; 
        dp[u][1] = vals[u] ; 
        int curr_sz = 1 ; 

        for( int c : children[u] ){
            for( int j = curr_sz ; j >= 1 ; --j ){
                if( dp[u][j] == LLONG_MIN ) continue ;
                for( int k=1 ; k<=sz[c] ; ++k ){
                    if( dp[c][k] == LLONG_MIN ) continue ; 
                    dp[u][j+k] = max( dp[u][j+k] , dp[u][j] + dp[c][k] ) ; 
                }
            }
            curr_sz += sz[c] ; 
        }
    }


    vector<ll> best( n+1 , LLONG_MIN ) ; 
    for( int i=1 ; i<=n ; ++i ){
        for( int j=1 ; j<=n ; ++j ){
            best[i] = max( best[i] , dp[j][i] ) ; 
        }
    }

    int k = log2(n) ; 
    vector<vector<ll>> sparse( n+1 , vector<ll>( k+1 ) ) ; 
    for( int i=1 ; i<=n ; ++i ){
        sparse[i][0] = best[i] ; 
    }

    for( int i=1 ; i<=k; ++i ){
        for( int j=1 ; j<=n ; ++j ){
            if( j + ( 1 << i ) - 1 <= n ){
                sparse[j][i] = max( sparse[j][i-1] , sparse[j+(1<<(i-1))][i-1] ) ; 
            }
        }
    }

    int q ; cin >> q ;
    while( q-- ){
        int l , r ; 
        cin >> l >> r ; 
        ll ans = get( sparse , l , r ) ; 
        cout << ans << '\n' ; 
    }
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}