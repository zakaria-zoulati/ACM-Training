#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

ll mod = 1e9 + 7 ; 

void solve(){
    int n , k ; 
    cin >> n >> k ; 
    vector<vector<int>> dp( n+1 , vector<int>(k+1) ) ; 

    for( int i=1 ; i<=k ; ++i ){
        dp[n][i] = 1 ; 
    }

    for( int i=n-1 ; i>=1 ; --i ){
        for( int j=1 ; j<=k ; ++j ){
            dp[i][j] = 0 ; 
            for( int t=j ; t<=k ; t += j ){
                dp[i][j] = ( dp[i][j] + dp[i+1][t] ) % mod ; 
            }
        }
    }

    ll ans = 0 ; 
    for( int i=1 ; i<=k ; ++i ){
        ans = ( ans + dp[1][i] ) % mod ; 
    }
    cout << ans << '\n' ; 
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}