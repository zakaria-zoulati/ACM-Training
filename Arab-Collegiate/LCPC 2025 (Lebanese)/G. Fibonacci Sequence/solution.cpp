#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n ; cin >> n ; 
    if( n <= 2 ){
        cout << 0 << '\n' ;
        return ; 
    }
    cout << n-1 << '\n' ; 
    string ans( n+1 , '-' ) ;    
    for( int i=2 ; i<=n ; ++i ){
        if( i == n ){
            ans[i] = 'B' ; 
        }else if( i % 2 == 0 ){
            ans[i] = 'F' ; 
        }else {
            ans[i] = 'B' ; 
        }
    }
    cout << ans.substr(2,n-1) << '\n' ; 
}


int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}