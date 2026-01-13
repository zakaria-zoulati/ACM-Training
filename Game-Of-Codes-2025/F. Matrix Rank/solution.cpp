#include <bits/stdc++.h>

#define all(x) begin(x) , end(x)
#define pb push_back 


using namespace std;
using ll = long long;
using ld = long double;


using vi = vector<int> ; 
using vvi = vector<vi> ; 

vi normalize( vi &arr ){
    int curr = 0 ; 
    for( int num : arr ){
        curr = gcd( curr , num ) ;
    }
    vi result ; 
    for( int num : arr ){
        result.pb( num / curr ) ; 
    }
    return result ; 
}

int get_rank( vvi &matrix ){
    set<vi> unique_rows ; 
    for( auto &row : matrix ){
        unique_rows.insert( normalize(row) ) ;   
    }
    return unique_rows.size() ; 
}

void solve(){
    int n , m ; 
    cin >> n >> m ;   
    
    vvi grid( n , vi(m) ) ; 
    for( int i=0 ; i<n ; ++i ){
        for( int j=0 ; j<m ; ++j ){
            cin >> grid[i][j] ; 
        }
    }

    vvi transpose( m , vi(n) ) ; 
    for( int i=0 ; i<n ; ++i ){
        for( int j=0 ; j<m ; ++j ){
            transpose[j][i] = grid[i][j] ; 
        }
    }

    cout << min( get_rank( grid ) , get_rank( transpose ) ) << '\n' ; 
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}