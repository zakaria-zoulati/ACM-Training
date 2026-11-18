#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


void solve(){
    int a , b , x ; 
    cin >> a >> b >> x ; 
    
    int needed = ( b / x )*( x + 1 ) + ( b % x == 0 ? 0  :( b % x )+ 1 ) ; 

    cout << ( needed <= a ? "YES\n" : "NO\n" ); 
}

int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}