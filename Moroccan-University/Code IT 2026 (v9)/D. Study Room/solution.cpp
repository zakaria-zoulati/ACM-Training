#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n , m , k ; 
    cin >> n >> m >> k ; 
    vector<int> diff( m + 2 , 0 ) ; 
    for( int i=0 ; i<n ; ++i ){
        int s , f ; 
        cin >> s >> f ;
        diff[s] += 1 ; 
        diff[f+1] -= 1 ; 
    }    
    for( int i=2 ; i<=m ; ++i ){
        diff[i] += diff[i-1];
    }
    ll curr = 0 ; 
    int start = 1 ; 
    for( int i=1; i<=k ; ++i ){
        curr += diff[i] ; 
    }
    ll best = curr ; 
    for( int i=k+1 ; i<=m ; ++i ){
        curr -= diff[i-k] ; 
        curr += diff[i] ; 
        if( curr < best ){
            best = curr ; 
            start = i-k+1  ;
        }
    }
    cout << start << " " << best << '\n' ; 
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}