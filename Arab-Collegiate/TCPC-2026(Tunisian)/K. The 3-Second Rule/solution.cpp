#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int x , y ; 
    cin >> x >> y ; 
    
    int ans = ( x == 3 ? 0 : x ) + ( y == 3 ? 0 : y ) ;   
    cout << ans << '\n' ; 
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}