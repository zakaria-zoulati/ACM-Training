#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

bool possible( vector<pair<ll,ll>> &hanout , map<ll,ll> &prs , int n , int m ,int k ){
    int valid = 0 ;
    map<ll,ll> curr ;  
    for( int i=0 ; i<k ; ++i ){
        if( prs.find( hanout[i].first ) != prs.end() ){
            bool good = false ; 
            if( curr[ hanout[i].first ] >= prs[ hanout[i].first ] ){
                good = true ;  
            }
            curr[ hanout[i].first ] += hanout[i].second ; 
            if( !good && curr[ hanout[i].first ] >= prs[ hanout[i].first ] ){
                valid++ ;   
            }
        }
    }
    if( valid == m ) return true ; 
    for( int i=k ; i<n ; ++i ){
        if( prs.find( hanout[i].first ) != prs.end() ){
            bool good = false ; 
            if( curr[ hanout[i].first ] >= prs[ hanout[i].first ] ){
                good = true ;  
            }
            curr[ hanout[i].first ] += hanout[i].second ; 
            if( !good && curr[ hanout[i].first ] >= prs[ hanout[i].first ] ){
                valid++ ;   
            }
        }
        if( prs.find( hanout[i-k].first ) != prs.end() ){
            bool good = false ; 
            if( curr[ hanout[i-k].first ] >= prs[ hanout[i-k].first ] ){
                good = true ;  
            }
            curr[ hanout[i-k].first ] -= hanout[i-k].second ; 
            if( good && curr[ hanout[i-k].first ] < prs[ hanout[i-k].first ] ){
                valid-- ;  
            }
        }
        if( valid == m ) return true ; 
    }
    return false ; 
}

void solve(){
    int n , m ; 
    cin >> n >> m ;     
    vector<pair<ll,ll>> hanout(n) ; 
    for( int i=0 ; i<n ; ++i ){
        int s , o ; 
        cin >> s >> o ; 
        hanout[i] = { s , o } ; 
    }
    map<ll,ll> prs ; 
    for( int i=0 ; i<m ; ++i ){
        ll s , t ; 
        cin >> s >> t ; 
        prs[s] = t ; 
    }
    if( !possible( hanout , prs , n , m , n ) ){
        cout << -1 << '\n' ; 
        return ; 
    }
    int l = 1 ; 
    int r = n ; 
    while( l < r ){
        int mid = l + ( r - l )/2 ; 
        if( possible( hanout , prs, n , m , mid ) ){
            r = mid ; 
        } else {
            l = mid + 1; 
        }
    }
    cout << l << '\n' ; 
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