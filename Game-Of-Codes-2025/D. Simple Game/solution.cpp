#include <bits/stdc++.h>
#define all(x) begin(x) , end(x)

using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n , m ; 
    cin >> n >> m ; 
    if( m % 2 == 0 || n % 2 == 0 ){
        cout << "Anas\n" ; 
    }else {
        cout << "Zakariaa\n" ; 
    }
}

int main() {
    int t = 1;
    cin >> t ; 
    while(t--){
        solve();
    }
    return 0;
}