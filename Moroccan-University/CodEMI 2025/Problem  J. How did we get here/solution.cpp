#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>
#include <utility>
#include <fstream>
#include <bitset>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;


void solve(){
        ll a,b ; 
        cin >> a >> b ;
        ll rs = (b*(b+1)/2) - (a*(a-1)/2) ; 
        cout << rs << '\n' ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1; cin >> t ; 
    while (t--) {
        solve();
    }
    return 0;
}