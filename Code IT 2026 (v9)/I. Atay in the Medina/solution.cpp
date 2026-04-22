#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }
    sort( all(arr) ) ; 
    ll ans = 0;  
    for( int i=0 ; i<n ; ++i ){
        ans += abs( arr[i] - arr[n/2] ) ; 
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