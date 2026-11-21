#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n , k;
    cin >> n >> k ; 
    
    vector<ll> a(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> a[i] ; 
    }


    ll count = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        count += a[i]/k ; 
        a[i] %= k ; 
    }
    
    sort( a.begin() , a.end() ) ; 
    count %= n ; 

    for( int i=0 ; i<count ; ++i ){
        a[i] += k ; 
    }

    sort( a.begin() , a.end() ) ; 

    cout << a[n-1] - a[0] << '\n' ; 
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}