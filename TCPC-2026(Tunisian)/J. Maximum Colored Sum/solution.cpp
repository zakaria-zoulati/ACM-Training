#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n , k , m ; 
    cin >> n >> k >> m ; 
    
    vector<pair<int,int>> items ; 

    for( int i=0 ; i<n ; ++i ){
        int pi ; cin >> pi ; 
        int ci ; cin >> ci ; 
        items.push_back(  {pi,ci} ) ; 
    }

    sort( all(items) ) ; 

    vector<int> count( n+1 , 0 ) ; 
    int curr = 0 ; 
    ll ans = 0 ; 
    for( int i=n-1 ; i>=0 ; --i ){
        if( count[ items[i].second ] < m && curr < k ){
            ans += items[i].first ; 
            count[ items[i].second ]++ ; 
            curr++ ; 
        }
    }


    if( curr == k ){
        cout << ans << '\n' ; 
    }else {
        cout << "-1\n" ; 
    }
    
}


int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}