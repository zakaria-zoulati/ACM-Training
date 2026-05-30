#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;


void solve(){
    ld x , y ; 
    cin >> x >> y ; 
    ld z3 = y*y/sqrt( x*x + y*y ) ; 
    ld z2 = sqrt( y*y - z3*z3 ) ; 
    ld z1 = sqrt( x*x - z2*z2 ) ; 


    vector<ld> areas ; 
    areas.push_back( z1*z2/2 ) ; 
    areas.push_back( x*y/2 ) ; 
    areas.push_back( z3*z2/2 ) ; 

    sort( all( areas ) ) ; 

    for(  ld area : areas ){
        cout << fixed << setprecision(4) << area << " " ; 
    }
    cout << '\n' ; 
}
int main() {
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}