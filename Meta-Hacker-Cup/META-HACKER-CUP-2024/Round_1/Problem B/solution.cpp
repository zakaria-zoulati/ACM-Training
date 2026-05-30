#include <bits/stdc++.h>
#define all(x) begin(x), end(x)


using namespace std;
using ll = long long;
using ld = long double ; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // precomp 
    int len  = 10'000'001 ; 
    vector<bool> isPrime( len , true ) ;
    isPrime[0] = false ;  
    isPrime[1] = false ;  
    for( int i=2 ; i*i<len ; ++i ){
        if( isPrime[i] ){
            for( int j=i*i ; j<len ; j += i ){
                isPrime[j] = false ; 
            }
        }
    }
    vector<ll> pref( len , 0 ) ; 
    pref[5] = 2 ; 
    for( int i=6 ; i<len ; ++i ){
        pref[i] = pref[i-1] ; 
        if( isPrime[i] && isPrime[i-2] ){
            pref[i]++ ; 
        }
    }


    int t = 1;
    cin >> t;
    for( int tc = 1 ; tc<=t ; tc++ ){
        ll n ; cin >> n ; 
        cout << "Case #" << tc << ":" << pref[n] << '\n' ; 
    }
    return 0;
}
