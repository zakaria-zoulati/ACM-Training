#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n ; cin >> n ; 
    vector<ld> trees(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> trees[i] ; 
    }

    ld S = 0 ; 
    for( ld tree : trees ){
        S += tree ; 
    }

    int threshold = S/2 ; 

    bitset<500'001> dp(0) ; 
    dp[0] = 1 ; 

    sort( trees.begin() , trees.end() ) ; 

    for( int i=0 ; i<n-1 ; ++i ){
        dp |= ( dp << trees[i] ) ; 
    }

    int i=threshold ;
    while( !dp[i] ) i-- ;
    
    
    cout << ( i + trees[n-1] ) << '\n' ; 
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}