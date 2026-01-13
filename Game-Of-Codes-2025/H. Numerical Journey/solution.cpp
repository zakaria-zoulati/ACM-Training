#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

class UnionFind {
    public :
        map<int,int> parent ; 

        int find( int i ){
            if( !parent.count(i) ){
                parent[i] = i ; 
            }
            if( parent[i] == i ) return i ; 
            return parent[i] = find( parent[i] ) ; 
        }

        void unite( int i , int j ){
            int pi = find(i) , pj = find(j) ; 
            if( pi == pj ) return ; 
            if( pi < pj ){
                parent[pj] = pi ; 
            }else {
                parent[pi] = pj ; 
            }
        }

        bool same( int i , int j ){
            return find(i) == find(j) ; 
        }
}; 

vector<int> preprocess( int n ){
    vector<int> divisor( n + 1 , 1 ) ; 
    for( int i=2 ; i<= n ; ++i ){
        if( divisor[i] == 1 ){
            for( int j=i ; j<=n ; j += i ){
                divisor[j] = i ; 
            }
        }
    }
    return divisor ; 
}

void solve(){
    vector<int> divisor = preprocess( 1e6 ) ; 
    
    int n ; cin >> n ; 

    UnionFind dsu ; 

    for( int i=0 ; i<n ; ++i ){
        int num ; cin >> num ; 
        if( num == 1 ){
            cout << "no\n" ; 
            return ; 
        }
        int last = divisor[num] ; 
        while( num != 1 ){
            dsu.unite( last , divisor[num] ) ; 
            num /= divisor[num] ; 
        }
    }

    set<int> roots ; 

    for( auto [a,_] : dsu.parent ){
        roots.insert( dsu.find( a ) ) ; 
    }

    cout << ( roots.size() == 1 ? "yes" : "no" ) << '\n' ; 

}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}