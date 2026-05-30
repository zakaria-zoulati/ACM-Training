#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

const int MAXV = 2e7 + 1 ; 
int spf[MAXV] ; 


void sieve(){
    iota( spf , spf + MAXV , 0 ) ; 
    for( int i=2 ; (ll)i*i<MAXV ; ++i ){
        if( spf[i] == i ){
            for( int j=i*i ; j<MAXV ; j += i ){
                if( spf[j] == j ) spf[j] = i ; 
            }
        }
    }  
}


void solve(){
    int n ; cin >> n ; 
    ll p ; cin >> p ; 
    vector<int> h(n) ; 
    for( int i=0 ; i<n ; ++i ) {
        cin >> h[i] ; 
    }    
    sort( all(h) ) ; 
    int monsters = 0;   
    for( int i=0 ; i<n ; ++i ){
        if( h[i] <= p ){
            monsters++;
            int curr = spf[h[i]] ; 
            p += curr ; 
        }else {
            break ; 
        }
    }
    cout << monsters << " " << p << '\n' ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve() ;

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}