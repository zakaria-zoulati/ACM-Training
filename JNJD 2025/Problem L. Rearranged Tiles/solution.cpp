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
    string s ; cin >> s ; 
    int n = s.size() ; 
    vector<int> f(26,0) ; 
    for( char c : s ){
        f[ c-'a' ]++ ; 
    }
    for( int i : f ){
        if( i > (n+1)/2 ){
            cout << "NO" << '\n' ; 
            return ; 
        }
    }
    cout << "YES" << '\n' ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}