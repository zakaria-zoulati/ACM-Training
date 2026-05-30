#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

int gcd( int a , int b ){
    while( b != 0 ){
        int temp = a % b ; 
        a = b ; 
        b = temp ; 
    }
    return a; 
}

void solve(){
    int n , m , k ; 
    cin >> n >> m >> k ; 
    vector<int> T(n) ; 
    for( int i=0 ; i<n ; ++i ){
        cin >> T[i] ; 
    }
    vector<vector<int>> edges(n) ; 
    for( int i=0 ; i<m ; ++i ){
        int a , b ; 
        cin >> a >> b ; 
        a-- ; b-- ; 
        edges[a].push_back(b) ;
        edges[b].push_back(a) ;  
    }

    vector<int> signs( n , 0 ) ; 
    queue<pair<int,int>> q ;
    q.push( { 0 , 1 } ) ; 
    signs[0] = 1 ; 
    while( !q.empty() ){
        auto [ node , s ] = q.front() ; q.pop() ; 
        for( int v : edges[node] ){
            if( signs[v] == 0 ){
                signs[v] = -signs[node] ; 
                q.push( {v,signs[v]} ) ; 
            }else if( signs[v] == signs[node] ){
                cout << "JAM\n" ; 
                return ;  
            }
        }
    }

    while( k-- ){
        int a , b ; 
        cin >> a >> b ; 
        a-- ; b-- ; 

        int t1 = T[a] ; 
        int t2 = T[b] ;
        int g = gcd( t1 , t2 ) ; 
        t1 /= g  ;
        t2 /= g ; 
        int s = signs[a] * signs[b] ; 

        cout << s*t2 << "/" << t1 << '\n' ; 
    }
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