#include <bits/stdc++.h>
#define all(x) begin(x), end(x)

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n ; cin >> n ; 
        ll a ; cin >> a; 
        ll b ; cin >> b ; 


        cout << "Case #" << tc << ": "  ; 

        for( int i=0 ; i<n ; ++i ){
            cout << 1 << " "  ; 
        }
        for( int i=1 ; i<n ; ++i ){
            cout << 1 << " " ; 
        }
        cout << b << '\n' ; 

    }

    return 0;
}
