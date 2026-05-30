#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;
using ll = long long;

struct Coffee {
    vector<int> prices; 
    Coffee(){
        prices.assign( 3 , 0 ) ; 
    }
};

void solve() {
    int n ; cin >> n ; 
    int p ; cin >> p ; 
    map<string,int> map1 ; 
    map1["small"] = 0 ;
    map1["medium"] = 1 ;
    map1["large"] = 2 ;
    map<string , Coffee > m ;
    for( int i=0 ; i<n ; ++i ){
        string name ; cin >> name ; 
        cin >> m[name].prices[0] >> m[name].prices[1] >> m[name].prices[2] ; 
    } 
    for( int i=0 ; i<p ; ++i ){
        string name ; cin >> name ; 
        string ty ; cin >> ty ; 
        string c ; cin >> c ; 
        int rs = m[c].prices[ map1[ty] ] + ( 100/p ) ;
        if( rs % 5 == 1 ){
            rs-- ; 
        }else if( rs % 5 == 4 ){
            rs++ ; 
        }
        cout << name << " " << rs << "\n" ; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("coffee.in", "r", stdin);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}