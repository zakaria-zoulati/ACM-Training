#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

bool dfs( string &s , vector<string> &parts , vector<bool> &seen , int n , int k , int index , int count ){
    if( count == k ) return true ; 
    if( index >= n ) return false ; 
    for( int i=0 ; i<k ; ++i ){
        if( !seen[i] ){
            seen[i] = true ; 
            for( int j=index ; j+parts[i].size() <= n ; ++j ){
                if( s.substr( j , parts[i].size() ) == parts[i] ){
                    if( dfs( s , parts , seen , n , k , index+parts[i].size() , count+1 ) ){
                        return true ; 
                    }
                    break ; 
                }
            }
            seen[i] = false ; 
        }
    }
    return false ;
}

void solve(){
    int n ; cin >> n ; 
    int k ; cin >> k ; 


    string s ; cin >> s; 
    vector<string> parts( k ) ;
    int len = 0 ; 
    for( int i=0 ; i<k ; ++i ){
        cin >> parts[i] ; 
        len += parts[i].size() ; 
    } 

    if( len > n ){
        cout << "NO\n" ; 
    }else {
        vector<bool> seen( k , false ) ; 
        if( dfs( s , parts , seen, n, k , 0 , 0 ) ) {
            cout << "YES\n" ; 
        } else {
            cout << "NO\n" ;
        }
    }
}

int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}