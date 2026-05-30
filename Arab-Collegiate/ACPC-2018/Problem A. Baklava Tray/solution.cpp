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
    int n; 
    cin >> n;
    ld PI = acos( -1.0 ) ; 
    ld rs = 10000;
    ld angle = PI / n;
    ld x = cos(angle);
    ld y = sin(angle);
    
    ld xx = 1L - x*x ;
    
    ld p = 1.0/( xx * xx ) ; 
    
    p *= y * y;
    rs *= p;
    
    cout << fixed << setprecision(5) << rs << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("baklava.in", "r", stdin);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}