#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


int find( vector<int> &rep , int node ){
    if( rep[node] != node ){
        rep[node] = find( rep , rep[node] ) ; 
    }
    return rep[node] ; 
}

void unite( vector<int> &rep , int x , int y ) {
    int r1 = find( rep , x ) ; 
    int r2 = find( rep , y ) ; 
    if( r1 != r2 ){
        rep[r1] = r2 ; 
    }
}

int same( vector<int> &rep , int x , int y ){
    int r1 = find( rep , x ) ; 
    int r2 = find( rep , y ) ; 
    return r1 == r2 ; 
}

void solve(){
    int n ; cin >> n ; 
    int m ; cin >> m ; 
    int q ; cin >> q ; 


    map< int, vector< pair<int,int> >  > pairs ; 


    while( m-- ){
        int ui , vi ; 
        cin >> ui >> vi ; 
        pairs[ ui + vi ].push_back( {ui,vi} ) ; 
    }


    vector<int> rep( n+1 , 0 ) ; 
    for( int i=1 ; i<=n ; ++i ){
        rep[i] = i ; 
    }

    vector<int> components( 2*n + 1 , 0 ) ; 
    components[2*n] = n ; 

    for( int i=2*n-1 ; i>=0 ; --i ){
        components[i] = components[i+1] ; 
        for( auto &[u,v] : pairs[i+1] ){
            if( !same( rep , u , v )){
                components[i]-- ; 
            }
            unite( rep , u , v ) ; 
        }
    }

    while( q-- ){
        ll s ; cin >> s ; 
        if( s > 2*n ){
            cout << n << '\n' ;
        }else {
            cout << components[s] << '\n' ; 
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}