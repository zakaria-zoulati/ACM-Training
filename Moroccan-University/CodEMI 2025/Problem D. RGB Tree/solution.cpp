#include <iostream> 
#include <vector> 

using namespace std ; 


typedef long long ll ; 


void dfs( int node , vector<vector<int>> &edges , vector<int> &ops , int prev ){
    ops[node] = ( ops[node] + prev ) % 3 ; 
    for( int i : edges[node] ){
         dfs( i , edges , ops , ops[node]  ) ;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n ; cin >> n  ; 
    vector<vector<int>> edges( n+1 ) ; 
    for( int i = 1 ; i<n ; ++i ){
        int pi ; cin >> pi ; 
        edges[pi].push_back( i+1 ) ;  
    }
    
    string s ; cin >> s ; 

    string RGB = "RGB" ; 
    
    vector<int> ops( n+1 ) ; 
    int q ; cin >> q ; 
    while( q-- ){
        int x ; cin >> x ; 
        ops[x] = ( ops[x] + 1 ) % 3 ; 
    }


    dfs( 1 , edges , ops , 0  ) ; 
    
    
    for( int i=1 ; i<=n ; ++i ){
        int in = 0 ; 
        while( s[i-1] != RGB[in] ) ++in ; 
        in = ( in + ops[i] ) % 3 ; 
        s[i-1] = RGB[in] ; 
    }
    
    cout << s << endl ; 
    
    return 0 ; 
}