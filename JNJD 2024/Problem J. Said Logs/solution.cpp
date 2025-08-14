#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>
#include <utility>
#include <fstream>
#include <cmath>
#include <iomanip>


using namespace std;
using ll = long long;
using ld = long double;


void solve(){
    int n ; cin >> n ; 
    int rs = 0;
    int errors = 0 ; 
    for( int i=0 ; i<n ; ++i ){
        string s ; cin >> s ; 
        if( s == "ERROR" ){
            errors++ ; 
        }else if( s == "RESOLVED" ) {
            if( errors > 0 ){
                rs++ ; 
                errors-- ; 
            }
        }
    } 
    cout << rs << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1; 
    while (t--) {
        solve();
    }
    return 0;
}