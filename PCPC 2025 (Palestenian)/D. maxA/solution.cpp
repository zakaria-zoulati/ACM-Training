#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

void solve(){
    int n , m ;
    cin >> n >> m ; 
    int th ; cin >> th ;  
    
    vvi grid( n+1 , vi(m+1) ) ; 

    for( int i=1 ; i<=n ; ++i ){
        for( int j=1 ; j<=m ; ++j ){
            cin >> grid[i][j] ; 
        } 
    }

    vvi pref( n+1 , vi(m+1,0) ) ; 
    
    for( int i=1 ; i<=n ; ++i ){
        for( int j=1 ; j<=m ; ++j ){
            pref[i][j] = pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1] + ( grid[i][j] > th ? 1 : 0 ) ; 
        }
    }

    int ans = 0 ;

    for( int i=1 ; i<=n ; ++i ){
        for( int j=1 ; j<=m ; ++j ){
            for( int k=1 ; k<=min( i,j ) ; ++k ){
                int len = k*k ; 
                int curr = pref[i][j] - ( pref[i][j-k] + pref[i-k][j] - pref[i-k][j-k] ) ;  
                if( curr <= len / 2 ){
                    ans = max( ans , k*k ) ; 
                }
            }
        }
    }

    cout << ans << '\n' ; 
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}