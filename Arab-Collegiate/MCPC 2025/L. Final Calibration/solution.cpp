#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

struct BIT{
    vector<int> bit ; 
    int n ; 
    BIT( int len ){
        n = len ; 
        bit.assign( n , 0 ) ; 
    }
    int get( int idx ){
        int ans = 0 ; 
        while( idx < n ){
            ans += bit[idx] ; 
            idx += idx & -idx ; 
        }
        return ans ; 
    }
    void update( int idx ){
        while( idx > 0 ){
            bit[idx]++ ; 
            idx -= idx & -idx ; 
        }
    }
};

void solve(){
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
    }

    vector<pair<int,int>> m( n ) ; 
    for( int i=0 ; i<n ; ++i ){
        m[i] = { arr[i] , i } ; 
    }
    sort( all(m) ) ; 
    int curr = 1 ; 
    for( int i=0 ; i<n ; ++i ){
        arr[ m[i].second ] = curr ; 
        while( i+1<n && m[i+1].first == m[i].first ){
            i++ ; 
            arr[ m[i].second ] = curr ; 
        }
        curr++ ; 
    }


    ll ans = 0 ; 
    BIT bit( curr ) ; 
    for( int i=0 ; i<n ; ++i ){
        ans += bit.get( arr[i] + 1  ) ; 
        bit.update( arr[i] ) ; 
    }

    cout << ( ans % 2 == 0 ? ans : -1 ) << '\n'; 
     
}
int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}