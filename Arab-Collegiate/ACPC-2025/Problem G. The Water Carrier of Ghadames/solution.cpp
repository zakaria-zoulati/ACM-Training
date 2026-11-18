#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1000; 
const ll mod = 1e9 + 7;

ll dp[N+1][N+1] ; 
ll pw[2*N+1] ; 

void precompute(){
    dp[0][0] = 1 ;
    for( int i=1 ; i<=N ; ++i ){
        dp[0][i] = 1 ; 
        dp[i][0] = 1 ; 
    }

    for( int i=1 ; i<=N ; ++i ){
        for( int j=1 ; j<=N ; ++j ){
            dp[i][j] = ( dp[i][j-1] + dp[i-1][j] ) % mod; 
        }
    }

    pw[0] = 1 ; 
    for( int i=1 ; i<=2*N ; ++i ){
        pw[i] = ( pw[i-1] * 2 ) % mod;
    }
}

void solve(){
    ll a , b ; 
    cin >> a >> b ; 

    if( a==0 && b==0 ){
        cout << "0\n" ; 
        return ; 
    }
    
    ll n = a + b ; 
    ll ans = ( dp[a][b] * pw[n-1] ) % mod ;  

    cout << ans << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    precompute() ; 

    int t ; cin >> t ; 
    while(t--){
        solve();
    }
    return 0;
}