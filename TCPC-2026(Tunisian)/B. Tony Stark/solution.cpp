#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

const double pi = acos(-1) ; 
const double toRad = pi/180.0 ; 

void solve(){
    double a , b , c ; 
    cin >> a >> b >> c ; 
    double k ; cin >> k ; 

    double coeff = ( pi - 2*sin(a*toRad)*sin(b*toRad)*sin(c*toRad) ) ; 
    double ans = sqrt( k / coeff ) ; 

    cout << fixed << setprecision( 4 ) << ans << '\n'; 
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}