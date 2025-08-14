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
using ld = long double;

bool dfs( int node , vector<vector<int>> &edges , vector<int> &seen , int curr , vector<int> &count  ){
    seen[node] = curr ; 
    count[curr]++ ;
    for( int i : edges[node] ){
        if( seen[i] == -1 ){
            if( !dfs( i , edges , seen , 1 - curr , count ) ){
                return false ; 
            }
        }else if( seen[i] == curr ){
            return false ; 
        }
    }
    return true ; 
}

ll helper(const vector<ll> &els) {
    ll sum = 0;
    for (ll v : els) sum += v;
    bitset<4'001> dp; 
    dp[0] = 1;
    for (ll v : els) {
        dp |= (dp << v);
    }

    ll best = sum;
    for (ll s = 0; s <= sum; ++s) {
        if (dp[s]) {
            ll diff = abs((sum - s) - s);
            if (diff < best) best = diff;
        }
    }
    return best;
}

void solve(){
    int n ; cin >> n ; 
    int m ; cin >> m ; 
    vector<vector<int>> edges( n+1 ) ; 
    while( m-- ){
        int u , v ; 
        cin >> u >> v ; 
        edges[u].push_back( v );
        edges[v].push_back( u );
    }
    vector<int> seen( n+1 , -1 ) ;
    vector<ll> els; 
    for( int i=1 ; i<=n ; ++i ){
        if( seen[i] == -1 ){
            vector<int> curr( 2 , 0 ) ; 
            if( !dfs( i , edges , seen , 0 , curr ) ){
                cout << -1 << '\n' ; 
                return ; 
            }
            els.push_back( abs(curr[0] - curr[1]) ) ; 
        }
    }
    ll rs = helper( els ) ;
    
    cout << rs << '\n' ; 
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