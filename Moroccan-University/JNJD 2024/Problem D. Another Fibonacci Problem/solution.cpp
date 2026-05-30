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

int mod = 37 ; 
vector<int> vals ; 

void precompute() {
    int a = 0 , b = 1 , c = 1 ; 
    while( true ){
        vals.push_back(a) ; 
        int temp = b ; 
        a = b ; 
        b = c ; 
        c = ( c + temp ) % mod ; 
        if( b == 0 && c == 1 ) {
            vals.push_back(a) ; 
            break ; 
        }
    }
}


void solve(){
    string s ; cin >> s ; 
    int len = (int) vals.size() ; 
    int pos = 0 ; 
    for( char c : s ){
        pos = ( pos*10 + (c-'0') )%len ;
    }
    cout << vals[pos] << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute() ; 
    
    int t = 1; cin >> t ;
    while (t--) {
        solve();
    }
    return 0;
}