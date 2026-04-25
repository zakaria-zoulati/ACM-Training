#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int k , n ; 
    cin >> n >> k ; 
    vector<vector<int>> edges(n+1) ; 
    for( int i=1; i<=n ; ++i ){
       int l ; cin >> l ;
       while( l-- ){
            int node ; cin >> node ; 
            edges[node].push_back(i) ;
       }
    }    
    for( int i=1 ; i<=n ; ++i ){
        int curr = 1 ;
        vector<bool> seen(n+1,false) ; 
        queue<int> q ; 
        q.push(i) ; 
        seen[i] = true ;   
        while( !q.empty() ){
            int node = q.front() ; q.pop() ; 
            for( int v : edges[node] ){
                if( !seen[v] ){
                    curr++ ; 
                    seen[v] = true ; 
                    q.push(v) ; 
                }
            }
        }
        cout << ( curr > k ? 1 : 0 ) << '\n' ; 
    }
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}