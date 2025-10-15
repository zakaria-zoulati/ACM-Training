#include <bits/stdc++.h>
#define all(x) begin(x), end(x)


using namespace std;
using ll = long long;
using ld = long double ; 

const ld L_MAX = 1e7 ; 
const ld L_MIN = -1e7 ; 

bool inter( pair<ld,ld> &curr , ll t1 , ll t2 , ll i ){
    ld v1 = (ld) i/t2 ; 
    ld v2 =  ( t1 == 0 ? L_MAX : (ld) i/t1 ) ; 
    if( v1 > curr.second ) return false ;
    if( v2 < curr.first ) return false ; 
    curr.first = max( curr.first , v1 ) ;
    curr.second = min( curr.second , v2 ) ; 
    return true ; 
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for( int tc = 1 ; tc<=t ; tc++ ){
        int n ; cin >> n ; 
        pair<ld,ld> curr = { L_MIN , L_MAX } ; 
        bool ans = true ; 
        for( int i=0 ; i<n ; ++i ){
            ld t1 , t2 ; 
            cin >> t1 >> t2 ; 
            if( ans ){
                if( !inter( curr , t1 , t2 , i+1 ) ){
                    ans = false ; 
                }
            }
        }
        cout << "Case #" << tc << ":" << ( ans ? curr.first : -1 ) << '\n' ; 
    }
    return 0;
}
