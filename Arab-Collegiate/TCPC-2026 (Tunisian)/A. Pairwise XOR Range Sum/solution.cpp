#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


void solve(){
    int n ; cin >> n ; 
    vector<int> arr(n+1) ; 
    for( int i=1 ; i<=n ; ++i ){
        cin >> arr[i] ; 
    }

    vector<vector<int>> dp( n+1 , vector<int>( 32 , 0 ) ) ; 
    for( int i=1 ; i<=n ; ++i ){
        for( int j=0 ; j<32 ; ++j ){
            dp[i][j] = dp[i-1][j] ; 
            if( ( (arr[i] >> j) & 1 ) == 1 ){
                dp[i][j] += 1 ; 
            }
        }
    }

    int q ; cin >> q ; 
    while( q-- ){
        int l , r ; 
        cin >> l >> r ;
        int len = r - l + 1; 

        ll ans = 0 ; 
        for( int i=0 ; i<32 ; ++i ){
            int curr = dp[r][i] - dp[l-1][i] ; 
            ans += ( len - curr )*curr*( 1LL << i ) ; 
        }
        cout << ans << '\n' ; 

    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}