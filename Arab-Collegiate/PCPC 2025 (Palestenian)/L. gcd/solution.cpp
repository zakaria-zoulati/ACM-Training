#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

int gcd(int a , int b){ 
    while( b != 0 ){
        int temp = a % b ; 
        a = b ; 
        b = temp ; 
    }
    return a; 
}

void solve(){
    int n ; cin >> n ; 
    vector<int> arr(n) ; 
    int g = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> arr[i] ; 
        g = gcd( g , arr[i] ) ; 
    }

    vector<int> pref(n) ; 
    pref[0] = arr[0] ; 
    for( int i=1 ; i<n ; ++i ){
        pref[i] = gcd( pref[i-1] , arr[i] ) ; 
    }

    vector<int> suff(n) ; 
    suff[n-1] = arr[n-1] ; 
    for( int i=n-2 ; i>=0 ; --i ){
        suff[i] = gcd( suff[i+1] , arr[i] ) ; 
    }


    int q ; cin >> q; 
    while( q-- ){
        int x ; cin >> x ; 
        if( n == 1 || g % x == 0 ){
            cout << "YES\n" ; 
        }else {
            if( arr[0] % x == 0 ){
                int l=0 ; 
                int r=n-1 ; 
                while( l < r ){
                    int mid = l + ( r-l+1 )/2 ; 
                    if( pref[mid] % x == 0 ){
                        l = mid ;
                    }else {
                        r = mid -1 ;
                    }
                }
                if( l == n-2 || suff[l+2] % x == 0 ){
                    cout << "YES\n" ; 
                }else {
                    cout << "NO\n" ; 
                }
            }else {
                cout << ( suff[1] % x == 0 ? "YES\n" : "NO\n" ) ; 
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}