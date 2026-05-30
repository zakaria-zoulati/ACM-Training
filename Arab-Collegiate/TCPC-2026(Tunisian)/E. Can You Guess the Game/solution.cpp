#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


void solve(){
    ll n ; cin >> n ; 
    ll x ; cin >> x ; 
    ll y ; cin >> y ; 
    
    for( int i=0 ; i<=n ; ++i ){
        if( 3*i > x ) break ; 
        ll rem = x - 3*i ; 
        if( rem > y ) continue ; 
        ll otherPlayer = y - rem ; 
        if( otherPlayer % 3 != 0 ){
            continue ; 
        }
        ll plays = rem + i + otherPlayer/3 ; 
        if( plays == n ){
            string player1( n , 'D' ) ; 
            string player2( n , 'D' ) ;

            for( int j=n-1 ; j>=n-i ; --j ){
                player1[j] = 'W' ; 
                player2[j] = 'L' ; 
            }
            for( int j=n-i-1 ; j>n-i-1-otherPlayer/3 ; --j ){
                player2[j] = 'W' ; 
                player1[j] = 'L' ; 
            }

            cout << player1 + player2 << '\n' ;  
            return ; 
        }
    }


    cout << "-1\n" ; 
}


int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}